# Write your MySQL query statement below

with daily as
(
    select visited_on, sum(amount) as amount from Customer group by visited_on
),
rolling as 
(
    select visited_on,
    SUM(amount) OVER (
        order by visited_on
        ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    ) as amount,
    AVG(amount) OVER(
        order by visited_on
         ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    ) as average_amount,
    ROW_NUMBER() OVER(order by visited_on) as row_no

    from daily
)

select visited_on, amount, ROUND(average_amount,2) AS average_amount from rolling where row_no >= 7;