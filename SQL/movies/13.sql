/* SELECT name
    FROM people
        WHERE id IN (SELECT person_id
            FROM stars WHERE movie_id IN (SELECT id
                FROM movies WHERE id IN (SELECT movie_id
                    FROM stars WHERE person_id = (SELECT id
                        FROM people WHERE name = 'Kevin Bacon')))); -- */
SELECT p.name
FROM people AS p
JOIN stars AS s ON s.person_id = p.id
JOIN movies AS m ON s.movie_id = m.id
JOIN stars AS s1 ON s1.movie_id = m.id
JOIN people AS p1 ON s1.person_id = p1.id
WHERE p1.name = 'Kevin Bacon' AND p1.birth = 1958 AND p.name <> 'Kevin Bacon';

