CREATE DATABASE  IF NOT EXISTS `pankki` /*!40100 DEFAULT CHARACTER SET utf8mb3 */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `pankki`;
-- MySQL dump 10.13  Distrib 8.0.36, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: pankki
-- ------------------------------------------------------
-- Server version	8.2.0

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `asiakas`
--

DROP TABLE IF EXISTS `asiakas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas` (
  `etunimi` varchar(45) DEFAULT NULL,
  `osoite` varchar(45) DEFAULT NULL,
  `idasiakas` int NOT NULL AUTO_INCREMENT,
  `puhelin` varchar(45) DEFAULT NULL,
  `sukunimi` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`idasiakas`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas`
--

LOCK TABLES `asiakas` WRITE;
/*!40000 ALTER TABLE `asiakas` DISABLE KEYS */;
/*!40000 ALTER TABLE `asiakas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `kortti`
--

DROP TABLE IF EXISTS `kortti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `kortti` (
  `idkortti` int NOT NULL AUTO_INCREMENT,
  `pin` varchar(255) DEFAULT NULL,
  `voimassaolo` date DEFAULT NULL,
  PRIMARY KEY (`idkortti`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kortti`
--

LOCK TABLES `kortti` WRITE;
/*!40000 ALTER TABLE `kortti` DISABLE KEYS */;
/*!40000 ALTER TABLE `kortti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `korttitili`
--

DROP TABLE IF EXISTS `korttitili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `korttitili` (
  `idkortti` int NOT NULL,
  `idtili` int NOT NULL,
  `tyyppi` enum('credit','debit','credit+debit') DEFAULT NULL,
  PRIMARY KEY (`idkortti`,`idtili`),
  KEY `Korttinro_idx` (`idkortti`),
  KEY `Tilinro_idx` (`idtili`),
  CONSTRAINT `Korttinro` FOREIGN KEY (`idkortti`) REFERENCES `kortti` (`idkortti`),
  CONSTRAINT `Tilinro` FOREIGN KEY (`idtili`) REFERENCES `tili` (`idtili`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `korttitili`
--

LOCK TABLES `korttitili` WRITE;
/*!40000 ALTER TABLE `korttitili` DISABLE KEYS */;
/*!40000 ALTER TABLE `korttitili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pankkiautomaatti`
--

DROP TABLE IF EXISTS `pankkiautomaatti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pankkiautomaatti` (
  `idpankkiautomaatti` int NOT NULL AUTO_INCREMENT,
  `automaatinvarat` int DEFAULT NULL,
  `idkortti` int DEFAULT NULL,
  PRIMARY KEY (`idpankkiautomaatti`),
  KEY `kortti_nostoautomaatti_idx` (`idkortti`),
  CONSTRAINT `kortti_nostoautomaatti` FOREIGN KEY (`idkortti`) REFERENCES `kortti` (`idkortti`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pankkiautomaatti`
--

LOCK TABLES `pankkiautomaatti` WRITE;
/*!40000 ALTER TABLE `pankkiautomaatti` DISABLE KEYS */;
/*!40000 ALTER TABLE `pankkiautomaatti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tapahtuma`
--

DROP TABLE IF EXISTS `tapahtuma`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tapahtuma` (
  `idtapahtuma` int NOT NULL AUTO_INCREMENT,
  `paivamaara` date DEFAULT NULL,
  `nostonmaara` int DEFAULT NULL,
  `idpankkiautomaatti` int DEFAULT NULL,
  `tapahtumanTyyppi` enum('nosto','talletus','saldo') DEFAULT NULL,
  `idtili` int DEFAULT NULL,
  PRIMARY KEY (`idtapahtuma`),
  KEY `nostoautomaatti_nosto_idx` (`idpankkiautomaatti`),
  KEY `tili_tapahtuma_idx` (`idtili`),
  CONSTRAINT `pankkiautomaatti_tapahtuma` FOREIGN KEY (`idpankkiautomaatti`) REFERENCES `pankkiautomaatti` (`idpankkiautomaatti`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `tili_tapahtuma` FOREIGN KEY (`idtili`) REFERENCES `tili` (`idtili`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tapahtuma`
--

LOCK TABLES `tapahtuma` WRITE;
/*!40000 ALTER TABLE `tapahtuma` DISABLE KEYS */;
/*!40000 ALTER TABLE `tapahtuma` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tili`
--

DROP TABLE IF EXISTS `tili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tili` (
  `idtili` int NOT NULL AUTO_INCREMENT,
  `saldo` decimal(10,0) DEFAULT NULL,
  `idasiakas` int DEFAULT NULL,
  `avauspvm` date DEFAULT NULL,
  PRIMARY KEY (`idtili`),
  KEY `asiakas_tili_idx` (`idasiakas`),
  CONSTRAINT `asiakas_tili` FOREIGN KEY (`idasiakas`) REFERENCES `asiakas` (`idasiakas`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tili`
--

LOCK TABLES `tili` WRITE;
/*!40000 ALTER TABLE `tili` DISABLE KEYS */;
/*!40000 ALTER TABLE `tili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'pankki'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-01-16 17:59:29
