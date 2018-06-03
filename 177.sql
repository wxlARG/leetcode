CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set N=N-1;
    RETURN (
        # Write your MySQL query statement below.
        select
            if(count(1)=0, null, Salary) as SecondHighestSalary
        from (
            select
                Salary
            from Employee
            group by Salary
            order by Salary desc
            limit N, 1
        ) as b    
    );
END
