# Write your MySQL query statement below
with cte as
(
    select person_name, weight, SUM(weight) over(order by turn) as cumulative from 
    Queue order by turn
)

select person_name from cte where cumulative <= 1000 order by cumulative desc limit 1;

