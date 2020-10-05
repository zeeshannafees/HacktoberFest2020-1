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
-- Submission by Vivek Rathi
