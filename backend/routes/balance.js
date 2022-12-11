const express = require("express");
const router = express.Router();
const balance = require("../models/balance_model");

router.get("/:id?",function (request, response) {
  const id=request.params.id;
  balance.getById(id, function (err,dbResult) {

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

  router.put("/", function (request, response) {
    balance.update(request.body, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  });

  module.exports = router;