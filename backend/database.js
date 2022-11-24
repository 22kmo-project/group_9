const mysql = require("mysql");
const connection = mysql.createPool({
  host: "localhost",
  user: "group_9",
  password: "netpass",
  database: "banksimul_db",
});
module.exports = connection;
