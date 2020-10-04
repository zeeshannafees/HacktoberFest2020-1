--------------------------------------------------------------------------------
--Assignment 5
--
--(a)Fetch first name, last name of worker using alias name as E_Name.
SELECT CONCAT(FIRST_NAME,' ',LAST_NAME) AS E_Name from Employee;
--(b)List the last name of employees in upper case.
SELECT UPPER(LAST_NAME) FROM  Employee;
--(c)Retrieve the first three characters of employees from their first name.
SELECT LEFT(FIRST_NAME,3) FROM Employee;
--(d)Retrieve the unique values of department and display its length.
SELECT DISTINCT DEPARTMENT ,LENGTH(DEPARTMENT) FROM Employee;
--(e)List the first name from employees table after replacing ‘a’ with ‘A’.
SELECT REPLACE(FIRST_NAME,'a','A') FROM Employee;
--(f)Display all employee details, use order by in first name asec and salary in desc.
SELECT * FROM Employee  ORDER BY SALARY DESC,FIRST_NAME;
--(g)List the details of an employee whose first name ends with ‘h’ and contains six alphabets.
SELECT * FROM Employee WHERE LENGTH(FIRST_NAME)=6 AND RIGHT(FIRST_NAME,1)='h';
--(h)Display the details of employees who have joined in Feb 2014.
SELECT * FROM Employee WHERE YEAR(JOINING_DATE)=2014 AND MONTH(JOINING_DATE)=02;
--(i)Fetch the employee’s names with salaries over and equal to 50000 and less than equal to 100000.
SELECT CONCAT(FIRST_NAME,' ',LAST_NAME) FROM Employee WHERE SALARY>=50000 AND SALARY<=100000;
--(j)List the no. of employees for each department in desc order.
SELECT DEPARTMENT, COUNT(DEPARTMENT) FROM Employee GROUP BY DEPARTMENT ORDER BY COUNT(DEPARTMENT) DESC;
--(k)Print the details of employees who are also managers.
 SELECT * FROM Employee, Job_Title WHERE Employee.E_Id=Job_Title.E_Ref_Id AND E_Title='Manager';
--(l)Fetch the duplicate records having matching data in some fields of a table. (Using departmentn column.)
SELECT * FROM Employee WHERE DEPARTMENT IN (SELECT DEPARTMENT FROM Employee GROUP BY DEPARTMENT HAVING COUNT(DEPARTMENT) > 1);
--(m)Fetch intersecting records of two tables.
SELECT * FROM Employee,Job_Title,Bonus where Employee.E_Id=Job_Title.E_Ref_Id AND Employee.E_Id=Bonus.E_Ref_Id;
--(n)Find the nth (say n=5) highest salary from a table.
SELECT Salary FROM Employee GROUP BY Salary DESC LIMIT 4,1;
--(o)Find the 4th highest salary without using TOP or limit method.
SELECT Salary FROM Employee e1 where 4=(SELECT COUNT(DISTINCT SALARY) FROM Employee e2 WHERE e2.Salary>e1.Salary);
--(p)List the details of employees with the same salary.
SELECT * FROM Employee WHERE Salary IN (SELECT Salary FROM Employee GROUP BY Salary HAVING COUNT(Salary) > 1);
--(q)Display the second highest salary from a table.
SELECT Salary FROM Employee GROUP BY Salary DESC LIMIT 1,1;
--(r)Display all departments along with the number of people in there.
SELECT DEPARTMENT, COUNT(DEPARTMENT) FROM Employee GROUP BY DEPARTMENT;
--(s)List the name of employees having the highest salary in each department.
 SELECT FIRST_NAME,LAST_NAME,DEPARTMENT,MAX(SALARY) AS SALARY  FROM Employee GROUP BY DEPARTMENT;
--(t)Fetch three min salaries from a table
SELECT Salary FROM Employee GROUP BY Salary LIMIT 3;
--(u)Fetch departments along with the total salaries paid for each of them.
SELECT DEPARTMENT,SUM(SALARY) FROM Employee GROUP BY DEPARTMENT;
--(v)Fetch the names of employees who earn the highest salary.
SELECT FIRST_NAME,LAST_NAME FROM Employee WHERE SALARY=(SELECT MAX(SALARY) FROM Employee);
--(w)List the employee details whose joining year is “2013”?
SELECT * FROM Employee WHERE YEAR(JOINING_DATE)=2013;
--(x)Find the Joining Date and Time from employee table
SELECT date(JOINING_DATE),time(JOINING_DATE) FROM Employee;
--(y)Fetch the department wise minimum salary from employee table order by salary ascending.
SELECT FIRST_NAME,LAST_NAME,DEPARTMENT,MIN(SALARY) AS SALARY  FROM Employee GROUP BY DEPARTMENT ORDER BY MIN(SALARY);
--(z)Fetch department, no of employees in a department, total salary with respect to a department from employee table order by total salary descending
SELECT DEPARTMENT,COUNT(DEPARTMENT),SUM(SALARY) FROM Employee GROUP BY DEPARTMENT ORDER BY SUM(SALARY) DESC;
