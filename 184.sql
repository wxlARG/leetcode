select 
    t.Department,
    e.Name as Employee,
    e.Salary
from Employee as e
join(
    select
        b.Id,
        max(Salary) as Salary,
        b.Name as Department
    from Employee as a
    join Department as b on a.DepartmentId=b.Id
    group by b.Id
) as t on e.Salary=t.Salary and e.DepartmentId=t.Id;
