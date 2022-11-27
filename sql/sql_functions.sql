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
select card_property.card_type, owner.fname, owner.lname, account.balance, account.credit_limit, card_property.account_id, owner.id_ownerget_card_info
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
DELIMITER ;get_account_owner_info