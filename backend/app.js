var express = require("express");
var path = require("path");
var cookieParser = require("cookie-parser");
var logger = require("morgan");

var app = express();

app.use(logger("dev"));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, "public")));

const helmet = require("helmet");
const cors = require("cors");

app.use(helmet());
app.use(cors());

const accountRouter = require("./routes/account");
app.use("/account", accountRouter);

module.exports = app;
