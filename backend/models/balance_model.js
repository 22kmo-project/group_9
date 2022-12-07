const db = require("../database");

const balance = {
  getById: function (id,card, callback) {
    console.log("testim");
    console.log("card",card);
    return db.query(
      "call get_account_balance_info(?,?)",
      [id,card],callback
    );
  },
  update: function (id, newbalance, callback) {
    return db.query(
        /*"update account set balance=? where id_account=?",*/
        "call update_account_balance(?,?)",
        [newbalance,id],callback);
}
};
module.exports = balance;