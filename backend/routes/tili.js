const express = require('express');
const router = express.Router();
const tili = require('../models/tili_model');
const tapahtuma = require('../models/tapahtuma_model');

router.get('/', function(request, response){
    tili.getAll(function(err, result){
        if(err){
            response.json(err);
        }
        else {
            response.json(result);
        }
    })
});

router.get('/:id', function(request, response){
    tili.getById(request.params.id,function(err, result){
        if(err){
            response.json(err);
        }
        else {
            response.json(result[0]);
        }
    })
});

router.post('/',function(request, response){
    tili.add(request.body, function(err, result){
        if(err){
            response.json(err);
        }
        else {
            response.json(result.affectedRows);
        }
    })
});

router.put('/:id',function(request, response){
    tili.update(request.params.id,request.body, function(err, result){
        if(err){
            response.json(err);
        }
        else {
            response.json(result.affectedRows);
        }
    })
});

router.delete('/:id',function(request, response){
    tili.delete(request.params.id, function(err,result){
        if(err){
            response.json(err);
        }
        else {
            response.json(result.affectedRows);
        }
    })
});

router.get('/saldo/kortti/:id', function(request, response) {
    tili.getSaldoByKorttiId(request.params.id, function(err, result) {
        if (err) {
            response.json(err);
        } else {
            if (result.length > 0) {
                response.json({ saldo: result[0].saldo });
            } else {
                response.status(404).json({ message: 'Tiliä ei löytynyt' });
            }
        }
    });
});


router.get('/nosto/debit/check/:id', function (request, response) {
    const idkortti = request.params.id;

    tili.getKorttiTyyppi(idkortti, function (err, result) {
        if (err) {
            response.json(err);
        } else {
            if (result.length > 0 && (result[0].tyyppi === 'debit' || result[0].tyyppi === 'credit+debit')) {
                response.json({ debitAvailable: true });
            } else {
                response.json({ debitAvailable: false });
            }
        }
    });
});

router.get('/nosto/credit/check/:id', function (request, response) {
    const idkortti = request.params.id;

    tili.getKorttiTyyppi(idkortti, function (err, result) {
        if (err) {
            response.json(err);
        } else {
            if (result.length > 0 && (result[0].tyyppi === 'credit' || result[0].tyyppi === 'credit+debit')) {
                response.json({ creditAvailable: true });
            } else {
                response.json({ creditAvailable: false });
            }
        }
    });
});

router.get('/credit/kortti/:id', function(req, res) {
    tili.getCreditByKorttiId(req.params.id, function(err, result) {
        if (err) {
            res.status(500).json({ error: err.message });
        } else if (result.length === 0) {
            res.status(404).json({ error: "Credit info not found" });
        } else {
            res.json(result[0]);
        }
    });
});

router.get('/nosto/kortti/check/:id', function (request, response) {
    const idkortti = request.params.id;

    tili.getKorttiTyyppi(idkortti, function (err, result) {
        if (err) {
            response.json(err);
        } else {
            if (result.length > 0) {
                const tyyppi = result[0].tyyppi.toLowerCase();
                response.json({
                    debitAvailable: tyyppi === 'debit' || tyyppi === 'credit+debit',
                    creditAvailable: tyyppi === 'credit' || tyyppi === 'credit+debit'
                });
            } else {
                response.json({
                    debitAvailable: false,
                    creditAvailable: false
                });
            }
        }
    });
});

router.post('/saldo/kortti/:id', function(request, response) {
    const idkortti = request.params.id;
    const nostosumma = request.body.nostosumma;

    if (!nostosumma || isNaN(nostosumma) || nostosumma <= 0) {
        return response.status(400).json({ error: "Virheellinen nostosumma" });
    }

    tili.withdrawSaldoByKorttiId(idkortti, nostosumma, function(err, result) {
        if (err) {
            return response.status(500).json({ error: "Tietokantavirhe", details: err });
        } 
        if (result.affectedRows === 0) {
            return response.status(400).json({ error: "Ei tarpeeksi saldoa tai korttia ei löytynyt" });
        } 
        
        tili.getByKorttiId(idkortti, function(err, tiliResult) {
            if (err || tiliResult.length === 0) {
                return response.status(500).json({ error: "Tilin haku epäonnistui", details: err });
            }

            const idtili = tiliResult[0].idtili;
            const tapahtumaData = {
                paivamaara: new Date(),
                nostonmaara: nostosumma,
                idpankkiautomaatti: 1,
                idtili: idtili,
                tapahtumanTyyppi: "nosto"
            };

            tapahtuma.add(tapahtumaData, function(err, tapahtumaResult) {
                if (err) {
                    return response.status(500).json({ error: "Tapahtuman tallennus epäonnistui", details: err });
                }

                response.status(200).json({ message: "Nosto onnistui ja tapahtuma tallennettu!" });
            });
        });
    });
});

router.post('/luottoraja/kortti/:id', function(request, response) {
    const idkortti = request.params.id;
    const nostosumma = request.body.nostosumma;

    if (!nostosumma || isNaN(nostosumma) || nostosumma <= 0) {
        return response.status(400).json({ error: "Virheellinen nostosumma" });
    }

    tili.withdrawCreditByKorttiId(idkortti, nostosumma, function(err, result) {
        if (err) {
            return response.status(500).json({ error: "Tietokantavirhe", details: err });
        } 
        if (result.affectedRows === 0) {
            return response.status(400).json({ error: "Ei tarpeeksi luottoa tai korttia ei löytynyt" });
        } 
        
        tili.getByKorttiId(idkortti, function(err, tiliResult) {
            if (err || tiliResult.length === 0) {
                return response.status(500).json({ error: "Tilin haku epäonnistui", details: err });
            }

            const idtili = tiliResult[0].idtili;
            const tapahtumaData = {
                paivamaara: new Date(),
                nostonmaara: nostosumma,
                idpankkiautomaatti: 1,
                idtili: idtili,
                tapahtumanTyyppi: "nosto"
            };

            tapahtuma.add(tapahtumaData, function(err, tapahtumaResult) {
                if (err) {
                    return response.status(500).json({ error: "Tapahtuman tallennus epäonnistui", details: err });
                }

                response.status(200).json({ message: "Nosto onnistui ja tapahtuma tallennettu!" });
            });
        });
    });
});
module.exports=router;