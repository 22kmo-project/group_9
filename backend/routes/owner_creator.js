const express = require("express");
const router = express.Router();
const owner_creator = require("../models/owner_creator_model");

router.post("/", function (request, response) {
    owner_creator.add(request.body, function (err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


module.exports = router;
