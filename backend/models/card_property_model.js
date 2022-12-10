const db = require("../database");

const card_property = {
  getById: function (id, callback) {
    db.query(
      "SELECT * from card_property where id_card_property=?",
      [id],
      function (err, result, fields) {
        if (err) throw err;
        console.log(result);
        callback(result);
      }
    );

  },
  getAll: function (callback) {
    //Select all card_propertys and return the result
    db.query("select * from card_property", function (err, result, fields) {

      if (err) throw err;
      console.log(result);
      console.log("GetAll");
      callback(result);
    });

  },
  add: function (card_property, callback) {
    return db.query(
      "insert into card_property (card_type,card_id,account_id) values(?,?,?)",
      [card_property.card_type, card_property.card_id,card_property.account_id],
      callback
    );
  },
  delete: function (id, callback) {
    //return db.query("delete from card_property where id_card_property=?", [id], callback);
    return db.query ("delete from card_property where id_card_property=?",[id],callback);
    
  },
  update: function (id, card_property, callback) {
    return db.query(
      "update card_property set card_type=?,card_id=?,account_id=? where id_card_property=?",
      [card_property.card_type, card_property.card_id,card_property.account_id, id],
      callback
    );
  },
};
module.exports = card_property;
