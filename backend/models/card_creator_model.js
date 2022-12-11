const db = require("../database");
const bcrypt = require("bcryptjs");

const saltRounds = 10;
const card_creator = {

  add: function (card, callback) {
    bcrypt.hash(card.pin, saltRounds, function (err, hash) {
      console.log(
        hash +
          "\n" +
          card.owner_id +
          "\n" +
          card.account_id +
          "\n" +
          card.card_type
      );

      //return db.query("insert into card ( pin) values(?)", [hash], callback);
      return db.query(
        "call create_card(?,?,?,?)",
        [hash, card.owner_id, card.account_id, card.card_type],
        callback
      );
    });
  }
};

module.exports = card_creator;
