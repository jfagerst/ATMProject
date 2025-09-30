const express = require('express');
const router = express.Router();
const korttiTiliModel = require('../models/korttiTili_model');


router.get('/', (req, res) => {
    korttiTiliModel.getAll((err, rows) => {
        if (err) {
            return res.status(500).json({ message: 'Internal server error', error: err.message });
        }
        res.json(rows);
    });
});


router.post('/', (req, res) => {
    const { idkortti, idtili, tyyppi } = req.body;
    korttiTiliModel.add(idkortti, idtili, tyyppi, (err, result) => {
        if (err) {
            return res.status(500).json({ message: 'Failed to add KorttiTili', error: err.message });
        }
        res.status(201).json({ message: 'KorttiTili added successfully' });
    });
});


router.put('/:id', (req, res) => {
    const { idkortti, idtili, tyyppi } = req.body;
    const { id } = req.params;
    korttiTiliModel.update(id, idkortti, idtili, tyyppi, (err, result) => {
        if (err) {
            return res.status(500).json({ message: 'Failed to update KorttiTili', error: err.message });
        }
        res.json({ message: 'KorttiTili updated successfully' });
    });
});

router.delete('/:id', (req, res) => {
    const { id } = req.params;
    korttiTiliModel.delete(id, (err, result) => {
        if (err) {
            return res.status(500).json({ message: 'Failed to delete KorttiTili', error: err.message });
        }
        res.json({ message: 'KorttiTili deleted successfully' });
    });
});

module.exports = router;
