# Write your MySQL query statement below

select id, num from 
(
    select id, COUNT(*) as num
    from 
    (
        select requester_id as id from RequestAccepted
        UNION ALL
        select accepter_id as id from RequestAccepted
    )
    as combined
    group by id
) as final order by num desc limit 1;