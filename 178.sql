select 
    Score,
    (select count(distinct Score)+1 from Scores as b where b.Score>a.Score) as Rank
from Scores as a
order by a.Score desc;
