SELECT title, rating FROM ratings, movies WHERE movies.year = 2010 AND ratings.movie_id = movies.id ORDER BY rating DESC, title ASC;