select 
    b.Id as Id
from Weather as a
join Weather as b on a.RecordDate=DATE_SUB(b.RecordDate,INTERVAL 1 DAY)
where b.Temperature>a.Temperature
