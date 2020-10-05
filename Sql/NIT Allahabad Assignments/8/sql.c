--20178057 Assignment

-- Q1.a
-- Retrieve the list of names and the cities of all the clients.
select client_name, city from client;

-- Q1.b
-- List the various products available.
select * from product;

-- Q1.c
-- Find the names of all clients having a as the second letter in their names.
select client_name from client where SUBSTR(client_name, 2, 1) = 'a';

-- Q1.d
-- List all the clients who are located in tezpur.
select client_name,city from client where city = "tezpur";

-- Q1.e
-- Find the products whose selling price is greater than 2000 and less than or equal to 5000
select * from product where sell_price>2000 and sell_price<=5000;

-- Q1.f
-- Add a new column NEW_PRICE into the product table.
ALTER TABLE product
ADD new_price int;

-- Q1.g
-- Rename the column P_rate of Sales_Order_Details to new_P_rate.
ALTER TABLE sales_order_details
CHANGE product_rate new_product_rate int;

-- Q1.h
-- List the products in sorted order of their description.
select * from product ORDER BY product_description;

-- Q1.i
-- Display the order number and date on which the clients placed their order.
select sales_order_no, sales_order_date from sales_order_details;

-- Q1.j
-- Delete all the records having delivery date before 25th August, 2008.
delete from sales_order_details where delivery_date < '2008-08-25';

-- Q1.k
-- Change the delivery date of order number ON01008 to 16-08-08
update sales_order_details
set delivery_date = '2008-08-16'
where sales_order_no = 'on01008';

-- Q1.l
-- Change the bal_due of client_no C01003 to 1200
update client
set bal_due = 1200
where client_id = 'cn01003';

-- Q1.m
-- Find the product with description as 'HDD1034' and 'DVDRW'
select * from product where product_description in ('HDD1034', 'DVDRW');

-- Q1.n
-- List the names, city and state of the clients not in the state of assam
select client_name, city, state from client where state != 'assam';

-- Q1.o
-- List of all orders that were cancelled in the month of March.
select * from sales_order_details where MONTH(cancel_date) = 03;

use db20178001;
--
-- Question 1:-
--1.1 Display the names and contact number of all student member
select F_Name,Contact_No from STUD_MEMBER;
--1.2 Give the names and roll numbers of all students of information technology.
select F_Name,Roll_No from STUD_MEMBER,DEPARTMENT where STUD_MEMBER.Dept_ID=DEPARTMENT.Dept_ID and DEPARTMENT.Dept_Name='IT';
--1.3 Display the department names whose students are present in student member.
SELECT * FROM STUD_MEMBER sm LEFT JOIN DEPARTMENT dp ON sm.Dept_Id=dp.Dept_Id
--1.4 Display the department names where no student information is available.
SELECT * FROM STUD_MEMBER sm RIGHT JOIN DEPARTMENT dp ON sm.Dept_Id=dp.Dept_Id
--1.5 Display the names of all departments.
select Dept_Name from DEPARTMENT;
--1.6 Find the names of students of electrical department who are the members
SELECT * FROM STUD_MEMBER sm LEFT JOIN DEPARTMENT dp ON sm.Dept_Id=dp.Dept_Id WHERE sm.Dept_Id=2
--1.7 Display the information of students members whose names begin with the letter A
select F_Name from STUD_MEMBER where F_Name LIKE 'A%';
--1.8 Display all the details of male members only
select * from STUD_MEMBER where Gender='M';
--1.9 Display the data of student members who are currently in semester 3
select * from STUD_MEMBER where Semester=3;
--1.10 Display the data of student female member in alphabetic order
select * from STUD_MEMBER where Gender='F' order by F_Name;

CREATE VIEW MarksView AS  
SELECT Student_Detail.NAME, Student_Detail.ADDRESS, Student_Marks.MARKS  
FROM Student_Detail, Student_Mark  
WHERE Student_Detail.NAME = Student_Marks.NAME;  

CREATE TABLE Persons (
    PersonID int,
    LastName varchar(255),
    FirstName varchar(255),
    Address varchar(255),
    City varchar(255)
);

