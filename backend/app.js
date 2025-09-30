var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var indexRouter = require('./routes/index');


var pankkiautomaattiRouter = require('./routes/pankkiautomaatti');
var korttiRouter = require('./routes/kortti');
var tapahtumaRouter = require('./routes/tapahtuma');
var asiakasRouter = require('./routes/asiakas');
var tiliRouter = require('./routes/tili');
var korttiTiliRoutes = require('./routes/korttiTili');
var loginRouter = require('./routes/login');
const jwt = require('jsonwebtoken');


var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);

app.use('/login', loginRouter);
//app.use(authenticateToken);
app.use('/pankkiautomaatti', pankkiautomaattiRouter);
app.use('/kortti', korttiRouter);
app.use('/tapahtuma', tapahtumaRouter);
app.use('/asiakas', asiakasRouter);
app.use('/tili', tiliRouter);
app.use("/korttiTili", korttiTiliRoutes);
app.use("/login", loginRouter);


/**const PORT = process.env.PORT || 3000;
*app.listen(PORT, () => {
*  console.log(`Server is running on port ${PORT}`);
});*/

function authenticateToken(req, res, next) {
  const authHeader = req.headers['authorization']
  const token = authHeader && authHeader.split(' ')[1]

  console.log("token = "+token);
  if (token == null) return res.sendStatus(401)

  jwt.verify(token, process.env.MY_TOKEN, function(err, user) {

    if (err) return res.sendStatus(403)

    req.user = user

    next()
  })
}

module.exports = app;
