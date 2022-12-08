const db = require("../database");
const bcrypt = require("bcryptjs");

const saltRounds = 10;
const event = {
  get: function (callback) {
    return db.query(
      'select id_event, date_format(date,"%d.%m.%Y") as "date",account_id, action, sum, card_id from  event',
      callback
    );
  },
  getAll: function (callback) {
    return db.query(
      'select id_event, date_format(date,"%d.%m.%Y") as "dateeu",account_id, action, sum, card_id from event order by date desc;',
      callback
    );
  },
  add: function (add_data, callback) {
    return db.query(
      "call create_event(?,?,?,?,?)",
      [
        add_data.account_id,
        add_data.card_id,
        add_data.date,
        add_data.action,
        add_data.sum,
      ],
      callback
    );
  },
  delete: function (id, callback) {
    return db.query("delete from grade where id_grade=?", [id], callback);
  },
  update: function (id, update_data, callback) {
    return db.query(
      "update grade set grade_date=?,id_student=?, id_course=?, grade=? where id_grade=?",
      [
        update_data.grade_date,
        update_data.id_student,
        update_data.id_course,
        update_data.grade,
        id,
      ],
      callback
    );
  },
};

module.exports = event;