-- 1
set serveroutput on;
DECLARE 
  var1 varchar2(20) := 'Hello World';
BEGIN
  dbms_output.put_line(var1);
END;
/
-- 2
set serveroutput on;
accept x char prompt 'Please enter something: '
DECLARE
  len varchar2(2); 
  revnum varchar2(5);
  num varchar2(10);
BEGIN
  num := '&x';
  len := length(num);
  for i in 1 .. len
  loop
    revnum := revnum || substr(num,len-i+1,1);
  end loop;
  dbms_output.put_line('Given Number is '||num);
  dbms_output.put_line('Reverse number is '||revnum);
  end;
/
-- 4
set serveroutput on;
declare
  num1 number := 1;
  num2 number := 2;
  num3 number := 3;
begin
  if num1 > num2 and num1 > num3
  then
    dbms_output.put_line('Greatest is '||num1);
  elsif num2 > num1 and num2 > num3
  then
    dbms_output.put_line('Greatest is '||num2);
  else
    dbms_output.put_line('Greatest is '||num3);
  end if;
end;
/
-- 5
create table areas( r number(2), area number(14,2) );
set serveroutput on;
declare 
  r number(5);
  pi number(4,2) := 3.14;
  area number(14,2);
begin
  r := 3;
  for i in 0 .. 4
  loop
    area := (r+i)*(r+i)*pi;
    insert into areas values(r+i,area);
  end loop;
end;
/
select * from areas;
-- 6
set serveroutput on;
accept x char prompt 'Please enter number whose factorial needs to be calculated'
declare
  num number(2);
  ans number(7) := 1;
begin
  num := &x;
  for i in 1 .. num loop
    ans:= ans*i;
  end loop;
  dbms_output.put_line(ans);
end;
/
-- 7
set serveroutput on;
declare
  date1 date;
  date2 date;
  ans number(4);
begin
  date1 := to_date('12-21-1999','MM-DD-YYYY');
  date2 := to_date('10-16-2019','MM-DD-YYYY');
  ans := months_between(date1,date2);
  dbms_output.put_line(ans);
end;
/
-- 8
Create   table       Account_Master(acct_no   number(5)   primary   key,acct_holder_name
varchar2(10),balance number(10));
insert into Account_Master values(1,'John',1000);
insert into Account_Master values(2,'Denis',100);
insert into Account_Master values(3,'Albert',1100);
insert into Account_Master values(4,'Charles',700);
insert into Account_Master values(5,'Darwin',1700);
accept x char prompt 'Enter Account Number '
set serveroutput on;
declare
  person Account_Master%rowtype;
  accno number(1);
  newbalance number(4);
begin
  accno := 4;
  select * into person from Account_Master where acct_no=accno;
  if person.balance < 1000
  then
    newbalance := person.balance-100;
    update Account_Master set balance=person.balance-100 where acct_no=accno;
  end if;
end;
/
select * from Account_Master;



-- question 1
set serveroutput on;
declare
    employee_id Emp_Detail.employee_id%type;
    first_name Emp_Detail.first_name%type;
    last_name Emp_Detail.last_name%type;
    salary Emp_Detail.salary%type;
    dept_id Emp_Detail.dept_id%type;
    dept_name Department.dept_name%type;
    manager_id Department.manager_id%type;
    cursor c_emp is select employee_id, first_name, last_name, salary, dept_id from Emp_Detail where employee_id=5;
begin
    open c_emp;
    loop
        fetch c_emp into employee_id, first_name, last_name, salary, dept_id;
        exit when c_emp%notfound;
        dbms_output.put_line(employee_id||' '||first_name||' '||last_name||' '||salary||' '||dept_id);
    end loop;
    close c_emp;
end;
-- question 2
select first_name, Department.dept_id, dept_name from Emp_Detail join Department where salary>5000;
-- question 3
declare
    employee_id Emp_Detail.employee_id%type;
    first_name Emp_Detail.first_name%type;
    last_name Emp_Detail.last_name%type;
    salary Emp_Detail.salary%type;
    dept_id Emp_Detail.dept_id%type;
    dept_name Department.dept_name%type;
    manager_id Department.manager_id%type;
    cursor c_emp is select employee_id, first_name, last_name, salary, dept_id from Emp_Detail;
