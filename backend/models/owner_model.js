const db = require("../database");

const owner = {
  getById: function (id, callback) {
    db.query(
      "SELECT * from owner where id_owner=?",
      [id],
      function (err, result, fields) {
        if (err) throw err;
        console.log(result);
        callback(result);
      }
    );

    //Siirretäänkö tämä erilliseen modeliin?
    //return db.query("call get_owner_info(?)", [id], callback);
  },
  getAll: function (callback) {
    //Select all owners and return the result
    db.query("select * from owner", function (err, result, fields) {

      if (err) throw err;
      console.log(result);
      console.log("GetAll");
      callback(result);
    });

    //return db.query("SELECT * FROM owner", callback);
  },
  add: function (owner, callback) {
    return db.query(
     "insert into owner (fname,lname,address,phone) values(?,?,?,?)",
      [owner.fname, owner.lname,owner.address,owner.phone],
      callback
       /* return db.query("call create_owner(?,?,?,?,?,?)",
        [owner.fname,owner.lname,owner.address,owner.phone,owner.owner_type,owner.account_id],
        callback*/
    );
  },
  delete: function (id, callback) {
    //return db.query("delete from owner where id_owner=?", [id], callback);
    return db.query ("call delete_owner_and_foreign_keys(?)",[id],callback);
    
  },
  update: function (id, owner, callback) {
    return db.query(
      "update owner set fname=?,lname=?,address=?,phone=? where id_owner=?",
      [owner.fname, owner.lname,owner.address,owner.phone, id],
      callback
    );
  },
};
module.exports = owner;
