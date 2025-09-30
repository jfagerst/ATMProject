const express=require('express');
const router=express.Router();
const tapahtuma=require('../models/tapahtuma_model');

router.get('/',function(req,res){
    tapahtuma.getAll(function(err,result){
        if(err){
            res.status(500).json(err);
        } else{
            res.json(result);
        }
    });
});

router.get('/:id',function(req,res){
    tapahtuma.getById(req.params.id,function(err,result){
        if(err){
            res.status(500).json(err);
        } else{
            res.json(result);
        }
    });
});

router.post('/',function(req,res){
    tapahtuma.add(req.body,function(err,result){
        if(err){
            res.status(500).json(err);
        } else{
            res.status(201).json(result);
        }
    });
});

router.put('/:id', function(req,res){
    tapahtuma.update(req.params.id,req.body,function(err,result){
       if(err){
        res.status(500).json(err);
       } else{
        res.json(result);
       }
    });
});

router.delete('/:id',function(req,res){
    tapahtuma.delete(req.params.id,function(err,result){
        if(err){
            res.status(500).json(err);
        } else{
            res.json(result);
        }
    });
});

router.get('/kortti/:id', function(request, response) {
    const page = parseInt(request.query.page) || 1;
    const limit = 10; 
    const offset = (page - 1) * limit; 

    tapahtuma.getTapahtumatByKorttiId(request.params.id, limit, offset, function(err, result) {
        if (err) {
            response.status(500).json(err);
        } else {
            if (result.length > 0) {
                tapahtuma.getTapahtumatCount(request.params.id, function(err, countResult) {
                    if (err) {
                        response.status(500).json(err);
                    } else {
                        const totalCount = countResult[0].count;
                        const totalPages = Math.ceil(totalCount / limit);

                        response.json({
                            tapahtumat: result,
                            totalPages: totalPages,
                            currentPage: page
                        });
                    }
                });
            } else {
                response.status(404).json({ message: 'Ei tapahtumia tälle kortille' });
            }
        }
    });
});
module.exports=router;