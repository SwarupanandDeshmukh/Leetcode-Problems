# Write your MySQL query statement below

select u.unique_id, e.name as 'name' from EmployeeUNI u RIGHT JOIN Employees e ON u.id = e.id;