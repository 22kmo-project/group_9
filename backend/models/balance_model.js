const db = require("../database");

const balance = {
  getById: function (id,data, callback) {
    console.log("testim");
    console.log("data",data);
    return db.query(
      "call get_account_balance_info(?,?)",
      [data.id,data.card],callback
    );
  },
  update: function (data, callback) {
    return db.query(
        /*"update account set balance=? where id_account=?",*/
        "call update_account_balance(?,?)",
        [data.id,data.newbalance],callback);
}
};
module.exports = balance;