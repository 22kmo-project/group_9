const db = require("../database");

const owner_property = {
  getById: function (id, callback) {
    db.query(
      "SELECT * from owner_property where id_owner_property=?",
      [id],
      function (err, result, fields) {
        if (err) throw err;
        console.log(result);
        callback(result);
      }
    );

  },
  getAll: function (callback) {
    //Select all owner_propertys and return the result
    db.query("select * from owner_property", function (err, result, fields) {

      if (err) throw err;
      console.log(result);
      console.log("GetAll");
      callback(result);
    });

    //return db.query("SELECT * FROM owner_property", callback);
  },
  add: function (owner_property, callback) {
    return db.query(
      "insert into owner_property (owner_type,owner_id,account_id) values(?,?,?)",
      [owner_property.owner_type, owner_property.owner_id,owner_property.account_id],
      callback
    );
  },
  delete: function (id, callback) {
    return db.query ("delete from owner_property where id_owner_property=?",[id],callback);
    
  },
  update: function (id, owner_property, callback) {
    return db.query(
      "update owner_property set owner_type=?,owner_id=?,account_id=? where id_owner_property=?",
      [owner_property.owner_type, owner_property.owner_id,owner_property.account_id, id],
      callback
    );
  },
};
module.exports = owner_property;
