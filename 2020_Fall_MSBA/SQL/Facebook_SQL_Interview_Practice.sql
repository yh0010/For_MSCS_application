/* tables: customers, products, sales,....
products: product_id, brand_name, product_class_id, price,.....
Sales: product_id, customer_id, store_sales, promotion_id,.....*/

/*1. something about for a brand:over average price > 3$ and at least 2 products only use products table */
SELECT (forgot this variable, probably brand_name), AVG(price), COUNT(product_id)
FROM product
 GROUP BY (forgot this variable)
HAVING AVG(price) > 3 and COUNT(product_id) >=2

/*2.what is the percentage of discount promotion? (the original question is more words and kind of hard to understand)*/
 SELECT (SUM(CASE WHEN promotion_id !=0 THEN 1 ELSE 0 END)/COUNT(*))*100 AS ratio
 FROM sales

/*3. TOP 3 best sale products class */
SELECT product_class_id, SUM(store_sales) AS totrevenue
FROM products JOIN sales ON products.product_id = sales.product_id
GROUP BY product_class_id
ORDER BY SUM(store_sales) DESC LIMIT 3

/*4. find the customer buy both brand "Ford" and "Gold" My stupid answer. */
SELECT s.customer_id
FROM products p
JOIN sales s
WHERE p.brand_name = "Ford" and customer_id in ( SELET s. customer_id FROM products p JOIN sales s WHERE p,brand_name = "Gold")
GROUP BY customer_id
ORDER BY customer_id;

Avoid use sub -query. Interviewer ask the alternative way in the end the tip from the interviewer.
SELECT MAX(CASE WHEN brand_name="Ford" THEN 1 ELSE 0), MAX(CASE WHEN brand_name="Gold" THEN 1 ELSE 0)

/*Q1: SPAM

POST
||         ts       || user_id || post_id || action || extra ||
||2019-02-20|| 13453   ||  6         || view    || spam ||
||2019-02-20|| 13481   ||  7         || view    || null  ||

action: view, reaction, comment, report
Extra: spam, other (report reason)

1.count reported spam*/
SELECT extra, COUNT(*)
FROM post
WHERE ts = DATE(NOW()) - INTERVAL ‘1 DAY’ AND action = ‘report’
GROUP BY 1;

/*2. whats the percentage of extra*/
SELECT extra, COUNT(*)*100/ (SELECT COUNT(*) FROM post) AS extra_percentage
FROM post
WHERE ts = DATE(CURDATE()-1) AND action = ‘report’
GROUP BY 1;

/*3. Improve efficiency version with over()*/
SELECT extra, COUNT(*)*100/ SUM(COUNT(*)) OVER() AS extra_percentage
FROM post
WHERE ts = DATE(CURDATE()-1) AND action = ‘report’
GROUP BY 1;

/*TRUE_SPAM
user_id | post_id |

1.finding the true spam*/

SELECT COUNT(b.post_id)*100/COUNT(a.post_id) AS true_spam_percentage
FROM post a
LEFT JOIN spam b
ON a.post_id = b.post_id
WHERE a.action = ‘view’;

/*2.How to find users who abuse this spam system?
思路: 找出users中report数量比较多且true spam rate较低的那部分
Output：userid,  total_report, false_spam_rate/ false negative rate

Userid, total views, total report, false positive rate */

With temp1 as(
Select  userid, count(p1.action) num_view, count(p2.action) num_report
From post p1 full outer join post p2
on p1.userid = p2.userid and p1.action = ‘view’ and p2.action = ‘report’
Group by  p1.userid)
Temp2 as(
Select p3.userid, count(p3.postid)/count(t.postid) as fp_rate
From post p3 left join true_spam t
On p3.postid = t.postid and p3.userid = t.userid
Group by p3.userid),
Select
From temp1, temp2
Where temp1.userid = temp2.userid and num_view > _____ and num_report > ______ and fp_rate > _______


SELECT user_id, COUNT(*) AS total_report, (1-COUNT(DISTINCT b.post_id)/COUNT(*)) AS false_spam_rate
FROM post a
LEFT JOIN spam b
ON a.user_id = b.user_id AND a.post_id = b.post_id
WHERE a.action = ‘report’and a.extra = ‘spam’
GROUP BY 1
HAVING total_report >= 10 AND false_spam_rate >= 0.6
ORDER BY 3 DESC, 2 DESC;

/*3.What percent of yesterday's content views were on content reported for spam?*/

WITH sub AS (
SELECT DISTINCT post_id AS spam_id
FROM user_actions
WHERE extra = ‘SPAM’AND ts =  DATE(NOW()) - INTERVAL ‘1 DAY’
)

