-- q1 Write a PL/SQL program to print “HELLO WORLD”.
set serveroutput on;
Declare
message varchar2(20):= 'HELLO WORLD!';
Begin
dbms_output.put_line(message);
End;
/

-- q2 Write a PL/SQL code for inverting a number. (Example: 1234 – 4321)
-- set serveroutput on;
Declare
num number;
revnum number;
dig number;
i number;
Begin
revnum:=0;
num:=&num;
i:= num;
WHILE i>0
LOOP
dig:=mod(i,10);
revnum:=(revnum*10)+dig;
i:=trunc(i/10);
END LOOP;
dbms_output.put_line('reverse is '||revnum);
End;
/

-- q3 Write a PL/SQL code to find the greatest number among three with Anonymous blocks.
-- set serveroutput on;
Declare
a number:= &a;
b number:= &b;
c number:= &c;
Begin
IF a>b AND a>c THEN
dbms_output.put_line('Greatest number ' ||a);
ELSEIF b>a AND b>c THEN
dbms_output.put_line('Greatest number ' ||b);
IF c>a AND c>b THEN
dbms_output.put_line('Greatest number ' ||c);
END IF;
End;
/

-- q4 Write a PL/SQL code to calculate the area of a circle where radius takes values from 3 to 7.Store the calculated area in Table AREA.
-- set serveroutput on;
DROP TABLE AREAS;
CREATE TABLE AREAS(r number(4),ar number(14,2));
Declare
r number(4);
pie number(4,2):= 3.14;
ar number(14,2);
Begin
r:=3;
while r<=7
LOOP
ar:=pie*r*r;
INSERT INTO AREAS VALUES(r,ar);
r:=r+1;
END LOOP;
End;
/
Select * from AREAS;

-- q5 Write a PL/SQL program to accept a number and find the factorial of the number
-- set serveroutput on;
Declare
num number:= &num;
fact number;
Begin
fact:=1;
for i in 1..num 
loop
fact:=fact*i;
end loop;
dbms_output.put_line('Factorial is ' ||fact);
End;
/

-- q6 Write a PL/SQL program to display the months between two dates of a year
-- set serveroutput on;
Declare
-- D1 DATE:=&D1;
-- D2 DATE:=&D2;
months number(10);
Begin
months:= MONTHS_BETWEEN('13-JUN-1973', '23-JAN-1973');
dbms_output.put_line(months);
End;
/
-- q7 Create an Account_Master table & insert the tuples as given the question. Write a PL/SQL code that will accept an account number from user. If the balance of account is less than minimum balance (i.e 1000) deducts Rs 100 from balance.
-- SET SERVEROUTPUT ON;
DROP TABLE Account_Master;
Create table Account_Master(acct_no number(5) primary key,acct_holder_name varchar2(10),balance number(10));
insert into Account_Master values(1,'John',1000);
insert into Account_Master values(2,'Denis',100);
insert into Account_Master values(3,'Albert',1100);
insert into Account_Master values(4,'Charles',700);
insert into Account_Master values(5,'Darwin',1700);
Declare
xacct_no number:=&xacct_no;
xbalance number;
Begin
select balance into xbalance  
from Account_Master  
where acct_no=xacct_no;
IF(xbalance < 1000) THEN 
update Account_Master 
set balance=balance-100  
where acct_no=xacct_no;                                                           
xbalance:=xbalance-100;  
dbms_output.put_line('Rs 100 is deducted and current balance is '||xbalance);
ELSE             
dbms_output.put_line('Current balance is '||xbalance);
END IF; 
END;  
/ 
Select * from Account_Master;
