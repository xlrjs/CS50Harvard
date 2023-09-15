-- Keep a log of any SQL queries you execute as you solve the mystery.
-- so the things we know
--  the crime took place on July 28 2021
-- on the 'Humphrey Street'
SELECT * FROM crime_scene_reports LIMIT 10; -- I did this to see how was the table information
-- i think in this way i can see better the information and undestand the content
-- then i went specific
/* I select eveything not just description,
i think is better to see the overall information
to double check if its the right one */
SELECT * FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28
AND street = 'Humphrey Street';

-- table is to big, now we just see description
SELECT description FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28
AND street = 'Humphrey Street';
/* information: theft took place at 10:15 at the bakery. Three interviwed witnesses
each one in the transcripts mention the bakey */

-- lets see the interviews table
 .schema interviews
 SELECT * FROM interviews LIMIT 2;

 -- Okay it has to be same date

 SELECT * FROM interviews
 WHERE year = 2021 AND month = 7 AND day = 28;

 --they said bakery

SELECT transcript FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28
AND transcript LIKE'%bakery%';

/* INFORMATION:
witnesses
    Ruth id 161 says: 10 min after, 10:25 am, thief got into a car in the bakery parking lot
        look for cars leaving at that time
    Eugene id 162 says: morning by the ATM on Leggett Street thief withdeaw money
    Raymond id 163 says: heard by thief making phone call
        planning to take earliest flight out of town tomorrow. purchase the flight ticket
        called less than a minute
        flight out of fiftyville
        ask the other person to purchase the ticket


look for
    parking lot at 10:25
    ATM at Leggett Street before 10:15 am
    flights on 29 july 2021, the earliest
    */

.schema bakery_security_logs

SELECT * FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28
AND hour = 10 AND minute >= 15 AND minute <= 25;

/* we got multiple plates lets check whats in the other tips*/

.schema atm_transactions

SELECT * FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28
AND atm_location = 'Leggett Street' and transaction_type = 'withdraw';

-- a lot of information, but, we have a account_number
-- airport
SELECT * FROM airports
WHERE city = 'Fiftyville';

SELECT * FROM flights
WHERE origin_airport_id IN (SELECT id FROM airports WHERE city = 'Fiftyville')
AND year = 2021 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1;

SELECT * FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60
ORDER BY duration;


/* from the information gathered we know that
    we have to match the information from the bakery logs and phone calls to match
    the license plate with the caller */

SELECT name, destination_airport_id, ad.city, receiver
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

-- WE GOT THE NAME 'BRUCE'

SELECT * FROM airports WHERE id = 4;

-- we know the destination city New York City

SELECT name FROM people WHERE phone_number = '(375) 555-8161';

-- the complice ROBIN
