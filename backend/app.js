var express = require("express");
var path = require("path");
var cookieParser = require("cookie-parser");
var logger = require("morgan");
const jwt = require("jsonwebtoken");

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

const loginRouter = require("./routes/login");
const accountRouter = require("./routes/account");
const cardRouter = require("./routes/card");
const card_propertyRouter = require("./routes/card_property");
const balanceRouter = require("./routes/balance");
const ownerRouter = require("./routes/owner");
const owner_propertyRouter = require("./routes/owner_property");
const eventRouter = require("./routes/event");
const card_creatorRouter = require("./routes/card_creator");
const owner_creatorRouter = require("./routes/owner_creator");
const balanceCheckRouter = require("./routes/balance_check");

app.use("/login", loginRouter); //login is not protected

//commint when you have all ready created card
app.use(authenticateToken);

app.use("/card", cardRouter);
app.use("/account", accountRouter);
app.use("/balance", balanceRouter);
app.use("/owner_property", owner_propertyRouter);
app.use("/card_property", card_propertyRouter);
app.use("/event", eventRouter);
app.use("/owner", ownerRouter);
app.use("/balance_check", balanceCheckRouter);
app.use("/card_creator", card_creatorRouter);
app.use("/owner_creator", owner_creatorRouter);

module.exports = app;

function authenticateToken(req, res, next) {
  const authHeader = req.headers["authorization"];
  const token = authHeader && authHeader.split(" ")[1];

  console.log("token = " + token);
  if (token == null) return res.sendStatus(401);

  jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
    console.log(err);

    if (err) return res.sendStatus(403);

    req.user = user;

    next();
  });
}
