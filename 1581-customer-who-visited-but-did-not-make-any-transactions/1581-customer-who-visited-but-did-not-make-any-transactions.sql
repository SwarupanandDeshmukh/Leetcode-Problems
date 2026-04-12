# Write your MySQL query statement below

#get customer id where users visited without making transactions.
select v.customer_id,
COUNT(CASE WHEN t.transaction_id IS NULL THEN 1 END) as count_no_trans
 from Visits v LEFT JOIN Transactions t ON v.visit_id = t.visit_id group by customer_id HAVING count_no_trans > 0;