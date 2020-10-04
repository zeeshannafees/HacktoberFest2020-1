use db20178057;
--
-- Question 1:-
--1.1 Display the names and contact number of all student member
select F_Name,Contact_No from STUD_MEMBER;
--1.2 Give the names and roll numbers of all students of information technology.
select F_Name,Roll_No from STUD_MEMBER,DEPARTMENT where STUD_MEMBER.Dept_ID=DEPARTMENT.Dept_ID and DEPARTMENT.Dept_Name='IT';
--1.3 Display the department names whose students are present in student member.
select DISTINCT Dept_Name from DEPARTMENT,STUD_MEMBER where STUD_MEMBER.Dept_ID=DEPARTMENT.Dept_ID;
--1.4 Display the department names where no student information is available.
SELECT DISTINCT DEPARTMENT.Dept_Name FROM DEPARTMENT WHERE DEPARTMENT.Dept_Id NOT IN (SELECT DISTINCT Dept_Id FROM STUD_MEMBER);
--1.5 Display the names of all departments.
select Dept_Name from DEPARTMENT;
--1.6 Find the names of students of electrical department who are the members
select F_Name from STUD_MEMBER,DEPARTMENT where STUD_MEMBER.Dept_ID=DEPARTMENT.Dept_ID and DEPARTMENT.Dept_Name='Electrical';
--1.7 Display the information of students members whose names begin with the letter A
select F_Name from STUD_MEMBER where F_Name LIKE 'A%';
--1.8 Display all the details of male members only
select * from STUD_MEMBER where Gender='M';
--1.9 Display the data of student members who are currently in semester 3
select * from STUD_MEMBER where Semester=3;
--1.10 Display the data of student female member in alphabetic order
select * from STUD_MEMBER where Gender='F' order by F_Name;

--
--Question 2:-
--
--1. Display product information which is ordered in the same year as its manufacturing year.
select * from products,sales where sales.OrderID=products.OrderID and year(OrderDate)=year(Manufacture_Date);
--2. Display product information which is ordered in the same year of its manufacturing year and where vendor is “smith‟.
select * from products,sales,Vendor_info where sales.OrderID=products.OrderID and year(OrderDate)=year(Manufacture_Date) and products.Vendor_Id=Vendor_info.Vendor_Id and Vendor_info.Vendor_Name='Smith';
--3. Display total no. of orders placed in each year.
select year(OrderDate),SUM(OrderQuantity) from sales group by year(Orderdate);
--4. Display total no. of orders placed in each year by vendor Wills.
select year(OrderDate),SUM(OrderQuantity) from sales,products,Vendor_info where sales.OrderId=products.OrderId and products.Vendor_Id=Vendor_info.Vendor_id and Vendor_name='Wills' group by year(Orderdate) ;
--5. Display the name of all those persons who are vendors and customers both.
select DISTINCT CustomerName from sales,Vendor_info where CustomerName=Vendor_Name;
--6. Display total no. of food items ordered every year.
select year(OrderDate),SUM(OrderQuantity) from sales,products where sales.OrderID=products.OrderId and products.Raw_Material IN ("Milk","Pulses","Bread") group by year(OrderDate);
--7. Display total no. of food items ordered every year made from Bread.
select year(OrderDate),SUM(OrderQuantity) from sales,products where sales.OrderID=products.OrderId and products.Raw_Material IN ("Bread") group by year(OrderDate);
--8. Display list of product_id whose vendor and customer is different.

--9. Display all those customers who are ordering milk products by smith.
select CustomerName from sales,products,Vendor_info where sales.OrderID=products.OrderId and products.Raw_Material="Milk" and products.Vendor_Id=Vendor_info.Vendor_id and Vendor_Name="Smith";
--10. Display total no. of orders by each vendor every year.
 select Vendor_name,SUM(OrderQuantity) from Vendor_info,products,sales where Vendor_info.Vendor_id=products.Vendor_Id and products.OrderId=sales.OrderID group by Vendor_name;
