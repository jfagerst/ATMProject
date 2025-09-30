DELIMITER //
CREATE PROCEDURE GetAllTapahtumat()
BEGIN
    SELECT * FROM tapahtuma;
END //

DELIMITER ;

DELIMITER //
CREATE PROCEDURE GetTapahtumaById(IN tapahtumaId INT)
BEGIN
    SELECT * FROM tapahtuma WHERE idtapahtuma=tapahtumaId;
END //

DELIMITER ;

DELIMITER //
CREATE PROCEDURE AddTapahtuma(
   IN paivamaara DATE,
   IN nostonmaara DECIMAL(10,2),
   IN idpankkiautomaatti INT,
   IN idtili INT,
   IN tapahtumantyyppi VARCHAR(50)
)
BEGIN
    INSERT INTO tapahtuma (paivamaara, nostonmaara, idpankkiautomaatti, idtili, tapahtumanTyyppi)
    VALUES (paivamaara, nostonmaara, idpankkiautomaatti, idtili, tapahtumanTyyppi);
END //

DELIMITER ;

DELIMITER //
CREATE PROCEDURE UpdateTapahtuma(
    IN tapahtumaId INT,
    IN paivamaara DATE,
    IN nostonmaara DECIMAL(10,2),
    IN idpankkiautomaatti INT,
    IN idtili INT,
    IN tapahtumanTyyppi VARCHAR(50)
)
BEGIN
   UPDATE tapahtuma
    SET paivamaara=paivamaara,
        nostonmaara=nostonmaara,
        idpankkiautomaatti=idpankkiautomaatti,
        idtili=idtili,
        tapahtumanTyyppi=tapahtumanTyyppi
    WHERE idtapahtuma=tapahtumaId;
END //

DELIMITER ;

DELIMITER //
CREATE PROCEDURE DeleteTapahtuma(IN tapahtumaId INT)
BEGIN
    DELETE FROM tapahtuma WHERE idtapahtuma=tapahtumaId;
END //

DELIMITER ;