# Write your MySQL query statement below

with ranked_dept as (
    select d.name as Department , e.name as Employee, e.salary as Salary, 
DENSE_RANK() OVER(partition by d.id order by salary desc) as `rank`
from Employee e join Department d on e.departmentId = d.id 
group by d.name, e.name, e.salary
)

select Department, Employee, Salary from ranked_dept where `rank` <= 3;