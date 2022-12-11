const db = require("../database");

const balance = {
  getById: function (id, callback) {
    return db.query("call get_account_info(?)", [id], callback);
    
  },
}
module.exports = balance;