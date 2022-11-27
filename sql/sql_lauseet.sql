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
