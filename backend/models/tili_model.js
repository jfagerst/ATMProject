const db=require('../database');


const tili={
    getAll:function(callback) {
        return db.query('SELECT * FROM tili', callback);
    },
    getById:function(id, callback){
        return db.query('SELECT * FROM tili WHERE idtili=?',[id],callback);
    },
    add:function(tili_data, callback){
        return db.query('INSERT INTO tili(saldo,idasiakas,avauspvm,luottoraja) VALUES (?,?,?,?)',[tili_data.saldo, tili_data.idasiakas, tili_data.avauspvm, tili_data.luottoraja], callback);
    },
    update:function(id, tili_data, callback){
        return db.query('UPDATE tili SET saldo=?, luottoraja=? WHERE idtili=?',[tili_data.saldo, tili_data.luottoraja, id], callback);
    },
    delete:function(id, callback){
        return db.query('DELETE FROM tili WHERE idtili=?',[id], callback);
    },
    getSaldoByKorttiId: function(id, callback) {
        return db.query(`
            SELECT tili.saldo 
            FROM tili 
            JOIN korttitili ON tili.idtili = korttitili.idtili 
            JOIN kortti ON korttitili.idkortti = kortti.idkortti 
            WHERE kortti.idkortti = ?
        `, [id], callback);
    },
    getKorttiTyyppi: function (idkortti, callback) {
        return db.query(
            'SELECT tyyppi FROM korttitili WHERE idkortti = ?',
            [idkortti],
            callback
            );
        },
        getByKorttiId: function(idkortti, callback) {
            return db.query(`
                SELECT tili.idtili 
                FROM tili 
                JOIN korttitili ON tili.idtili = korttitili.idtili 
                JOIN kortti ON korttitili.idkortti = kortti.idkortti 
                WHERE kortti.idkortti = ?
            `, [idkortti], callback);
        },
    withdrawSaldoByKorttiId: function (idkortti, nostosumma, callback) {
        return db.query(
            `UPDATE tili 
            JOIN korttitili ON tili.idtili = korttitili.idtili 
            JOIN kortti ON korttitili.idkortti = kortti.idkortti 
            SET tili.saldo = tili.saldo - ? 
            WHERE kortti.idkortti = ? AND tili.saldo >= ?`, 
            [nostosumma, idkortti, nostosumma],
            callback
        );
    },
    withdrawCreditByKorttiId: function (idkortti, nostosumma, callback) {
        return db.query(
            `UPDATE tili 
            JOIN korttitili ON tili.idtili = korttitili.idtili 
            JOIN kortti ON korttitili.idkortti = kortti.idkortti 
            SET tili.luottoraja = tili.luottoraja - ? 
            WHERE kortti.idkortti = ? AND tili.luottoraja >= ?`, 
            [nostosumma, idkortti, nostosumma],
            callback
        );
    },
    getCreditByKorttiId: function(id, callback) {
        return db.query(`
            SELECT tili.luottoraja 
            FROM tili 
            JOIN korttitili ON tili.idtili = korttitili.idtili 
            JOIN kortti ON korttitili.idkortti = kortti.idkortti 
            WHERE kortti.idkortti = ?
        `, [id], callback);
    }
    };



module.exports=tili;