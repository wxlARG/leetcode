select 
    if(count(1)=0, null, Salary) as SecondHighestSalary
from (
    select 
        Salary
    from Employee 
    group by Salary
    order by Salary desc
    limit 1, 1
) as b;
