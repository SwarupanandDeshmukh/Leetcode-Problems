select person_name from
(
    select person_name,
            weight,
            SUM(weight) OVER (order by turn) as total
    from Queue
) as t
where total <= 1000 order by total desc limit 1;