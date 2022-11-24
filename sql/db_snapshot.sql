-- MySQL dump 10.13  Distrib 8.0.30, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: banksimul_db
-- ------------------------------------------------------
-- Server version	8.0.29

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
-- Table structure for table `account`
--

DROP TABLE IF EXISTS `account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `account` (
  `id_account` int NOT NULL AUTO_INCREMENT,
  `balance` double DEFAULT NULL,
  `credit_limit` double DEFAULT NULL,
  PRIMARY KEY (`id_account`),
  UNIQUE KEY `idAccount_UNIQUE` (`id_account`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account`
--

LOCK TABLES `account` WRITE;
/*!40000 ALTER TABLE `account` DISABLE KEYS */;
INSERT INTO `account` VALUES (1,2500,3000),(2,2500,0);
/*!40000 ALTER TABLE `account` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `card`
--

DROP TABLE IF EXISTS `card`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `card` (
  `id_card` int NOT NULL AUTO_INCREMENT,
  `pin` varchar(255) DEFAULT NULL,
  `owner_id` int DEFAULT NULL,
  PRIMARY KEY (`id_card`),
  UNIQUE KEY `idCard_UNIQUE` (`id_card`),
  KEY `card_owner_id_idx` (`owner_id`),
  CONSTRAINT `card_owner_id` FOREIGN KEY (`owner_id`) REFERENCES `owner` (`id_owner`)
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `card`
--

LOCK TABLES `card` WRITE;
/*!40000 ALTER TABLE `card` DISABLE KEYS */;
INSERT INTO `card` VALUES (1,'1234',1),(2,'1234',1),(3,'1234',1),(4,'1234',1),(5,'1234',1),(6,'1234',1),(7,'1234',1),(8,'1234',1),(9,'1234',1),(10,'1234',1),(11,'1234',1),(12,'1234',1),(13,'1234',1),(14,'1234',1),(15,'1234',1),(16,'1234',1),(17,'1234',1),(18,'1234',1),(19,'1234',1),(20,'$2a$10$aTEoeqU6tKZQNTUpJgUJ5uC8p.ySEjqrypkKl.vKgmPVjb.b8SF.2',1),(21,'$2a$10$4B.SHUypAl4t1RUa9qvIkejPUomq2/TRLyRIAzwfs38Rk6t.32moS',2);
/*!40000 ALTER TABLE `card` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `card_property`
--

DROP TABLE IF EXISTS `card_property`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `card_property` (
  `id_card_property` int NOT NULL AUTO_INCREMENT,
  `card_type` varchar(6) DEFAULT NULL,
  `card_id` int DEFAULT NULL,
  `account_id` int DEFAULT NULL,
  PRIMARY KEY (`id_card_property`),
  UNIQUE KEY `idCard_property_UNIQUE` (`id_card_property`),
  KEY `idCard_idx` (`card_id`),
  KEY `card_account_idx` (`account_id`),
  CONSTRAINT `card` FOREIGN KEY (`card_id`) REFERENCES `card` (`id_card`),
  CONSTRAINT `card_account` FOREIGN KEY (`account_id`) REFERENCES `account` (`id_account`)
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `card_property`
--

LOCK TABLES `card_property` WRITE;
/*!40000 ALTER TABLE `card_property` DISABLE KEYS */;
INSERT INTO `card_property` VALUES (1,'credit',1,1),(2,'credit',2,1),(3,'credit',3,1),(4,'credit',4,1),(5,'credit',5,1),(6,'credit',6,1),(7,'credit',7,1),(8,'credit',8,1),(9,'credit',9,1),(10,'credit',10,1),(11,'credit',11,1),(12,'credit',12,1),(13,'credit',13,1),(14,'credit',14,1),(15,'credit',15,1),(16,'credit',16,1),(17,'credit',17,1),(18,'credit',18,1),(19,'credit',19,1),(20,'debit',20,1),(21,'debit',21,1);
/*!40000 ALTER TABLE `card_property` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `event`
--

DROP TABLE IF EXISTS `event`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `event` (
  `id_event` int NOT NULL AUTO_INCREMENT,
  `account_id` int DEFAULT NULL,
  `date` datetime DEFAULT NULL,
  `action` varchar(45) DEFAULT NULL,
  `sum` double DEFAULT NULL,
  PRIMARY KEY (`id_event`),
  UNIQUE KEY `idEvent_UNIQUE` (`id_event`),
  KEY `idAccount_idx` (`account_id`),
  CONSTRAINT `account` FOREIGN KEY (`account_id`) REFERENCES `account` (`id_account`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `event`
--

LOCK TABLES `event` WRITE;
/*!40000 ALTER TABLE `event` DISABLE KEYS */;
/*!40000 ALTER TABLE `event` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `owner`
--

DROP TABLE IF EXISTS `owner`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `owner` (
  `id_owner` int NOT NULL AUTO_INCREMENT,
  `fname` varchar(45) DEFAULT NULL,
  `lname` varchar(45) DEFAULT NULL,
  `address` varchar(45) DEFAULT NULL,
  `phone` varchar(15) DEFAULT NULL,
  PRIMARY KEY (`id_owner`),
  UNIQUE KEY `idOwner_UNIQUE` (`id_owner`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `owner`
--

LOCK TABLES `owner` WRITE;
/*!40000 ALTER TABLE `owner` DISABLE KEYS */;
INSERT INTO `owner` VALUES (1,'Pekka','Merivalo','Esimerkkitie 2','+35844231512345'),(2,'Liisa','Merivalo','Esimerkkitie 2','+35844231512346'),(3,'Juha','Wayne','Jokutie 3','+35844231512sd5');
/*!40000 ALTER TABLE `owner` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `owner_property`
--

DROP TABLE IF EXISTS `owner_property`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `owner_property` (
  `id_owner_property` int NOT NULL AUTO_INCREMENT,
  `owner_type` char(5) DEFAULT NULL,
  `owner_id` int DEFAULT NULL,
  `account_id` int DEFAULT NULL,
  PRIMARY KEY (`id_owner_property`),
  UNIQUE KEY `idOwnver_property_UNIQUE` (`id_owner_property`),
  KEY `owner_idx` (`owner_id`),
  KEY `owner_account_idx` (`account_id`),
  CONSTRAINT `owner` FOREIGN KEY (`owner_id`) REFERENCES `owner` (`id_owner`),
  CONSTRAINT `owner_account` FOREIGN KEY (`account_id`) REFERENCES `account` (`id_account`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `owner_property`
--

LOCK TABLES `owner_property` WRITE;
/*!40000 ALTER TABLE `owner_property` DISABLE KEYS */;
INSERT INTO `owner_property` VALUES (1,'owner',1,1),(2,'user',2,1),(3,'owner',3,2);
/*!40000 ALTER TABLE `owner_property` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-11-24 20:48:12
