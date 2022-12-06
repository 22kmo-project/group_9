const db = require("../database");
const bcrypt = require("bcryptjs");

const saltRounds = 10;
const event = {
  get: function (callback) {
    return db.query(
      'select id_event, date_format(date,"%d.%m.%Y") as "date",account_id, action, sum, card_id from event',
      callback
    );
  },
  getAll: function (callback) {
    return db.query(
      'select id_event, date_format(date,"%d.%m.%Y") as "date",account_id, action, sum, card_id from event',
      callback
    );
  },
  add: function (add_data, callback) {
    return db.query(
      "insert into id_event (event_date,account_id,card_id,event) values(?,?,?,?)",
      [
        add_data.event_date,
        add_data.account_id,
        add_data.card_id,
        add_data.event,
      ],
      callback
    );
  },
  delete: function (id, callback) {
    return db.query("delete from event where id_event=?", [id], callback);
  },
  update: function (id, update_data, callback) {
    return db.query(
      "update event set event_date=?,account_id=?, card_id=?, event=? where id_event=?",
      [
        update_data.event_date,
        update_data.account_id,
        update_data.card_id,
        update_data.event,
        id,
      ],
      callback
    );
  },
};

module.exports = event;
