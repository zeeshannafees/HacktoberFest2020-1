

-- --------------------------------------------------------

--
-- Table structure for table `products`
--

CREATE TABLE IF NOT EXISTS `products` (
  `Product_id` varchar(255) NOT NULL,
  `OrderId` int(11) NOT NULL,
  `Manufacture_Date` date DEFAULT NULL,
  `Raw_Material` varchar(255) DEFAULT NULL,
  `Vendor_Id` int(11) DEFAULT NULL,
  PRIMARY KEY (`Product_id`),
  KEY `OrderId` (`OrderId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `products`
--

INSERT INTO `products` (`Product_id`, `OrderId`, `Manufacture_Date`, `Raw_Material`, `Vendor_Id`) VALUES
('AZ145', 2, '2005-12-23', 'Steel', 1),
('CS784', 4, '2005-11-28', 'Plastic', 2),
('AZ147', 6, '2002-08-15', 'Steel', 3),
('FD344', 3, '2005-11-03', 'Milk', 1),
('GR233', 3, '2005-11-30', 'Pulses', 2),
('FD123', 2, '2005-10-03', 'Milk', 2),
('CS783', 1, '2004-11-03', 'Plastic', 2),
('CS435', 5, '2001-11-04', 'Steel', 1),
('GR567', 6, '2005-09-03', 'Pulses', 2),
('FD267', 5, '2002-03-21', 'Bread', 4),
('FD333', 9, '2001-12-12', 'Milk', 1);

-- --------------------------------------------------------

--
-- Table structure for table `sales`
--

CREATE TABLE IF NOT EXISTS `sales` (
  `OrderID` int(11) NOT NULL AUTO_INCREMENT,
  `OrderDate` date DEFAULT NULL,
  `OrderPrice` int(11) DEFAULT NULL,
  `OrderQuantity` int(11) DEFAULT NULL,
  `CustomerName` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`OrderID`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10 ;

--
-- Dumping data for table `sales`
--

INSERT INTO `sales` (`OrderID`, `OrderDate`, `OrderPrice`, `OrderQuantity`, `CustomerName`) VALUES
(1, '2005-12-22', 160, 2, 'Smith'),
(2, '2005-08-10', 190, 2, 'Johnson'),
(3, '2005-07-13', 500, 5, 'Baldwin'),
(4, '2005-07-15', 420, 2, 'Smith'),
(5, '2005-12-22', 1000, 4, 'Wood'),
(6, '2005-10-02', 820, 4, 'Smith'),
(7, '2005-11-03', 2000, 2, 'Baldwin'),
(8, '2002-12-22', 1000, 4, 'Wood'),
(9, '2004-12-29', 5000, 4, 'Smith');

-- --------------------------------------------------------


-- --------------------------------------------------------

--
-- Table structure for table `Vendors`
--

CREATE TABLE IF NOT EXISTS `Vendors` (
  `Raw_material` varchar(255) DEFAULT NULL,
  `Vendors` varchar(255) DEFAULT NULL,
  `Vendor_id` int(11) DEFAULT NULL,
  KEY `Vendor_id` (`Vendor_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Vendors`
--

INSERT INTO `Vendors` (`Raw_material`, `Vendors`, `Vendor_id`) VALUES
('Steel', 'Smith', 1),
('Plastic', 'Wills', 2),
('Steel', 'Johnson', 3),
('Milk', 'Smith', 1),
('Pulses', 'Wills', 2),
('Bread', 'Roger', 4),
('Bread', 'Wills', 2),
('Milk', 'Wills', 2),
('Milk', 'Wills', 2);

-- --------------------------------------------------------

--
-- Table structure for table `Vendor_info`
--

CREATE TABLE IF NOT EXISTS `Vendor_info` (
  `Vendor_id` int(11) DEFAULT NULL,
  `Vendor_name` varchar(255) DEFAULT NULL,
  KEY `Vendor_id` (`Vendor_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Vendor_info`
--

INSERT INTO `Vendor_info` (`Vendor_id`, `Vendor_name`) VALUES
(1, 'Smith'),
(2, 'Wills'),
(3, 'Johnson'),
(4, 'Roger');


