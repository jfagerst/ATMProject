const db = require("../database");

const korttiTili = {
    getAll: function(callback) {
        return db.query('SELECT * FROM korttiTili', callback);
    },

    add: function(idkortti, idtili, tyyppi, callback) {
        return db.query('INSERT INTO korttiTili (idkortti, idtili, tyyppi) VALUES (?, ?, ?)', [idkortti, idtili, tyyppi], callback);
    },

    update: function(id, idtili, tyyppi, callback) {
        return db.query('UPDATE korttiTili SET idtili = ?, tyyppi = ? WHERE id = ?', [idtili, tyyppi, id], callback);
    },

    delete: function(id, callback) {
        return db.query('DELETE FROM korttiTili WHERE id = ?', [id], callback);
    }
};

module.exports = korttiTili;
