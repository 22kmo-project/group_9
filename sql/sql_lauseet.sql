/*Owner data*/
/*CREATE user 'group_9'@'localhost'
 IDENTIFIED WITH mysql_native_password BY 'netpass';*/
 
GRANT ALL on banksimul_db.* to 'group_9'@'localhost';

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
VALUES (2500, 450);

select * from account;


/*owner_property data*/

INSERT INTO owner_property (owner_type, owner_id, account_id)
VALUES ("owner", 4, 3);

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
VALUES ("credit", 4, 2);
select * from card_property;

select * from account;

/* to delete with forgeinkey
SET FOREIGN_KEY_CHECKS=0;
to close delte
SET FOREIGN_KEY_CHECKS=1;

delete from card_property where id_card_property = 2;
*/
call get_owner_account_info(1)
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

select balance, credit_limit from account where id_account = 1
select * from account
select * from card
select * from card_property

select * from owner_property
select * from owner

call create_card("pass",?,?,?)

update account set credit_limit =1000 where id_account = 2
select id_event, date_format(date,"%d.%m.%Y") as "date",account_id, action, sum, card_id from  event where account_id = 1 order by date desc 