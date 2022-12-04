/*Owner data*/

CREATE USER 'group_9'@'localhost'
 IDENTIFIED WITH mysql_native_password BY 'netpass';
 
GRANT ALL ON banksimul_db TO 'group_9'@'localhost';
FLUSH PRIVILEGES;

INSERT INTO owner (fname, lname, address, phone)
VALUES ("Pekka", "Merivalo", "Esimerkkitie 2", "+35844231512345");

INSERT INTO owner (fname, lname, address, phone)
VALUES ("Liisa", "Merivalo", "Esimerkkitie 2", "+35844231512346");

INSERT INTO owner (fname, lname, address, phone)
VALUES ("Juha", "Wayne", "Jokutie 3", "+35844231512sd5");

select * from owner;

/*account data*/

INSERT INTO account (balance, credit_limit)
VALUES (2500, 3000);

INSERT INTO account (balance, credit_limit)
VALUES (2500, 0);

select * from account;


/*owner_property data*/

INSERT INTO owner_property (owner_type, owner_id, account_id)
VALUES ("owner", 1, 1);

INSERT INTO owner_property (owner_type, owner_id, account_id)
VALUES ("user", 2, 1);


INSERT INTO owner_property (owner_type, owner_id, account_id)
VALUES ("owner", 3, 2);

select * from owner_property;

/*card data*/

/*
INSERT INTO card (pin)
VALUES ("1234");
INSERT INTO card (pin)
VALUES ("1564");
INSERT INTO card (pin)
VALUES ("4824");
select * from card;*/

/*card_property data*/
INSERT INTO card_property (card_type, card_id, account_id)
VALUES ("credit", 1, 1);
INSERT INTO card_property (card_type, card_id, account_id)
VALUES ("credit", 2, 1);
INSERT INTO card_property (card_type, card_id, account_id)
VALUES ("credit", 3, 2);
select * from card_property;

select * from account;

/* to delete with forgeinkey
SET FOREIGN_KEY_CHECKS=0;
to close delte
SET FOREIGN_KEY_CHECKS=1;

delete from card_property where id_card_property = 2;
*/

select owner_type, fname, lname
from owner_property inner join owner on owner_property.owner_id=owner.id_owner;

SELECT
  owner.fname,
  owner.lname,
  owner_property.owner_type,
  account.balance
FROM owner_property
JOIN owner
  ON owner_property.owner_id=owner.id_owner
JOIN account
  ON owner_property.account_id = account.id_account;


create database banksimul_db;


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

call create_card("1234",1,1,"credit");

select * from owner;

select *from card;
select *from card_property;


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
get_owner_accounts_info

call create_owner("Old", "boy", "Nigga Gaa","265564561")
#create_owner
DELIMITER //
CREATE PROCEDURE create_owner(IN _fname varchar(45), IN _lname varchar(45),IN _address varchar(45),IN _phone varchar(45))
  BEGIN
INSERT INTO owner (fname, lname, phone, address)
VALUES (_fname,_lname,_phone,_address);
  END //
DELIMITER ;

#create_account
DELIMITER //
CREATE PROCEDURE create_account(IN _id_owner INT, IN _credit_limit DOUBLE, IN _owner_type varchar(5))
  BEGIN
INSERT INTO account (credit_limit)
VALUES (666);
insert into owner_property (account_id, owner_id, owner_type)
values(
/*(select newest account with  highest id),*/
(SELECT MAX(id_account)
FROM account),
_id_owner, _owner_type);
  END //
DELIMITER ;



