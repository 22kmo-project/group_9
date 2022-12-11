const db = require("../database");

const owner_creator = {

  add: function (owner, callback) {
    /*return db.query(
     "insert into owner (fname,lname,address,phone) values(?,?,?,?)",
      [owner.fname, owner.lname,owner.address,owner.phone],
      callback*/
        return db.query("call create_owner(?,?,?,?,?,?)",
        [owner.fname,owner.lname,owner.address,owner.phone,owner.owner_type,owner.account_id],
        callback
    );
  },
};
module.exports = owner_creator;
