const db = require("../database");

const account = {
  getById: function (id, callback) {
    /*db.query(
      "SELECT * from account where id_account=?",
      [id],
      function (err, result, fields) {
        if (err) throw err;
        console.log(result);
        callback(result);
      }
    );*/

    return db.query("call get_account_info(?)", [id], callback);
  },
  getAll: function (callback) {
    //Select all customers and return the result object:y
    db.query("call select_from_account(?)", function (err, result, fields) {
      console.log("[mysql error]", err);

      if (err) throw err;
      console.log(result);
      console.log("GetAll");
      callback(result);
    });

    //return db.query("SELECT * FROM account", callback);
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
