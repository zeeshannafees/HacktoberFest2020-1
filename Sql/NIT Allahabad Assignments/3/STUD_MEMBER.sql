
CREATE TABLE IF NOT EXISTS `STUD_MEMBER` (
  `Roll_No` int(20) NOT NULL,
  `F_Name` varchar(20) NOT NULL,
  `M_Name` varchar(20) NOT NULL,
  `S_Name` varchar(20) NOT NULL,
  `Dept_Id` int(20) NOT NULL,
  `Semester` varchar(20) NOT NULL,
  `Contact_No` varchar(40) NOT NULL,
  `Gender` text NOT NULL,
  PRIMARY KEY (`Roll_No`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `STUD_MEMBER`
--

INSERT INTO `STUD_MEMBER` (`Roll_No`, `F_Name`, `M_Name`, `S_Name`, `Dept_Id`, `Semester`, `Contact_No`, `Gender`) VALUES
(1, 'Ankur', 'Samir', 'Kahar', 1, '1', '272121', 'M'),
(2, 'Dhaval', 'Dhiren', 'Joshi', 1, '1', '232122', 'M'),
(3, 'Ankita', 'BIREN', 'SHAH', 1, '1', '112121', 'F'),
(10, 'KOMAL', 'MAHESKUMAR', 'PANDEY', 2, '3', '123123', 'F'),
(13, 'AMIT', 'JITENKUMAR', 'MEHTA', 3, '3', '453667', 'M'),
(23, 'JINAL', 'ASHISH', 'GANDHI', 2, '1', '323232', 'M'),
(22, 'GANESH', 'ASHA', 'PATEL', 2, '3', '124244', 'M'),
(4, 'SHWETA', 'MIHIR', 'PATEL', 3, '1', '646342', 'F'),
(7, 'POOJA', 'MAYANK', 'DESAI', 3, '3', '328656', 'F'),
(8, 'KOMAL', 'KRISHNARAJ', 'BHATIA', 2, '3', '257422', 'F'),
(43, 'KIRAN', 'VIRAJ', 'SHAH', 1, '1', '754124', 'F');


