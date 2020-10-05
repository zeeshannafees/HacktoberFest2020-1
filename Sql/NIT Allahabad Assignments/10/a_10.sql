
create table salary(empno int,basic int,hra int,da int,totalded int,netsal int,grosssal int,primary key (empno));
create table newsalary(empno int,basic int,hra int,da int,totalded int,netsal int,grosssal int,primary key (empno));
insert into salary values(2,15000,4000,1000,5000,15000,20000);
insert into salary values(1,31000,8000,1000,5000,35000,40000);
insert into salary values(3,14000,4000,1000,5000,15000,19000);
insert into salary values(4,14000,4000,1000,5000,15000,19000);
insert into salary values(5,13000,4000,1000,5000,15000,18000);
set serveroutput on;
--q1
create or replace TRIGGER q1 
before
UPDATE ON SALARY
for each row
begin
    insert into salary_new values (:OLD.Emp_no, :OLD.Basic,:OLD.HRA , :OLD.DA, :OLD.Total_Dedution, :OLD.Net_Salary, :OLD.Gross_Salary);
end;
/
begin
    update Salary set basic = 20000 where Emp_no=2;
    update Salary set basic = 60000 where Emp_no=3;
end;


--q2
create or replace trigger q2
before delete on item_requisite
for each row
declare
    bal number;
begin
    select bal_stock into bal from item_master where item_id = :OLD.item_id;
    bal := bal - :OLD.quantity;
    if(bal<0)
        then
        dbms_output.put_line('Cant delete ');
        raise_application_error(-20000,'Cant delete');
    end if;
    update item_master set bal_stock=bal where item_id = :OLD.item_id;
end;
/
begin
  delete from item_requisite where item_id=105;
end;
/


--q3
create or replace trigger q3
after delete on emp
for each row
begin
    update emp set mgr = 'gg' where mgr = :OLD.emp_name;
end;
/
begin
    delete from emp where emp_id=1004;
end;
/
