import praw #reddit official library
import datetime as dt #important to tansfer reddit time code into human-reable timestamp
import psycopg2 #postgres library
import re #regex

#build connection to reddit through api
reddit = praw.Reddit(client_id='lB_qerwJrJDa0w',
                     client_secret='HOvfxaHfNyJG7HxjpaRBYCVSIL-Mrw',
                     user_agent="Elaina's api",
                     username='Elaine0010_',
                     password='Qwer`123')

#list of all the subreddits will be crawled
title = ['teslamotors','TeslaModel3','TeslaModelX','TeslaModelY']

for name in title:
    #standard reddit crawling codes
    subreddit = reddit.subreddit(name)

    top_subreddit = subreddit.top(limit = 1000)

#==========#
    #start connection to postgres
    conn = psycopg2.connect("host=localhost dbname=elaina user=postgres")
    #by using a cursor(dont know what that is)
    cur = conn.cursor()

    for submission in top_subreddit:
        if 'Tesla' in submission.title or 'tesla' in submission.title or 'model' in submission.title or 'Model' in submission.title:
            test = dt.datetime.fromtimestamp(submission.created)
            if test.year == 2014: continue #ignore 2014 because we only want 2015-2020
            else:
                cur.execute("INSERT INTO reddit_tesla_title(title,id,comments_num,created_time) VALUES (%s,%s,%s,%s)" , ([submission.title],[submission.id],[submission.num_comments],[dt.datetime.fromtimestamp(submission.created)]) )
                #here we have title, post id, nums of comment, and timestamp

    conn.commit()
