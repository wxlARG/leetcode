select 
    t.Request_at as Day,
    round(sum(if(t.Status='completed', 0, 1))/sum(1), 2) as `Cancellation Rate`
from Trips as t
join Users as c on t.Client_Id=c.Users_Id
join Users as d on t.Driver_Id=d.Users_Id
where c.Banned='No' 
	and d.Banned='No' 
	and t.Request_at between '2013-10-01' and '2013-10-03'
group by t.Request_at
