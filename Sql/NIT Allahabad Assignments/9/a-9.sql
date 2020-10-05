/*DECLARE 
   a number; 
   b number; 
   c number;
PROCEDURE findMin(x IN number, y IN number, z OUT number) IS 
BEGIN 
   IF x < y THEN 
      z:= x; 
   ELSE 
      z:= y; 
   END IF; 
END;   
BEGIN 
   a:= 23; 
   b:= 45; 
   findMin(a, b, c); 
   dbms_output.put_line(' Minimum of (23, 45) : ' || c); 
END; 
/ */
set SERVEROUTPUT on;
/*drop table customers;
Create table customers (ID number(10), name varchar2(10), age number(10), address
varchar2(10), Salary Float );
insert into customers values(101,'John',32,'Lodan',20000.00);
insert into customers values(3,'Clerk',25,'Paris',15000.00);
insert into customers values(4,'Mark',22,'New York',85000.00);
insert into customers values(5,'Albert',29,'California',45000.00);
DECLARE
x number(2);
FUNCTION totalCustomers 
RETURN number IS 
   total number(2) := 0; 
BEGIN 
   SELECT count(*) into total 
   FROM customers; 
    
   RETURN total; 
END; 
BEGIN
x:=totalCustomers();
dbms_output.put_line( 'total customers are '|| x );
END;
/ */
/*DECLARE
num number;
fct number;
FUNCTION fun(x number) RETURN number 
IS
f number;
BEGIN
if x=0 then
f:=1;
else
f:=x*fun(x-1);
end if;
return f;
END;
BEGIN
num:=5;
fct:=fun(num);
dbms_output.put_line('factorial of anumber  is '||fct);
end;
/ */
declare
procedure p is
procedure p1 is
begin
dbms_output.put_line('this is first one');
end;
procedure p2 is
begin
dbms_output.put_line('this is second');
end;
begin
p1();
p2();
end;
begin
p();
end;
/