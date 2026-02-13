# Write your MySQL query statement below

select e.name, b.bonus from Employee e LEFT JOIN Bonus b ON e.empid = b.empId WHERE b.bonus IS NULL OR b.bonus < 1000 ;
