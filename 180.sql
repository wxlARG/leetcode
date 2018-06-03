select 
    distinct(Num) as ConsecutiveNums
from (
    select 
        Id,
        Num,
        (select count(*) from Logs as b where b.Id between a.Id-2 and a.Id and b.Num=a.Num) as c
    from Logs as a
) as t 
where t.c>=3;
