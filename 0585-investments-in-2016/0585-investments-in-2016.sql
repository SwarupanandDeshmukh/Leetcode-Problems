# Write your MySQL query statement below

select ROUND(SUM(tiv_2016),2) as 'tiv_2016' from Insurance where tiv_2015 IN (
    select tiv_2015 from Insurance group by tiv_2015 having COUNT(*) > 1
)
AND (lat,lon) IN
(
    select lat,lon from Insurance group by lat,lon having COUNT(*) = 1
)
  
;