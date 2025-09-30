const express = require('express');
const router = express.Router();
const kortti = require('../models/kortti_model');

router.get('/', function(request, response){
    kortti.getAll(function(err, result){
        if(err){
            response.json(err);
        }
        else {
            response.json(result);
        }
    })
});


router.get('/:id', function(request, response){
    kortti.getById(request.params.id,function(err, result){
        if(err){
            response.json(err);
        }
        else {
            response.json(result);
        }
    })
});

router.post('/', function(request, response) {
    const { pin, voimassaolo } = request.body;
    kortti.add(pin, voimassaolo, function(err, result) {
        if (err) {
            response.json(err);
        } else {
            response.json(result);
        }
    });
});

router.put('/:id', function(request, response) {
    const { pin, voimassaolo } = request.body;
    kortti.update(request.params.id, pin, voimassaolo, function(err, result) {
        if (err) {
            response.json(err);
        } else {
            response.json(result);
        }
    });
});

router.delete('/:id', function(request, response){
    kortti.delete(request.params.id, function(err, result){
        if(err){
            response.json(err);
        }
        else {
            response.json(result);
        }
    });
});

module.exports=router;