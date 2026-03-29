select score,
    DENSE_RANK() OVER (order by score DESC) as 'rank' from Scores;