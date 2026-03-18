# Write your MySQL query statement below
select u.name, SUM(t.amount) AS 'balance' from Users u JOIN Transactions t ON u.account = t.account group by t.account having SUM(t.amount) > 10000;