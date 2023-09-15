SELECT title
FROM movies, ratings, people, stars
WHERE people.name = 'Chadwick Boseman'
AND ratings.movie_id = movies.id
AND stars.movie_id = movies.id
AND stars.person_id = people.id
ORDER BY rating DESC LIMIT 5;