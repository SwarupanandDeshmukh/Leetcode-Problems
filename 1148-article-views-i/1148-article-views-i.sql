# Write your MySQL query statement below

# author that viewed at least one of their own articles.

select DISTINCT(viewer_id) as 'id' from Views where viewer_id = author_id ORDER BY author_id ASC;