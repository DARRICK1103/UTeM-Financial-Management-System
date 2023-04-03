-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 19, 2023 at 04:08 AM
-- Server version: 10.4.27-MariaDB
-- PHP Version: 8.1.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `fms_w1`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `admin_ID` varchar(5) NOT NULL,
  `admin_name` varchar(50) NOT NULL,
  `admin_email` varchar(50) NOT NULL,
  `admin_contact` varchar(11) NOT NULL,
  `admin_password` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`admin_ID`, `admin_name`, `admin_email`, `admin_contact`, `admin_password`) VALUES
('A0001', 'ALI BIN ALI', 'ali123@gmail.com', '0110001111', '123456'),
('A0002', 'BILLY HII', 'billy123@gmail.com', '0110001112', '123456'),
('A0003', 'CAROL LIM', 'carol123@gmail.com', '0110001113', '123456'),
('A0004', 'DORIS HU', 'doris123@gmail.com', '0110001114', '123456');

-- --------------------------------------------------------

--
-- Table structure for table `faculty`
--

CREATE TABLE `faculty` (
  `faculty_ID` varchar(4) NOT NULL,
  `admin_ID` varchar(5) NOT NULL,
  `faculty_name` varchar(200) NOT NULL,
  `faculty_address` varchar(1000) NOT NULL,
  `faculty_contact` varchar(11) NOT NULL,
  `faculty_balance` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `faculty`
--

INSERT INTO `faculty` (`faculty_ID`, `admin_ID`, `faculty_name`, `faculty_address`, `faculty_contact`, `faculty_balance`) VALUES
('F001', 'A0001', 'Faculty of Electrical Engineering(FKE)', 'Faculty of Electrical Engineering (FKE), Universiti Teknikal Malaysia Melaka (UTeM), Hang Tuah Jaya, 76100 Durian Tunggal, Melaka, Malaysia', '0190001111', 183418),
('F002', 'A0001', 'Faculty of Electronic & Computer Engineering (FKEKK)', 'Faculty of Electronic & Computer Engineering (FKEKK) ,Universiti Teknikal Malaysia Melaka (UTeM),Hang Tuah Jaya, 76100 Durian Tunggal, Melaka, Malaysia', '0190001112', 54304),
('F003', 'A0001', 'Faculty of Mechanical Engineering(FKM)', 'Faculty of Mechanical Engineering(FKM), Jalan TU 62, Taman Tasik Utama, 75450 Ayer Keroh, Melaka', '0190001113', 27857),
('F004', 'A0001', 'Faculty of Manufacturing Engineering(FKP)', 'Faculty of Manufacturing Engineering(FKP) ,Universiti Teknikal Malaysia Melaka (UTeM),Hang Tuah Jaya, 76100 Durian Tunggal, Melaka, Malaysia', '0190001114', 122840),
('F005', 'A0001', 'Faculty of Information & Communication Technology(FTMK)', 'Faculty of Information & Communication Technology(FTMK), Universiti Teknikal Malaysia Melaka, Hang Tuah Jaya, 76100 Durian Tunggal\r\nMelaka, Malaysia', '0190001115', 81377),
('F006', 'A0001', 'Faculty Of Technology Management And Technopreneurship(FPTT)', 'Faculty Of Technology Management And Technopreneurship(FPTT), Jalan TU 62, Taman Tasik Utama, 75450 Ayer Keroh, Melaka', '0190001116', 43610),
('F007', 'A0001', 'Faculty Of Electrical And Electronic Engineering Technology(FTKEE)', 'Faculty Of Electrical And Electronic Engineering Technology(FTKEE), Jalan TU 62, Taman Tasik Utama, 75450 Ayer Keroh, Melaka', '0190001117', 130186),
('F008', 'A0001', 'Faculty Of Mechanical And Manufacturing Engineering Technology(FTKMP)', 'Faculty Of Mechanical And Manufacturing Engineering Technology(FTKMP), Jalan TU 62, Taman Tasik Utama, 75450 Ayer Keroh, Melaka', '0190001118', 31555),
('F009', 'A0001', 'Faculty Of Designer', 'Jalan UTeM', '0127778888', 0);

-- --------------------------------------------------------

--
-- Table structure for table `record_detail`
--

CREATE TABLE `record_detail` (
  `detail_ID` varchar(5) NOT NULL,
  `record_ID` varchar(5) NOT NULL,
  `description` varchar(100) NOT NULL,
  `quantity` int(11) NOT NULL,
  `price` double NOT NULL,
  `transaction_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `record_detail`
--

INSERT INTO `record_detail` (`detail_ID`, `record_ID`, `description`, `quantity`, `price`, `transaction_date`) VALUES
('D0001', 'R0001', '2022 Budget', 1, 250000, '2022-01-01'),
('D0002', 'R0002', 'Sponsorship from Datuk Ali', 1, 10000, '2022-02-09'),
('D0003', 'R0003', 'PROGRAM MELAWAT KE UM (100 Students)', 100, 150, '2022-10-12'),
('D0004', 'R0004', 'Rent Lab1 for 1 day', 1, 250, '2021-11-16'),
('D0005', 'R0005', 'Water Bills for December', 1, 550, '2022-12-31'),
('D0006', 'R0006', 'Utility Bills for December', 1, 9000, '2022-12-31'),
('D0007', 'R0007', 'Computer Repairment', 5, 200, '2022-12-21'),
('D0008', 'R0008', 'Water Bills for November', 1, 579, '2022-11-30'),
('D0009', 'R0009', 'Utility Bills for November', 1, 11234, '2022-11-30'),
('D0010', 'R0010', 'Invitation speaker Dr Yong', 1, 500, '2022-12-28'),
('D0011', 'R0011', 'Water Bills for October', 1, 678, '2022-12-29'),
('D0012', 'R0012', 'Utility Bills for October', 1, 10345, '2022-12-29'),
('D0013', 'R0013', 'Water Bills for July, Ogos, September', 1, 1888, '2022-12-29'),
('D0014', 'R0014', 'Utility Bills for July, Ogos, September', 1, 32450, '2022-12-29'),
('D0015', 'R0015', 'Invite speaker ', 1, 500, '2022-12-29'),
('D0016', 'R0016', 'From Mogan Lee', 1, 30000, '2023-01-06'),
('D0017', 'R0017', 'Program Robotic', 50, 100, '2023-01-06'),
('D0018', 'R0018', 'Buy New Computers', 2, 3520, '2023-01-06'),
('D0019', 'R0019', 'Water Bills for December', 1, 489, '2022-12-31'),
('D0020', 'R0020', 'Utility Bills for December', 1, 9877, '2022-12-31'),
('D0021', 'R0021', 'Budget 2022', 1, 30000, '2022-01-02'),
('D0022', 'R0022', 'Budget 2023', 1, 50000, '2023-01-16'),
('D0023', 'R0023', 'Water Bills for 2021', 12, 498, '2021-12-31'),
('D0024', 'R0024', 'Utility Bills 2021', 12, 897, '2021-12-31'),
('D0025', 'R0025', 'Install New Coway Water Filter', 3, 3900, '2023-01-16'),
('D0026', 'R0026', 'Bantuan Pelajar B40', 100, 100, '2023-01-16'),
('D0027', 'R0027', 'Bantuan Murid Miskin', 100, 150, '2022-01-16'),
('D0028', 'R0028', 'Sponsorhip From Dr Alex', 1, 3500, '2023-01-16'),
('D0029', 'R0029', 'The Night', 100, 150, '2022-01-16'),
('D0030', 'R0030', 'Rent Labs', 5, 250, '2023-01-16'),
('D0031', 'R0031', 'Water Bills for 2022', 12, 529, '2022-12-31'),
('D0032', 'R0032', 'Utility Bills 2022', 12, 896, '2022-12-31'),
('D0033', 'R0033', 'Budget 2021', 1, 25000, '2021-01-16'),
('D0034', 'R0034', 'Budget 2022', 1, 15000, '2022-01-16'),
('D0035', 'R0035', 'Budget 2023', 1, 30000, '2023-01-16'),
('D0036', 'R0036', 'Water bills 2021', 12, 345, '2021-12-31'),
('D0037', 'R0037', 'Water Bills 2022', 12, 300, '2022-12-31'),
('D0038', 'R0038', 'Water Bills 2023', 12, 350, '2023-01-16'),
('D0039', 'R0039', 'Utility Bills 2021', 12, 781, '2021-12-31'),
('D0040', 'R0040', 'Utility Bills 2022', 1, 689, '2022-12-31'),
('D0041', 'R0041', 'Utility Bills January 2023', 1, 867, '2023-01-16'),
('D0042', 'R0042', 'Repairment', 50, 279, '2023-01-16'),
('D0043', 'R0043', 'Laptop Repair', 5, 900, '2023-01-16'),
('D0044', 'R0044', 'Invite International Speaker', 3, 800, '2022-01-16'),
('D0045', 'R0045', 'Sponsorship from Mr Lee', 1, 5000, '2023-01-16'),
('D0046', 'R0046', 'Talent Night', 30, 100, '2021-01-16'),
('D0047', 'R0047', '10 labs', 10, 250, '2023-01-16'),
('D0049', 'R0049', 'Invitation International Speakers', 5, 900, '2023-01-16'),
('D0050', 'R0050', 'Construction A New Building', 1, 35000, '2023-01-16'),
('D0051', 'R0051', 'Labs Rental In 2021', 100, 250, '2021-12-31'),
('D0052', 'R0052', 'Lab Rental in 2022', 30, 250, '2022-12-31'),
('D0053', 'R0053', 'Water Bills 2021', 12, 469, '2021-12-31'),
('D0054', 'R0054', 'Utility Bills 2021', 12, 1098, '2021-12-31'),
('D0055', 'R0055', 'Water Bills 2022', 12, 567, '2022-12-31'),
('D0056', 'R0056', 'Budget 2021', 1, 30000, '2021-01-16'),
('D0057', 'R0057', 'Utility Bills 2022', 12, 987, '2022-12-31'),
('D0058', 'R0058', 'Water Bills January 2023', 1, 578, '2023-01-16'),
('D0059', 'R0059', 'Utility Bills Janaury 2023', 1, 895, '2023-01-16'),
('D0060', 'R0060', 'Budget 2021', 1, 20000, '2021-01-16'),
('D0061', 'R0061', 'Budget 2022', 1, 25000, '2022-01-16'),
('D0062', 'R0062', 'Budget 2023', 1, 30000, '2023-01-16'),
('D0063', 'R0063', 'Water Bills 2021', 12, 398, '2021-01-16'),
('D0064', 'R0064', 'Water Bills 2022', 12, 468, '2022-01-16'),
('D0065', 'R0065', 'Water Bills 2023 January', 1, 754, '2023-01-16'),
('D0066', 'R0066', 'Sponsorship From Mr Wong', 1, 7000, '2023-01-16'),
('D0067', 'R0067', 'Utility Bills 2021', 12, 1190, '2021-12-31'),
('D0068', 'R0068', 'Utility Bills 2022', 12, 1236, '2022-12-31'),
('D0069', 'R0069', 'Repairment Laptop', 20, 900, '2022-01-16'),
('D0070', 'R0070', 'Invitation International Speakers', 5, 700, '2022-01-16'),
('D0071', 'R0071', 'Program Exchange Students', 30, 3000, '2022-11-30'),
('D0072', 'R0072', 'Lab Rental 2021', 19, 250, '2021-12-31'),
('D0073', 'R0073', 'Lab Rental 2022', 26, 273, '2022-12-31'),
('D0074', 'R0074', 'Lab Rental January 2023', 3, 250, '2023-01-16'),
('D0075', 'R0075', 'Budget 2021', 1, 30000, '2021-01-16'),
('D0076', 'R0076', 'Budget 2022', 1, 25000, '2022-01-16'),
('D0077', 'R0077', 'Budget 2023', 1, 30000, '2023-01-16'),
('D0078', 'R0078', 'Water Bills 2021', 12, 689, '2021-12-31'),
('D0079', 'R0079', 'Water Bills 2022', 12, 489, '2022-12-31'),
('D0080', 'R0080', 'Water Bills 2023 January', 1, 500, '2023-01-16'),
('D0081', 'R0081', 'Utility Bills 2021', 12, 899, '2021-12-31'),
('D0082', 'R0082', 'Utility Bills 2022', 12, 1000, '2022-12-31'),
('D0083', 'R0083', 'Utility Bills January 2023', 1, 1199, '2023-01-16'),
('D0084', 'R0084', 'Buy Robotic Materials', 30, 1000, '2023-01-16'),
('D0085', 'R0085', 'Invitation Speaker', 1, 2000, '2023-01-16'),
('D0086', 'R0086', 'Sponsorship From Datuk Lee', 1, 10000, '2023-01-16'),
('D0087', 'R0087', 'Program Exchange Students', 15, 3000, '2023-01-16'),
('D0088', 'R0088', 'Lab Rental 2021', 20, 250, '2021-12-31'),
('D0089', 'R0089', 'Lab Rental 2022', 28, 250, '2022-12-31'),
('D0090', 'R0090', 'Budget 2021', 1, 25000, '2021-01-16'),
('D0091', 'R0091', 'Budget 2022', 1, 50000, '2022-01-16'),
('D0092', 'R0092', 'Water Bills 2021', 12, 789, '2021-12-31'),
('D0093', 'R0093', 'Water Bills 2022', 12, 689, '2022-12-31'),
('D0094', 'R0094', 'Water Bills January 2023', 1, 698, '2023-01-16'),
('D0095', 'R0095', 'Utility Bills 2021', 12, 1390, '2021-12-31'),
('D0096', 'R0096', 'Utility Bills 2022', 12, 1398, '2022-12-31'),
('D0097', 'R0097', 'Repairment Chair', 90, 100, '2023-01-16'),
('D0098', 'R0098', 'Bantuan Pelajar', 20, 500, '2022-01-16'),
('D0099', 'R0099', 'Sponsorship Dr Freedy', 1, 10000, '2022-01-16'),
('D0100', 'R0100', 'Program Excahnge Students', 10, 5000, '2023-01-16'),
('D0101', 'R0101', 'Lecture Hall Rental 2021', 50, 300, '2021-12-31'),
('D0102', 'R0102', 'Lecture Hall Rental 2022', 70, 350, '2022-12-31'),
('D0103', 'R0103', 'Build New Classroom', 2, 30000, '2022-01-16'),
('D0104', 'R0104', 'Budget 2021', 1, 35000, '2021-12-31'),
('D0105', 'R0105', 'Budget 2022', 1, 38000, '2022-12-31'),
('D0106', 'R0106', 'Sponsorship From Datuk Lee', 1, 30000, '2022-01-16'),
('D0107', 'R0107', 'Program Exchange Students', 50, 3500, '2022-01-16'),
('D0108', 'R0108', 'Lab Rental Fees 2021', 20, 350, '2021-12-31'),
('D0109', 'R0109', 'Lab Rental 2022', 38, 280, '2022-12-31'),
('D0110', 'R0110', 'Water Bills 2021', 12, 698, '2021-12-31'),
('D0111', 'R0111', 'Water Bills 2022', 12, 712, '2022-12-31'),
('D0112', 'R0112', 'Maintenance Fees 2022', 12, 9567, '2022-01-16'),
('D0113', 'R0113', 'Utility Bills 2021', 12, 1267, '2021-12-31'),
('D0114', 'R0114', 'Utility Bills 2022', 12, 984, '2022-12-31'),
('D0115', 'R0115', 'Water Bills January 2023', 1, 450, '2023-01-16'),
('D0116', 'R0116', 'Utility Bills January 2023', 1, 1268, '2023-01-16'),
('D0117', 'R0117', 'Invitation Speaker', 10, 500, '2023-01-16'),
('D0118', 'R0118', 'Budget 2021', 1, 25000, '2021-01-16'),
('D0119', 'R0119', 'Budget 2022', 1, 30000, '2022-01-16'),
('D0120', 'R0120', 'Sponsorship From Datuk Yii', 1, 30000, '2023-01-16'),
('D0121', 'R0121', 'Lab Rental 2021', 30, 260, '2021-01-16'),
('D0122', 'R0122', 'Lab Rental 2022', 39, 280, '2022-01-16'),
('D0123', 'R0123', 'Talent Show', 39, 100, '2022-01-16'),
('D0124', 'R0124', 'World Cup 2023', 350, 1, '2023-01-16'),
('D0125', 'R0125', 'Water Bills 2021', 12, 350, '2021-12-31'),
('D0126', 'R0126', 'Water Bills 2022', 12, 520, '2022-12-31'),
('D0127', 'R0127', 'Water Bills January 2023', 1, 489, '2023-01-16'),
('D0128', 'R0128', 'Utility Bills 2021', 12, 1299, '2021-12-31'),
('D0129', 'R0129', 'Utility Bills 2022', 12, 1350, '2022-12-31'),
('D0130', 'R0130', 'Utility Bills January 2023', 1, 1198, '2023-01-16'),
('D0131', 'R0131', 'Construction of New Building', 1, 30000, '2023-01-16'),
('D0132', 'R0132', 'Invitation of Speaker', 3, 500, '2022-01-16'),
('D0133', 'R0133', 'Invitation Speaker Dr Rachel', 1, 1000, '2021-01-16'),
('D0134', 'R0134', 'Budget 2021', 1, 20000, '2021-01-01'),
('D0135', 'R0135', 'Utility Bills 2021', 12, 1290, '2021-12-31'),
('D0136', 'R0136', 'Water Bills 2021', 12, 678, '2021-12-31'),
('D0137', 'R0137', 'Invitation Speaker', 2, 500, '2021-11-16'),
('D0138', 'R0138', 'Invitation Speaker', 1, 100, '2023-01-16');

-- --------------------------------------------------------

--
-- Table structure for table `staff`
--

CREATE TABLE `staff` (
  `staff_ID` varchar(5) NOT NULL,
  `admin_ID` varchar(5) NOT NULL,
  `faculty_ID` varchar(4) NOT NULL,
  `staff_name` varchar(50) NOT NULL,
  `staff_email` varchar(50) NOT NULL,
  `staff_contact` varchar(11) NOT NULL,
  `staff_password` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `staff`
--

INSERT INTO `staff` (`staff_ID`, `admin_ID`, `faculty_ID`, `staff_name`, `staff_email`, `staff_contact`, `staff_password`) VALUES
('S0001', 'A0001', 'F001', 'ALICE LAU', 'alice123@gmail.com', '0120001111', '123456'),
('S0002', 'A0001', 'F002', 'BONNY SIA', 'bonny123@gmail.com', '0120001112', '123456'),
('S0003', 'A0002', 'F003', 'CHRIS PAUL', 'chris123@gmail.com', '0120001113', '123456'),
('S0004', 'A0002', 'F004', 'DERRICK ROSE', 'derrick123@gmail.com', '0120001114', '123456'),
('S0005', 'A0003', 'F005', 'EILEEN WONG', 'eileen123@gmail.com', '0120001115', '123456'),
('S0006', 'A0003', 'F006', 'FION TANG', 'fion123@gmail.com', '0120001116', '123456'),
('S0007', 'A0004', 'F007', 'GINA YII', 'gina123@gmail.com', '0120001117', '123456'),
('S0008', 'A0004', 'F008', 'HENRY LAU', 'henry123@gmail.com', '0120001118', '123456');

-- --------------------------------------------------------

--
-- Table structure for table `transaction_record`
--

CREATE TABLE `transaction_record` (
  `record_ID` varchar(5) NOT NULL,
  `staff_ID` varchar(5) NOT NULL,
  `record_name` varchar(30) NOT NULL,
  `type` varchar(6) NOT NULL,
  `total` double DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `transaction_record`
--

INSERT INTO `transaction_record` (`record_ID`, `staff_ID`, `record_name`, `type`, `total`) VALUES
('R0001', 'S0001', 'BUDGET FROM UTeM', 'DEBIT', 250000),
('R0002', 'S0001', 'SPONSORSHIP', 'DEBIT', 10000),
('R0003', 'S0001', 'STUDENT FEES', 'DEBIT', 15000),
('R0004', 'S0001', 'LAB RENTAL FEES', 'DEBIT', 250),
('R0005', 'S0001', 'WATER BILLS', 'CREDIT', 550),
('R0006', 'S0001', 'UTILITY BILLS', 'CREDIT', 9000),
('R0007', 'S0001', 'MAINTENANCE FEES', 'CREDIT', 1000),
('R0008', 'S0001', 'WATER BILLS', 'CREDIT', 579),
('R0009', 'S0001', 'UTILITY BILLS', 'CREDIT', 11234),
('R0010', 'S0001', 'OTHER FEES', 'CREDIT', 500),
('R0011', 'S0001', 'WATER BILLS', 'CREDIT', 678),
('R0012', 'S0001', 'UTILITY BILLS', 'CREDIT', 10345),
('R0013', 'S0001', 'WATER BILLS', 'CREDIT', 1888),
('R0014', 'S0001', 'UTILITY BILLS', 'CREDIT', 32450),
('R0015', 'S0001', 'SPONSORSHIP', 'DEBIT', 500),
('R0016', 'S0002', 'SPONSORSHIP', 'DEBIT', 30000),
('R0017', 'S0002', 'STUDENT FEES', 'DEBIT', 5000),
('R0018', 'S0002', 'MAINTENANCE FEES', 'CREDIT', 7040),
('R0019', 'S0002', 'WATER BILLS', 'CREDIT', 489),
('R0020', 'S0002', 'UTILITY BILLS', 'CREDIT', 9877),
('R0021', 'S0002', 'BUDGET FROM UTeM', 'DEBIT', 30000),
('R0022', 'S0002', 'BUDGET FROM UTeM', 'DEBIT', 50000),
('R0023', 'S0002', 'WATER BILLS', 'CREDIT', 5976),
('R0024', 'S0002', 'UTILITY BILLS', 'CREDIT', 10764),
('R0025', 'S0002', 'MAINTENANCE FEES', 'CREDIT', 11700),
('R0026', 'S0002', 'OTHER FEES', 'CREDIT', 10000),
('R0027', 'S0002', 'OTHER FEES', 'CREDIT', 15000),
('R0028', 'S0002', 'SPONSORSHIP', 'DEBIT', 3500),
('R0029', 'S0002', 'STUDENT FEES', 'DEBIT', 15000),
('R0030', 'S0002', 'LAB RENTAL FEES', 'DEBIT', 1250),
('R0031', 'S0002', 'WATER BILLS', 'CREDIT', 6348),
('R0032', 'S0002', 'UTILITY BILLS', 'CREDIT', 10752),
('R0033', 'S0003', 'BUDGET FROM UTeM', 'DEBIT', 25000),
('R0034', 'S0003', 'BUDGET FROM UTeM', 'DEBIT', 15000),
('R0035', 'S0003', 'BUDGET FROM UTeM', 'DEBIT', 30000),
('R0036', 'S0003', 'WATER BILLS', 'CREDIT', 4140),
('R0037', 'S0003', 'UTILITY BILLS', 'CREDIT', 3600),
('R0038', 'S0003', 'WATER BILLS', 'CREDIT', 4200),
('R0039', 'S0003', 'UTILITY BILLS', 'CREDIT', 9372),
('R0040', 'S0003', 'UTILITY BILLS', 'CREDIT', 689),
('R0041', 'S0003', 'UTILITY BILLS', 'CREDIT', 867),
('R0042', 'S0003', 'MAINTENANCE FEES', 'CREDIT', 13950),
('R0043', 'S0003', 'MAINTENANCE FEES', 'CREDIT', 4500),
('R0044', 'S0003', 'OTHER FEES', 'CREDIT', 2400),
('R0045', 'S0003', 'SPONSORSHIP', 'DEBIT', 5000),
('R0046', 'S0003', 'STUDENT FEES', 'DEBIT', 3000),
('R0047', 'S0003', 'LAB RENTAL FEES', 'DEBIT', 2500),
('R0048', 'S0003', 'LAB RENTAL FEES', 'DEBIT', NULL),
('R0049', 'S0001', 'OTHER FEES', 'CREDIT', 4500),
('R0050', 'S0001', 'MAINTENANCE FEES', 'CREDIT', 35000),
('R0051', 'S0001', 'LAB RENTAL FEES', 'DEBIT', 25000),
('R0052', 'S0002', 'LAB RENTAL FEES', 'DEBIT', 7500),
('R0053', 'S0003', 'WATER BILLS', 'CREDIT', 5628),
('R0054', 'S0003', 'UTILITY BILLS', 'CREDIT', 13176),
('R0055', 'S0003', 'WATER BILLS', 'CREDIT', 6804),
('R0056', 'S0003', 'BUDGET FROM UTeM', 'DEBIT', 30000),
('R0057', 'S0003', 'UTILITY BILLS', 'CREDIT', 11844),
('R0058', 'S0003', 'WATER BILLS', 'CREDIT', 578),
('R0059', 'S0003', 'UTILITY BILLS', 'CREDIT', 895),
('R0060', 'S0004', 'BUDGET FROM UTeM', 'DEBIT', 20000),
('R0061', 'S0004', 'BUDGET FROM UTeM', 'DEBIT', 25000),
('R0062', 'S0004', 'BUDGET FROM UTeM', 'DEBIT', 30000),
('R0063', 'S0004', 'WATER BILLS', 'CREDIT', 4776),
('R0064', 'S0004', 'WATER BILLS', 'CREDIT', 5616),
('R0065', 'S0004', 'WATER BILLS', 'CREDIT', 754),
('R0066', 'S0004', 'SPONSORSHIP', 'DEBIT', 7000),
('R0067', 'S0004', 'UTILITY BILLS', 'CREDIT', 14280),
('R0068', 'S0004', 'UTILITY BILLS', 'CREDIT', 14832),
('R0069', 'S0004', 'MAINTENANCE FEES', 'CREDIT', 18000),
('R0070', 'S0004', 'OTHER FEES', 'CREDIT', 3500),
('R0071', 'S0004', 'STUDENT FEES', 'DEBIT', 90000),
('R0072', 'S0004', 'LAB RENTAL FEES', 'DEBIT', 4750),
('R0073', 'S0004', 'LAB RENTAL FEES', 'DEBIT', 7098),
('R0074', 'S0004', 'LAB RENTAL FEES', 'DEBIT', 750),
('R0075', 'S0005', 'BUDGET FROM UTeM', 'DEBIT', 30000),
('R0076', 'S0005', 'BUDGET FROM UTeM', 'DEBIT', 25000),
('R0077', 'S0005', 'BUDGET FROM UTeM', 'DEBIT', 30000),
('R0078', 'S0005', 'WATER BILLS', 'CREDIT', 8268),
('R0079', 'S0005', 'WATER BILLS', 'CREDIT', 5868),
('R0080', 'S0005', 'WATER BILLS', 'CREDIT', 500),
('R0081', 'S0005', 'UTILITY BILLS', 'CREDIT', 10788),
('R0082', 'S0005', 'UTILITY BILLS', 'CREDIT', 12000),
('R0083', 'S0005', 'WATER BILLS', 'CREDIT', 1199),
('R0084', 'S0005', 'MAINTENANCE FEES', 'CREDIT', 30000),
('R0085', 'S0005', 'OTHER FEES', 'CREDIT', 2000),
('R0086', 'S0005', 'SPONSORSHIP', 'DEBIT', 10000),
('R0087', 'S0005', 'STUDENT FEES', 'DEBIT', 45000),
('R0088', 'S0005', 'LAB RENTAL FEES', 'DEBIT', 5000),
('R0089', 'S0005', 'LAB RENTAL FEES', 'DEBIT', 7000),
('R0090', 'S0006', 'BUDGET FROM UTeM', 'DEBIT', 25000),
('R0091', 'S0006', 'BUDGET FROM UTeM', 'DEBIT', 50000),
('R0092', 'S0006', 'WATER BILLS', 'CREDIT', 9468),
('R0093', 'S0006', 'WATER BILLS', 'CREDIT', 8268),
('R0094', 'S0006', 'WATER BILLS', 'CREDIT', 698),
('R0095', 'S0006', 'UTILITY BILLS', 'CREDIT', 16680),
('R0096', 'S0006', 'UTILITY BILLS', 'CREDIT', 16776),
('R0097', 'S0006', 'MAINTENANCE FEES', 'CREDIT', 9000),
('R0098', 'S0006', 'OTHER FEES', 'CREDIT', 10000),
('R0099', 'S0006', 'SPONSORSHIP', 'DEBIT', 10000),
('R0100', 'S0006', 'STUDENT FEES', 'DEBIT', 50000),
('R0101', 'S0006', 'LAB RENTAL FEES', 'DEBIT', 15000),
('R0102', 'S0006', 'LAB RENTAL FEES', 'DEBIT', 24500),
('R0103', 'S0006', 'MAINTENANCE FEES', 'CREDIT', 60000),
('R0104', 'S0007', 'BUDGET FROM UTeM', 'DEBIT', 35000),
('R0105', 'S0007', 'BUDGET FROM UTeM', 'DEBIT', 38000),
('R0106', 'S0007', 'SPONSORSHIP', 'DEBIT', 30000),
('R0107', 'S0007', 'STUDENT FEES', 'DEBIT', 175000),
('R0108', 'S0007', 'LAB RENTAL FEES', 'DEBIT', 7000),
('R0109', 'S0007', 'LAB RENTAL FEES', 'DEBIT', 10640),
('R0110', 'S0007', 'WATER BILLS', 'CREDIT', 8376),
('R0111', 'S0007', 'WATER BILLS', 'CREDIT', 8544),
('R0112', 'S0007', 'MAINTENANCE FEES', 'CREDIT', 114804),
('R0113', 'S0007', 'UTILITY BILLS', 'CREDIT', 15204),
('R0114', 'S0007', 'UTILITY BILLS', 'CREDIT', 11808),
('R0115', 'S0007', 'WATER BILLS', 'CREDIT', 450),
('R0116', 'S0007', 'UTILITY BILLS', 'CREDIT', 1268),
('R0117', 'S0007', 'OTHER FEES', 'CREDIT', 5000),
('R0118', 'S0008', 'BUDGET FROM UTeM', 'DEBIT', 25000),
('R0119', 'S0008', 'BUDGET FROM UTeM', 'DEBIT', 30000),
('R0120', 'S0008', 'SPONSORSHIP', 'DEBIT', 30000),
('R0121', 'S0008', 'LAB RENTAL FEES', 'DEBIT', 7800),
('R0122', 'S0008', 'LAB RENTAL FEES', 'DEBIT', 10920),
('R0123', 'S0008', 'STUDENT FEES', 'DEBIT', 3900),
('R0124', 'S0008', 'STUDENT FEES', 'DEBIT', 350),
('R0125', 'S0008', 'WATER BILLS', 'CREDIT', 4200),
('R0126', 'S0008', 'WATER BILLS', 'CREDIT', 6240),
('R0127', 'S0008', 'WATER BILLS', 'CREDIT', 489),
('R0128', 'S0008', 'UTILITY BILLS', 'CREDIT', 15588),
('R0129', 'S0008', 'UTILITY BILLS', 'CREDIT', 16200),
('R0130', 'S0008', 'UTILITY BILLS', 'CREDIT', 1198),
('R0131', 'S0008', 'MAINTENANCE FEES', 'CREDIT', 30000),
('R0132', 'S0008', 'OTHER FEES', 'CREDIT', 1500),
('R0133', 'S0008', 'OTHER FEES', 'CREDIT', 1000),
('R0134', 'S0001', 'BUDGET FROM UTeM', 'DEBIT', 20000),
('R0135', 'S0001', 'UTILITY BILLS', 'CREDIT', 15480),
('R0136', 'S0001', 'WATER BILLS', 'CREDIT', 8136),
('R0137', 'S0001', 'OTHER FEES', 'CREDIT', 1000),
('R0138', 'S0001', 'STUDENT FEES', 'DEBIT', 100);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`admin_ID`);

--
-- Indexes for table `faculty`
--
ALTER TABLE `faculty`
  ADD PRIMARY KEY (`faculty_ID`),
  ADD KEY `Faculty_Admin_FK` (`admin_ID`);

--
-- Indexes for table `record_detail`
--
ALTER TABLE `record_detail`
  ADD PRIMARY KEY (`detail_ID`),
  ADD KEY `Detail_Record_PK` (`record_ID`);

--
-- Indexes for table `staff`
--
ALTER TABLE `staff`
  ADD PRIMARY KEY (`staff_ID`),
  ADD KEY `Staff_Admin_FK` (`admin_ID`),
  ADD KEY `Staff_Faculty_FK` (`faculty_ID`);

--
-- Indexes for table `transaction_record`
--
ALTER TABLE `transaction_record`
  ADD PRIMARY KEY (`record_ID`),
  ADD KEY `Record_Staff_FK` (`staff_ID`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `faculty`
--
ALTER TABLE `faculty`
  ADD CONSTRAINT `Faculty_Admin_FK` FOREIGN KEY (`admin_ID`) REFERENCES `admin` (`admin_ID`);

--
-- Constraints for table `record_detail`
--
ALTER TABLE `record_detail`
  ADD CONSTRAINT `Detail_Record_PK` FOREIGN KEY (`record_ID`) REFERENCES `transaction_record` (`record_ID`);

--
-- Constraints for table `staff`
--
ALTER TABLE `staff`
  ADD CONSTRAINT `Staff_Admin_FK` FOREIGN KEY (`admin_ID`) REFERENCES `admin` (`admin_ID`),
  ADD CONSTRAINT `Staff_Faculty_FK` FOREIGN KEY (`faculty_ID`) REFERENCES `faculty` (`faculty_ID`);

--
-- Constraints for table `transaction_record`
--
ALTER TABLE `transaction_record`
  ADD CONSTRAINT `Record_Staff_FK` FOREIGN KEY (`staff_ID`) REFERENCES `staff` (`staff_ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
