const express = require("express");
const router = express.Router();
const bcrypt = require("bcryptjs");
const login = require("../models/card_model");
const jwt = require("jsonwebtoken");
const dotenv = require("dotenv");

router.post("/", function (request, response) {
  if (request.body.id_card && request.body.pin) {
    const id_card = request.body.id_card;
    console.log("id_card " + id_card);

    const pin = request.body.pin;
    console.log("pin " + id_card);

    login.checkPassword(id_card, function (dbError, dbResult) {
      if (dbError) {
        response.json(dbError.errno);
        console.log("id_card does not exists");
        response.send(false);
      } else {
        console.log(dbResult[0].pin + " " + pin);

        if (dbResult.length > 0) {
          bcrypt.compare(pin, dbResult[0].pin, function (err, compareResult) {
            if (compareResult) {
              console.log("succes");
              const token = generateAccessToken({
                username: request.body.id_card,
              });
              response.send(token);
            } else {
              console.log("wrong pin");
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
    console.log("id_card or pin missing");
    response.send(false);
  }
});

function generateAccessToken(username) {
  dotenv.config();
  return jwt.sign(username, process.env.MY_TOKEN, {
    expiresIn: "1800s",
  });
}

module.exports = router;
