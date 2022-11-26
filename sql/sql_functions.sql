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

call create_card("1234",1,1,"credit");

select * from card;

call get_card_info(21);

#get_card_info
DELIMITER //
CREATE PROCEDURE get_card_info(IN _card_id INT)
  BEGIN
select card_property.card_type, owner.fname, owner.lname, account.balance, account.credit_limit, card_property.account_id, owner.id_owner
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