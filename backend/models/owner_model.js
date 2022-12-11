const db = require("../database");
const bcrypt = require("bcryptjs");

const saltRounds = 10;
const card = {
  get: function (callback) {
    return db.query("call get_all_card_info()", callback);
  },
  getById: function (id, callback) {
    //return db.query("select * from card where id_card=?", [id], callback);
    return db.query("call get_owner_account_info(?)", [id], callback);
  },
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
  },
  delete: function (id, callback) {
    return db.query("delete from card where id_card=?", [id], callback);
  },
  update: function (id, card, callback) {
    bcrypt.hash(card.pin, saltRounds, function (err, hash) {
      return db.query(
        "update card set pin=? where id_card=?",
        [hash, id],
        callback
      );
    });
  },
};

module.exports = card;
