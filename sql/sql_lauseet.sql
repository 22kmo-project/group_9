/*Owner data*/

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

INSERT INTO card (pin)
VALUES ("1234");
INSERT INTO card (pin)
VALUES ("1564");
INSERT INTO card (pin)
VALUES ("4824");
select * from card;

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



