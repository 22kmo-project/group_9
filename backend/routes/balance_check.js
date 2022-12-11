const express = require("express");
const router = express.Router();
const balance_check = require("../models/balance_check_model.js");

router.post("/", function (request, response) {
  if (request.body.account_id && request.body.card_type && request.body.summa) {
    const account_id = request.body.account_id;
    const summa = request.body.summa;
    const card_type = request.body.card_type;

    console.log("account_id " + account_id);
    balance_check.checkPassword(account_id, function (dbError, dbResult) {
      if (dbError) {
        response.json(dbError.errno);
        console.log("account_id does not exists");
        response.send(false);
      } else {
        console.log(
          "balance: " + dbResult[0].balance + " " + dbResult[0].credit_limit
        );

        if (card_type == "credit") {
          if (summa <= dbResult[0].balance + dbResult[0].credit_limit) {
            console.log(
              "asumma" +
                summa +
                " all" +
                (dbResult[0].balance + dbResult[0].credit_limit)
            );

            response.send(true);
          } else {
            response.send(false);
          }
        } else {
          if (summa <= dbResult[0].balance) {
            console.log("asumma" + summa + " all" + dbResult[0].balance);

            response.send(true);
          } else {
            response.send(false);
          }
        }
      }
    });
  } else {
    console.log("id_card or pin missing");
    response.send(false);
  }
});

module.exports = router;
