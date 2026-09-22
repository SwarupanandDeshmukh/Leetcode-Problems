# Write your MySQL query statement below

with cte as
(
select num,lag(num, 1) over () as prev, lead(num, 1) over () as future from Logs
)

select distinct num as ConsecutiveNums from cte where num = prev and num  = future;