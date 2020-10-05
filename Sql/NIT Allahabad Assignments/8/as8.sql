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

