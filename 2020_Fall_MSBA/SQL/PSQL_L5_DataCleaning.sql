/*3 LEFT&RIGHT*/
/*1. In the accounts table, there is a column holding the website for each company. The last three digits specify what type of web address they are using. A list of extensions (and pricing) is provided here. Pull these extensions and provide how many of each website type exist in the accounts table.*/
SELECT RIGHT(website, 3), COUNT(RIGHT(website, 3))
FROM accounts
GROUP BY 1

/*2. There is much debate about how much the name (or even the first letter of a company name) matters. Use the accounts table to pull the first letter of each company name to see the distribution of company names that begin with each letter (or number).*/
SELECT LEFT(name, 1), COUNT(*)
FROM accounts
GROUP BY 1
ORDER BY 2 DESC

/*3. Use the accounts table and a CASE statement to create two groups: one group of company names that start with a number and a second group of those company names that start with a letter. What proportion of company names start with a letter?*/
SELECT SUM(num) num, SUM(letter) letter
FROM
(SELECT CASE WHEN LEFT(name, 1) IN ('0','1','2','3','4','5','6','7','8','9') THEN 1 ELSE 0 END AS num,
CASE WHEN LEFT(name, 1) IN ('0','1','2','3','4','5','6','7','8','9') THEN 0 ELSE 1 END AS letter
FROM accounts) sub

/*4. Consider vowels as a, e, i, o, and u. What proportion of company names start with a vowel, and what percent start with anything else?*/
SELECT SUM(vowel) vowel, SUM(regular) regular
FROM(
SELECT CASE WHEN LEFT(LOWER(name), 1) IN ('a','e','i','o','u') THEN 1 ELSE 0 END AS vowel,
CASE WHEN LEFT(LOWER(name), 1) IN ('a','e','i','o','u') THEN 0 ELSE 1 END AS regular
FROM accounts) sub

/*POSITION(ANSI SQL STANDARD) & STRPOS*/
/*1. Use the accounts table to create first and last name columns that hold the first and last names for the primary_poc.*/
SELECT primary_poc,
LEFT(primary_poc, STRPOS(primary_poc, ' ') - 1 ) AS First_name,
RIGHT(primary_poc, LENGTH(primary_poc) - STRPOS(primary_poc, ' ')) Last_name
FROM accounts

/*2. Now see if you can do the same thing for every rep name in the sales_reps table. Again provide first and last name columns.*/
SELECT name,
LEFT(name, POSITION(' ' IN name)) AS first_name,
RIGHT(name, LENGTH(name) - POSITION(' ' IN name)) AS last_name
FROM sales_reps

/*CONCAT*/
/*1. Each company in the accounts table wants to create an email address for each primary_poc. The email address should be the first name of the primary_poc . last name primary_poc @ company name .com.*/
/*2. You may have noticed that in the previous solution some of the company names include spaces, which will certainly not work in an email address. See if you can create an email address that will work by removing all of the spaces in the account name, but otherwise your solution should be just as in question 1. Some helpful documentation is here.*/
SELECT CONCAT(first, '.', last, '@', company_name, '.com')
FROM (
SELECT
LEFT(primary_poc, STRPOS(primary_poc, ' ') - 1) AS first,
RIGHT(primary_poc, LENGTH(primary_poc) - STRPOS(primary_poc, ' ')) AS last,
CASE WHEN LENGTH(LEFT(name, STRPOS(name, ' '))) = 0 THEN name ELSE LEFT(name, STRPOS(name, ' ') - 1) || RIGHT(name, LENGTH(name) - STRPOS(name, ' ')) END company_name
FROM accounts) sub

/*3. We would also like to create an initial password, which they will change after their first log in. The first password will be the first letter of the primary_poc's first name (lowercase), then the last letter of their first name (lowercase), the first letter of their last name (lowercase), the last letter of their last name (lowercase), the number of letters in their first name, the number of letters in their last name, and then the name of the company they are working with, all capitalized with no spaces.*/
SELECT f1 || f2 || l1 || l2 || fl || ll || UPPER(comp_name)
FROM
(SELECT LEFT(LOWER(primary_poc), 1) f1, RIGHT(LEFT(primary_poc, STRPOS(primary_poc, ' ') - 1), 1) f2,
LEFT(LOWER(RIGHT(primary_poc, LENGTH(primary_poc) - STRPOS(primary_poc, ' '))), 1) l1,
RIGHT(LOWER(RIGHT(primary_poc, LENGTH(primary_poc) - STRPOS(primary_poc, ' '))), 1) l2,
LENGTH(LEFT(primary_poc, STRPOS(primary_poc, ' ') - 1)) fl,
LENGTH(RIGHT(primary_poc, LENGTH(primary_poc) - STRPOS(primary_poc, ' '))) ll,
CASE WHEN LENGTH(LEFT(name, STRPOS(name, ' '))) = 0 THEN name ELSE LEFT(name, STRPOS(name, ' ') - 1) || RIGHT(name, LENGTH(name) - STRPOS(name, ' '))  END AS comp_name
FROM accounts) sub

WITH t1 AS (
 SELECT LEFT(primary_poc,     STRPOS(primary_poc, ' ') -1 ) first_name,  RIGHT(primary_poc, LENGTH(primary_poc) - STRPOS(primary_poc, ' ')) last_name, name
 FROM accounts)
SELECT first_name, last_name, CONCAT(first_name, '.', last_name, '@', name, '.com'), LEFT(LOWER(first_name), 1) || RIGHT(LOWER(first_name), 1) || LEFT(LOWER(last_name), 1) || RIGHT(LOWER(last_name), 1) || LENGTH(first_name) || LENGTH(last_name) || REPLACE(UPPER(name), ' ', '')
FROM t1;


SELECT (yearnum || '-' || monthnum || '-' || daynum || ' ' ||times)::date AS form_date
FROM(SELECT SUBSTRING(newd from 7 for 10) yearnum, SUBSTRING(newd from 1 for 2) monthnum, SUBSTRING(newd from 4 for 2) daynum, times
FROM(SELECT LEFT(date, STRPOS(date, ' ') - 1) newd, LEFT((RIGHT(date, LENGTH(date) - STRPOS(date, ' '))), STRPOS((RIGHT(date, LENGTH(date) - STRPOS(date, ' '))), ' ')) times
FROM sf_crime_data
) sub) sub2
