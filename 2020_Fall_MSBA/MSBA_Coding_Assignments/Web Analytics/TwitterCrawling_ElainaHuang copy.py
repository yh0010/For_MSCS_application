import tweepy
import pandas as pd
import csv
import re

# TODO: Replace the keys you saved from the Twitter API at the appropriate locations
# auth = tweepy.auth.OAuthHandler(‘API Key’，‘API Secret Key')
# auth.set_access_token('Access token', 'Access token secret')
auth = tweepy.auth.OAuthHandler('1KqVc3OHfIK8u88u3MWUEsHKL', 'V61ZU8FV9Q8N6GqtUrDA9L471g1Aq7s34pOtwtcWlNtcjxlSRZ')
auth.set_access_token('1249209622461911043-HWAFGya1lkx8gLBMUzf6x6DVLNQCp6', 'lmPyDhVpSJu9PoVPQRleNTheBZi1qmUUiZgxu9RFw7tS9')

api = tweepy.API(auth)

def KeywordsPulling(file, keyword, limit):

    i = 0

    user_list = []
    follower_list = []
    location_list = []
    text_list = []

    for tweet in tweepy.Cursor(api.search, q = keyword, lang = "en").items(limit):
        user_list.append(tweet.user.screen_name)
        follower_list.append(tweet.user.followers_count)
        location_list.append(tweet.user.location)
        text_list.append(tweet.text.encode('utf-8'))


        i = i+1

    df = pd.DataFrame()
    df['Screen Name'] = user_list
    df['Number of Followers'] = follower_list
    df['Location'] = location_list
    df['Tweet'] = text_list

    print(str(i) + " rows of data successfully extracted under " + keyword)

    df.to_csv(file)

# Call the search function here
# TODO: The first paramter is the name of the output file, feel free to change it.
# TODO: The second parameter is the term you wish to search.
# TODO: The thrid paramter is the number of tweets you would like to crawl.
KeywordsPulling('ds.csv', 'datascience', 500)
KeywordsPulling('cs.csv', 'computerscience', 500)
KeywordsPulling('rb.csv', 'robotics', 500)
