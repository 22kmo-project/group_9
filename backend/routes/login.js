const express = require("express");
const router = express.Router();
const bcrypt = require("bcryptjs");
const login = require("../models/card_model");
const jwt = require("jsonwebtoken");
const dotenv = require("dotenv");

router.post("/", function (request, response) {
  if (request.body.id_card && request.body.pinword) {
    const id_card = request.body.id_card;
    console.log("id_card " + id_card);

    const pin = request.body.pinword;
    console.log("pin " + id_card);

    login.checkPassword(id_card, function (dbError, dbResult) {
      if (dbError) {
        response.json(dbError);
      } else {
        console.log(dbResult[0].pin + " " + pin);

        if (dbResult.length > 0) {
          bcrypt.compare(pin, dbResult[0].pin, function (err, compareResult) {
            if (compareResult) {
              console.log("succes");
              const token = generateAccessToken({ id_card: id_card });
              response.send(token);
            } else {
              console.log("wrong pinword");
              response.send(false);
            }
          });
        } else {
          console.log("id_card does not exists");
          response.send(false);
        }
      }
    });
  } else {
    console.log("id_card or pinword missing");
    response.send(false);
  }
});

function generateAccessToken(id_card) {
  dotenv.config();
  return jwt.sign(id_card, process.env.MY_TOKEN, { expiresIn: "1800s" });
}

module.exports = router;
