const db = require("../database");
const bcrypt = require("bcryptjs");

const saltRounds = 10;
const balance_check = {
  checkPassword: function (account_id, callback) {
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
      "select balance, credit_limit from account where id_account = ?",
      [account_id],
      callback
    );
  },
};

module.exports = balance_check;
