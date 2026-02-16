# Write your MySQL query statement below

select name from SalesPerson
where sales_id NOT IN(
    SELECT o.sales_id
    FROM Orders o
    JOIN Company c ON o.com_id = c.com_id
    WHERE c.name = 'RED');