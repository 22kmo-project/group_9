const mysql = require("mysql");
const connection = mysql.createPool({
  host: "localhost",
  user: "group_9",
  password: "netpass",
  database: "banksimul_db",
});

connection.getConnection(function (err) {
  if (err) {
    console.error("error connecting: " + err.stack);
    return;
  }

  console.log("connected as id " + connection.threadId);
});

module.exports = connection;
