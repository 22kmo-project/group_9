const express = require("express");
const router = express.Router();
const account = require("../models/balance_model");

router.get("/:id?", function (request, response) {
    account.getById(request.params.id, request.params.card, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  });

router.put("/:id", function (request, response) {
    balance.update(request.params.id, request.body, function (err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;
