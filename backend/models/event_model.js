const db = require("../database");

const event = {
  getById: function (id, callback) {
    db.query(
      "SELECT * from event where id_event=?",
      [id],
      function (err, result, fields) {
        if (err) throw err;
        console.log(result);
        callback(result);
      }
    );

  },
  getAll: function (callback) {
    //Select all events and return the result
    db.query("select * from event", function (err, result, fields) {

      if (err) throw err;
      console.log(result);
      console.log("GetAll");
      callback(result);
    });

    //return db.query("SELECT * FROM event", callback);
  },
  add: function (event, callback) {
    return db.query(
      "insert into event (account_id,date,action,sum) values(?,?,?,?)",
      [event.account_id, event.date,event.action, event.sum],
      callback
    );
  },
  delete: function (id, callback) {
    return db.query ("delete from event where id_event=?",[id],callback);
    
  },
  update: function (id, event, callback) {
    return db.query(
      "update event set account_id=?,date=?,action=?,sum=? where id_event=?",
      [event.account_id, event.date,event.action, event.sum, id],
      callback
    );
  },
};
module.exports = event;
