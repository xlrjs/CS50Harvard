SELECT name FROM directors, movies, ratings, people
WHERE ratings.rating >= 9.0
AND ratings.movie_id = movies.id
AND directors.movie_id = movies.id
AND directors.person_id = people.id;