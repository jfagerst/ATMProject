/*const mysql = require('mysql2');

const db = mysql.createConnection({
  host: 'localhost', 
  user: 'root',    
  password: 'test',    
  database: 'pankki'  
});

module.exports = db;*/

const dotenv=require('dotenv');
const mysql = require('mysql2');

dotenv.config();

const connection = mysql.createPool(process.env.SQL_SERVER);

module.exports=connection;