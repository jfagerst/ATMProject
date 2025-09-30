const express = require('express');
const router = express.Router();
const pankkiautomaatti = require('../models/pankkiautomaatti_model');

router.get('/', function(request, response){
    pankkiautomaatti.getAll(function(err, result){
        if(err){
            response.json(err);
        }
        else {
            response.json(result);
        }
    })
});


router.get('/:id', function(request, response){
    pankkiautomaatti.getById(request.params.id,function(err, result){
        if(err){
            response.json(err);
        }
        else {
            response.json(result);
        }
    })
});

router.post('/', function(request, response){
    const  {automaatinvarat, idkortti } = request.body;
    pankkiautomaatti.add(automaatinvarat, idkortti , function(err, result){
        if(err){
            response.json(err);
        }
        else {
            response.json(result);
        }
    });
});

router.put('/:id', function(request, response){
    const  { automaatinvarat, idkortti } =request.body;
    pankkiautomaatti.update(request.params.id, { automaatinvarat, idkortti }, function(err, result){
        if(err){
            response.json(err);
        }
        else {
            response.json(result);
        }
    });
});

router.delete('/:id', function(request, response){
    pankkiautomaatti.delete(request.params.id, function(err, result){
        if(err){
            response.json(err);
        }
        else {
            response.json(result);
        }
    });
});

module.exports=router;