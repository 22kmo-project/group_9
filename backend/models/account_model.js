const db = require("../database");

const account = {
  getById: function (id, callback) {
    return db.query("select * from account where id_account=?", [id], callback);
  },
  getAll: function (callback) {
    return db.query("select * from account", callback);
  },
  add: function (account, callback) {
    return db.query(
      "insert into account (balance,credit_limit) values(?,?)",
      [account.balance, account.credit_limit],
      callback
    );
  },
  delete: function (id, callback) {
    return db.query("delete from account where id_account=?", [id], callback);
  },
  update: function (id, account, callback) {
    return db.query(
      "update account set balance=?,credit_limit=? where id_account=?",
      [account.balance, account.credit_limit, id],
      callback
    );
  },
};
module.exports = account;
