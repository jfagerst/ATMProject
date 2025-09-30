const db=require('../database');


const asiakas={
    getAll:function(callback) {
        return db.query('SELECT * FROM asiakas', callback);
    },
    getById:function(id, callback){
        return db.query('SELECT * FROM asiakas WHERE idasiakas=?',[id],callback);
    },
    add:function(asiakas_data, callback){
        return db.query('INSERT INTO asiakas(etunimi,osoite,puhelin,sukunimi) VALUES (?,?,?,?)',[asiakas_data.etunimi, asiakas_data.osoite, asiakas_data.puhelin, asiakas_data.sukunimi], callback);
    },
    update:function(id, asiakas_data, callback){
        return db.query('UPDATE asiakas SET etunimi=?, osoite=?, puhelin=?, sukunimi=? WHERE idasiakas=?',[asiakas_data.etunimi, asiakas_data.osoite, asiakas_data.puhelin, asiakas_data.sukunimi, id], callback);
    },
    delete:function(id, callback){
        return db.query('DELETE FROM asiakas WHERE idasiakas=?',[id], callback);
    }
}

module.exports=asiakas;