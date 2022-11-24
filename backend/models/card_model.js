const db = require("../database");
const bcrypt = require("bcryptjs");

const saltRounds = 10;
const card = {
  get: function (callback) {
    return db.query("select * from card", callback);
  },
  getById: function (id, callback) {
    return db.query("select * from card where id_card=?", [id], callback);
  },
  add: function (card, callback) {
    bcrypt.hash(card.pin, saltRounds, function (err, hash) {
      return db.query("insert into card ( pin) values(?)", [hash], callback);
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

  checkPassword: function (id_card, callback) {
    /*db.query(
      "select pin from Card where id_card=? ",
      [id_card],
      function (err, result, fields) {
        if (err) throw err;
        console.log(result);
        callback(result);
      }
    );*/

    //funvtion sql
    //"call function(?,?)", [id], [numer]

    return db.query(
      "select pin from card where id_card=?",
      [id_card],
      callback
    );
  },
};

module.exports = card;
