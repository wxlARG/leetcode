select 
    d.Name as Department,
    e.Name as Employee,
    e.Salary
from Employee as e
join Department as d on e.DepartmentId=d.Id
join(
select 
    DepartmentId,
    Name,
    ifnull((select distinct b.Salary from Employee as b where b.DepartmentId=a.DepartmentId order by b.Salary desc limit 2, 1), -1) as Salary
from Employee as a
) as t on e.DepartmentId=t.DepartmentId and e.Name=t.Name and e.Salary>=t.Salary
order by Department asc, Salary desc;
