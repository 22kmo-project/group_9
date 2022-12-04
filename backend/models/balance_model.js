const db = require("../database");
const account = require("./account_model");

const balance = {
  getById: function (id, callback) {

    return db.query(
      "call get_account_balance(?,?)",
      [hash, account.id_account, account.balance],
      callback
    );
  },

  update: function (id, account, callback) {
    return db.query(
      "call update_account_balance(?,?)",
      [hash, account.id_account, account.balance],
      callback
    );
  },
};
module.exports = balance;