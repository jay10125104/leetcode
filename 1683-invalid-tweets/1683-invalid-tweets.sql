# Write your MySQL query statement below
select tweet_id from Tweets t
where LENGTH(t.content)>15