begin
    open c_emp;
    loop
        fetch c_emp into employee_id, first_name, last_name, salary, dept_id;
        exit when c_emp%notfound;
        dbms_output.put_line(first_name||' '||last_name||' '||salary);
    end loop;
    close c_emp;
end;
-- question 4
declare
    employee_id Emp_Detail.employee_id%type;
    first_name Emp_Detail.first_name%type;
    last_name Emp_Detail.last_name%type;
    salary Emp_Detail.salary%type;
    dept_id Emp_Detail.dept_id%type;
    dept_name Department.dept_name%type;
    manager_id Department.manager_id%type;
    cursor c_emp is select employee_id, first_name, last_name, salary, dept_id from Emp_Detail where salary>8000;
begin
    open c_emp;
    loop
        fetch c_emp into employee_id, first_name, last_name, salary, dept_id;
        exit when c_emp%notfound;
        dbms_output.put_line(employee_id||' '||first_name||' '||last_name||' '||salary||' '||dept_id);
    end loop;
    close c_emp;
end;
-- question 5
declare
    employee_id Emp_Detail.employee_id%type;
    first_name Emp_Detail.first_name%type;
    last_name Emp_Detail.last_name%type;
    salary Emp_Detail.salary%type;
    dept_id Emp_Detail.dept_id%type;
    dept_name Department.dept_name%type;
    manager_id Department.manager_id%type;
    cursor c_emp is select employee_id, first_name, last_name, salary, dept_id from Emp_Detail order by salary;
    coun number(2);
begin
    coun := 0;
    open c_emp;
    loop
        fetch c_emp into employee_id, first_name, last_name, salary, dept_id;
        exit when c_emp%notfound;
        dbms_output.put_line(employee_id||' '||first_name||' '||last_name||' '||salary||' '||dept_id);
        coun := coun+1;
        exit when coun>=6;
    end loop;
    close c_emp;
end;
-- question 6
declare
    employee_id Emp_Detail.employee_id%type;
    first_name Emp_Detail.first_name%type;
    last_name Emp_Detail.last_name%type;
    salary Emp_Detail.salary%type;
    dept_id Emp_Detail.dept_id%type;
    dept_name Department.dept_name%type;
    manager_id Department.manager_id%type;
    cursor c_emp is select employee_id, first_name, last_name, salary, dept_id from Emp_Detail for update;
begin
    open c_emp;
    loop
        fetch c_emp into employee_id, first_name, last_name, salary, dept_id;
        exit when c_emp%notfound;
        update Emp_Detail set salary = salary + 2000 where current of c_emp;
    end loop;
    close c_emp;
end;
-- question 7
DECLARE
CURSOR c_dept IS
  SELECT *
  FROM department
  WHERE manager_id IS NOT NULL
  ORDER BY dept_name;
  r_dept c_dept%ROWTYPE;

--Declaration of department cursor and record variable.
  
  CURSOR c_emp (c_dept_no department.dept_id%TYPE) IS
  SELECT *
  FROM emp_detail
  WHERE dept_id = c_dept_no;
  r_emp c_emp%ROWTYPE;

--Declaration of employees cursor and record variable.
  
BEGIN
   OPEN c_dept;
   LOOP
     FETCH c_dept INTO r_dept;
      EXIT WHEN c_dept%NOTFOUND;
      DBMS_OUTPUT.PUT_LINE('----------------------------------');
      DBMS_OUTPUT.PUT_LINE('Department Name : '||r_dept.dept_name);
      DBMS_OUTPUT.PUT_LINE('----------------------------------');
          OPEN c_emp(r_dept.dept_id);
           LOOP
            FETCH c_emp INTO r_emp;
             EXIT WHEN c_emp%NOTFOUND;
                DBMS_OUTPUT.PUT_LINE('Employees Details : '||r_emp.employee_id
||' '||r_emp.first_name||' '||r_emp.last_name||' '||r_emp.salary);
           END LOOP;
          CLOSE c_emp;  
   END LOOP;
   CLOSE c_dept;
END;

