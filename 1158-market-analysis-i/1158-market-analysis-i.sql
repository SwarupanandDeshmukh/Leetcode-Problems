# Write your MySQL query statement below

select u.user_id as buyer_id, u.join_date,

COUNT(CASE WHEN o.order_date BETWEEN "2019-01-01" AND "2019-12-31" THEN 1 END) AS orders_in_2019 
from Users u LEFT JOIN Orders o  ON u.user_id = o.buyer_id group by u.user_id order by u.user_id;
