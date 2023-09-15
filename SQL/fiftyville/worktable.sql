SELECT *
FROM people AS p
    JOIN bakery_security_logs AS bsl ON p.license_plate = bsl.license_plate
    JOIN phone_calls AS pc ON p.phone_number = pc.caller
    JOIN passengers AS ps ON ps.passport_number = p.passport_number
    JOIN flights AS f ON ps.flight_id = f.id
    JOIN airports AS a ON f.origin_airport_id = a.id
    JOIN airports AS ad ON f.destination_airport_id = ad.id
    JOIN bank_accounts AS ba ON ba.person_id = p.id

WHERE bsl.year = 2021 AND bsl.month = 7 AND bsl.day = 28
  AND bsl.hour = 10 AND bsl.minute >= 15 AND bsl.minute <= 25
  AND pc.duration < 60 AND pc.day = 28
  AND f.year = 2021 AND f.month = 7 AND f.day = 29 AND f.hour = 8
  AND a.city = 'Fiftyville';