const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const kortti = require('../models/kortti_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', function(request, response) {
  if (request.body.idkortti && request.body.pin) {
    const user = request.body.idkortti;
    const pass = request.body.pin;

    kortti.checkLockStatus(user, function(dbError, dbResult) {
      if (dbError) {
        response.send("-11");
      } else if (dbResult.length > 0 && dbResult[0].lukitus === 0) {
        response.send("Card is locked");
      } else {
        kortti.checkPassword(user, function(dbError, dbResult) {
          if (dbError) {
            response.send("-11");
          } else {
            if (dbResult.length > 0) {
              bcrypt.compare(pass, dbResult[0].pin, function(err, compareResult) {
                if (compareResult) {
                  console.log("success");
                  const token = generateAccessToken({ username: user });
                  response.send(token);
                } else {
                  console.log("wrong pin");
                  response.send(false);
                }
              });
            } else {
              console.log("idkortti does not exist");
              response.send(false);
            }
          }
        });
      }
    });
  } else {
    console.log("idkortti or pin missing");
    response.send(false);
  }
});

router.post('/lock', function(request, response) {
  const idkortti = request.body.idkortti;

  kortti.lockCard(idkortti, function(err, result) {
    if (err) {
      response.status(500).send("Virhe kortin lukituksessa");
    } else {
      response.send("Card is locked");
    }
  });
});

function generateAccessToken(idkortti) {
  dotenv.config();
  return jwt.sign(idkortti, process.env.MY_TOKEN, { expiresIn: '1800s' });
}

module.exports=router;