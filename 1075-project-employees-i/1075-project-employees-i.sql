# Write your MySQL query statement below

select
     p.project_id,
    ROUND(SUM(e. experience_years) / COUNT(e.employee_id), 2)
      AS average_years from Project p JOIN Employee e ON p.employee_id = e.employee_id GROUP by p.project_id;