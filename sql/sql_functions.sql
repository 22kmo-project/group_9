#create_card
DELIMITER //
CREATE PROCEDURE create_card(IN _pin varchar(255), IN owner_id INT,IN account_id INT, IN card_type varchar(6))
  BEGIN
INSERT INTO card (pin, owner_id)
VALUES (_pin, owner_id);
insert into card_property (card_type, card_id, account_id)
values(card_type, 
/*(select id_card from card where card.pin = _pin),*/
(SELECT MAX(id_card)
FROM card),
account_id);
  END //
DELIMITER ;

#get_card_info
DELIMITER //
CREATE PROCEDURE get_card_info(IN _card_id INT)
  BEGIN
select card_property.card_type, owner.fname, owner.lname, account.balance, account.credit_limit, card_property.account_id, owner.id_owner, account.balance, account.credit_limit,
owner_property.owner_type, owner.fname, owner.lname, owner.address,
 owner.phone
 from
 card
 JOIN card_property
  ON card_property.card_id=card.id_card
   JOIN owner
  ON owner.id_owner=card.owner_id
   JOIN account
  ON card_property.account_id=account.id_account
     where id_card = _card_id;
  END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE get_all_card_info()
  BEGIN
select id_card, card_property.card_type, owner.fname, owner.lname, account.balance, account.credit_limit, card_property.account_id, owner.id_owner
 from
 card
 JOIN card_property
  ON card_property.card_id=card.id_card
   JOIN owner
  ON owner.id_owner=card.owner_id
   JOIN account
  ON card_property.account_id=account.id_account;
  END //
DELIMITER ;


DELIMITER //
CREATE PROCEDURE get_card_by_account(IN _account_id int)
  BEGIN
select id_account, card_property.id_card_property, card_property.card_type, card_property.card_id, card.owner_id, owner.fname, owner.lname
 from
 account
 JOIN card_property
  ON card_property.account_id=id_account
   JOIN card
  ON card_property.card_id=card.id_card
    JOIN owner
  ON card.owner_id=owner.id_owner
  where id_account=_account_id;
  END //
DELIMITER ;


#Owner
#get_account_owner_info
DELIMITER //
CREATE PROCEDURE get_account_owner_info(IN _id_account INT)
  BEGIN
select owner_property.owner_type, owner.fname, owner.lname
 from
 account
 JOIN owner_property
  ON account.id_account=owner_property.account_id
   JOIN owner
  ON owner.id_owner=owner_property.owner_id
     where id_account = _id_account;
  END //
DELIMITER ;
#get_account_info
DELIMITER //
CREATE PROCEDURE get_account_info(IN _id_account INT)
  BEGIN
select owner_property.owner_type, owner.fname, owner.lname, owner.address, owner.phone, account.balance, account.credit_limit
 from
 account
 JOIN owner_property
  ON account.id_account=owner_property.account_id
   JOIN owner
  ON owner.id_owner=owner_property.owner_id
     where id_account = _id_account;
  END //
DELIMITER ;

#get_owner_accounts_info
DELIMITER //
CREATE PROCEDURE get_owner_accounts_info(IN _id_owner INT)
  BEGIN
select owner_property.owner_type, account.id_account, account.balance, account.credit_limit
 from
 account
 JOIN owner_property
  ON account.id_account=owner_property.account_id
   JOIN owner
  ON owner.id_owner=owner_property.owner_id
     where id_account = 2;
  END //
DELIMITER ;


#create_owner
DELIMITER //
CREATE PROCEDURE create_owner(IN _fname varchar(45), IN _lname varchar(45),IN _address varchar(45),IN _phone varchar(45),IN _owner_type varchar(5),IN _account_id INT)
  BEGIN
INSERT INTO owner (fname, lname, phone, address)
VALUES (_fname,_lname,_phone,_address);
INSERT INTO owner_property (owner_type,owner_id,account_id)
VALUES (_owner_type,
/*(select id_owner from owner where id is newest),*/
(SELECT MAX(id_owner)
FROM owner),
_account_id);
  END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE create_account( IN _credit_limit DOUBLE, IN _balance DOUBLE)
  BEGIN
INSERT INTO account (credit_limit, balance)
VALUES (_credit_limit, _balance);
  END //
DELIMITER ;

#create_account
DELIMITER //
CREATE PROCEDURE create_owner_property(IN _id_owner INT, IN _account_id INT, IN _owner_type varchar(5))
  BEGIN
insert into owner_property (account_id, owner_id, owner_type)
values(_account_id, _id_owner, _owner_type);
  END //
DELIMITER ;

#get_account_balance_info
DELIMITER //
CREATE PROCEDURE get_account_balance_info(IN _id_account INT, _id_card INT)
  BEGIN
select account.balance, account.credit_limit, card_property.card_type
 from
 account
 JOIN card_property
  ON account.id_account=card_property.account_id
 WHERE card_property.card_id = _id_card AND account.id_account = _id_account;
  END //
DELIMITER ;

     #update_account_balance
DELIMITER //
CREATE PROCEDURE update_account_balance(IN _id_account INT, _balance DOUBLE)
  BEGIN
update account
set balance = _balance
where id_account = _id_account;
  END //
DELIMITER ;

     #delete_account_and_foreign_keys
DELIMITER //
CREATE PROCEDURE delete_account_and_foreign_keys(IN _id_account INT)
  BEGIN
update card_property
set account_id = null
where account_id = _id_account;
update owner_property
set account_id = null
where account_id = _id_account;
update event
set account_id = null
where account_id = _id_account;
delete from account
where id_account = _id_account;
  END //
DELIMITER ;

     #delete_owner_and_foreign_keys
DELIMITER //
CREATE PROCEDURE delete_owner_and_foreign_keys(IN _id_owner INT)
  BEGIN
update owner_property
set owner_id = null
where owner_id = _id_owner;
update card
set owner_id = null
where owner_id = _id_owner;
delete from owner
where id_owner = _id_owner;
  END //
DELIMITER ;

     #delete_card_and_foreign_keys
DELIMITER //
CREATE PROCEDURE delete_card_and_foreign_keys(IN _id_card INT)
  BEGIN
update card_property
set card_id = null
where card_id = _id_card;
delete from card
where id_card = _id_card;
  END //
DELIMITER ;

     #add_account_owner_card_properties
DELIMITER //
CREATE PROCEDURE create_card(IN _pin varchar(255), IN owner_id INT,IN account_id INT, IN card_type varchar(6))
  BEGIN
INSERT INTO card (pin, owner_id)
VALUES (_pin, owner_id);
insert into card_property (card_type, card_id, account_id)
values(card_type, 
/*(select id_card from card where card.pin = _pin),*/
(SELECT MAX(id_card)
FROM card),
account_id);
  END //
DELIMITER ;

