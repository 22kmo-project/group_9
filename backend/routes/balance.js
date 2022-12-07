const express = require("express");
const router = express.Router();
const balance = require("../models/balance_model");

router.get("/:id?/:card?/:sum?",function (request, response) {
  console.log("testi");
  const card=request.params.card;
  const id=request.params.id;
  const sum=request.params.sum;
  balance.getById(id,card, function (err,dbResult) {

      if (err) {
        console.log("errori");
        response.json(err);
      } else {
      answer = dbResult;

       console.log("toimi");
       response.json(dbResult);
       console.log(answer);

      

    }});

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