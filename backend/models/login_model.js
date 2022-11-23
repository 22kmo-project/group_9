const db = require("../database");

const login = {
  checkPassword: function (id_card, callback) {
    return db.query(
      "SELECT password FROM card_table WHERE id_card = ?",
      [id_card],
      callback
    );
  },
};

module.exports = login;
