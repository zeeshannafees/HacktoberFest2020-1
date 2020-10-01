
-- --------------------------------------------------------

--
-- Table structure for table `DEPARTMENT`
--

CREATE TABLE IF NOT EXISTS `DEPARTMENT` (
  `Dept_Id` int(10) NOT NULL DEFAULT '0',
  `Dept_Name` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`Dept_Id`),FOREIGN KEY (Dept_Id) REFERENCES STUD_MEMBER(Dept_Id)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `DEPARTMENT`
--

INSERT INTO `DEPARTMENT` (`Dept_Id`, `Dept_Name`) VALUES
(1, 'Inforamtion Technology'),
(2, 'Electrical'),
(3, 'Civil'),
(4, 'Mechanical'),
(5, 'Chemical');