SELECT  COUNT(spam_id)/COUNT(post_id) AS spam_percent
FROM user_actions t1
LEFT JOIN sub
ON t1.pot_id = sub.spam_id
WHERE extra = ‘view’ AND ts =  DATE(NOW()) - INTERVAL ‘1 DAY’

/*Q2: Composer

composer
user_id|date|event (enter, post, exit)

1.post rate by date*/

SELECT date, SUM(CASE WHEN event = ‘post’ THEN 1 ELSE 0 END) /SUM(CASE WHEN event = ‘enter’ THEN 1 ELSE 0 END)  AS post_rate
FROM composer
GROUP BY 1;

/*user
User_id | country | date | dau (1 yes, 0 no)

2. general post success rate in the last 7 days ?*/

SELECT date, SUM(CASE WHEN event = ‘post’ THEN 1 ELSE 0 END) /SUM(CASE WHEN event = ‘enter’ THEN 1 ELSE 0 END) AS post_rate
FROM composer
WHERE DATEDIFF(day, date, CURDATE()) <= 7
GROUP BY 1;


/*3.average number of posts for dau yesterday by country*/


SELECT country, SUM(CASE WHEN event = ‘post’ THEN 1 ELSE 0 END)/COUNT(DISTINCT t1.user_id) AS avg_post
FROM composer t1
LEFT JOIN user t2
ON t1.user_id = t2.user_id
WHERE dau = 1 AND t1.date = DATE(CURDATE()-1)
GROUP BY 1
ORDER BY 2 DESC;

/*Q3: Search Rating

FB Search Rating: 请用户对于他搜索的结果进行评分来测量搜索引擎的Health
Search_Result || Result_ID || Postion || Rating
"Dog"             || 1234         || 1           || 5
"Dog"             || 1123         || 2           || 4


1. calculate Rating
Metrics: measure CTR, eg CTR (0.8, 1) →  5, (0.6-0.8) → 4, (0.4-0.6) → 3 …..

How do you take position in rating

Take weighted average for each search_result, and only focus on the first 5 or first 10 results*/

SELECT search_result, SUM(MAX(position)+1-position)/SUM(position)*Rating) AS weighted_rating
FROM search
WHERE Position >= 1 AND Position <= 10
GROUP BY search_result;

If we can make sure all searches have at least 10 results:
SELECT search_result, SUM(11-position)/55*Rating) AS weighted_rating
FROM search
WHERE Position >= 1 AND Position <= 10
GROUP BY search_result;

/*2.if overall calculate each row abs difference, else calculate RMSE*/

SELECT SQRT(SUM(SQUARE(t1.weighted_rating - t2.weighted_rating))) AS RMSE_diff
FROM
(SELECT search_result, SUM(11-position)/55*Rating) AS weighted_rating
FROM search
WHERE Position >= 1 AND Position <= 10
GROUP BY search_result) t1
LEFT JOIN
(SELECT search_result, SUM(11-position)/55*Rating) AS weighted_rating
FROM search2
WHERE Position >= 1 AND Position <= 10
GROUP BY search_result) t2
ON t1.search_result = t2.search_result;


/*Q4***: Fraud
account
 ad_account || date             || spend || status (open,close,fraud) ||
 123              || 2018-02-18 || 10       || open                                ||
 456              || 2018-02-18 || 1         || open                                ||
 123              || 2018-02-19 || 0         || fraud                                ||
 123              || 2018-02-20 || 5         || fraud                                ||

1.find the fraud rate in active accounts（active means spend>0）*/

/*Method 1:*/
SELECT SUM(CASE WHEN SUM(CASE WHEN status = ‘fraud’
     THEN 1 ELSE 0 END)>0
     THEN 1 ELSE 0 END)/COUNT(*) AS fraud_rate
FROM account
WHERE spend > 0
GROUP BY ad_account;

/*Method2:*/
WITH active AS(
SELECT account_id, SUM(CASE WHEN status=’fraud’THEN 1 ELSE 0 END) AS tag
FROM account
GROUP BY account
HAVING SUM(spend)>0
)
SELECT SUM(CASE WHEN tag>0 THEN 1 ELSE 0 END)/COUNT(*) AS fraud_percentage
FROM active

/*2. How many accounts labelled as fraud as of today?*/
/*Method1: */
SELECT COUNT(DISTINCT t2.ad_account) AS fraud_today
FROM account t1
LEFT JOIN account t2
ON t1.ad_account = t2.ad_account AND t1.date < t2.date
WHERE t1.status != ‘fraud’
AND t2.status = ‘fraud’
AND  t2.date = CURDATE();

/*Method2:*/

WITH sub AS(
Select Row_number() over (partition by account order by date asc) as rank, *
from table
Where status = 'Fraud'
)
Select count(account)
From sub
Where rank = 1 and  date = current_date()
