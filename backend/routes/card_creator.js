const express = require("express");
const router = express.Router();
const card_creator = require("../models/card_creator_model");

router.post("/", function (request, response) {
    card_creator.add(request.body, function (err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


module.exports = router;
