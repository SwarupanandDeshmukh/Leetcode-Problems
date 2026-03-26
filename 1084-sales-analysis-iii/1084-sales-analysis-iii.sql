# Write your MySQL query statement below

select product_id, product_name from Product where product_id IN (select product_id from Sales  group by product_id having COUNT(CASE WHEN sale_date between "2019-01-01" and "2019-03-31" then 1 end) = COUNT(*)) ;