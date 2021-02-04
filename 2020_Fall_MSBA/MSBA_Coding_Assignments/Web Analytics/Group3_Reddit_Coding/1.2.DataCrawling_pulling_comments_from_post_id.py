import psycopg2
import praw
import re
import pandas as pd

reddit = praw.Reddit(client_id='6y59IWYJKhILkQ',
                     client_secret='7jZf0cl6qKlab-CjOXZTP85sCiDChQ',
                     user_agent="Elaina's api2",
                     username='Elaine0010_',
                     password='Qwer`123')

conn = psycopg2.connect("host=localhost dbname=elaina user=postgres")

cur = conn.cursor()
#same thing above connect to the reddit and the postgres

#start definition because it's easier this way
#where i pass the year that's 1 year smaller than the intended starting year
def queryid(year):
    #print('begin',year)
    symbol = '{"'
    #this is the only constant value so I decide to put it at the beginning just for the convience sake

    #the for loop lopps 5 times it's 5 because 2020-2016+1 is 5 years in total
    for i in range(5):#should be 5
        year += 1
        month = 0
        x = True
        #so my point is every loop the year increment by 1 and the month reset to 0 as well as x reset to True

        #start the while loop
        while x is True:
            #i notice that it's important to clear up the ls to an empty list inside the while loop, otherwise
            #the output will only keep adding the new contents below the first output, that is not what I want
            #I need the file separated by month, but that's surprising though, usually my file would be overwritten...need to be alert to this situation
            ls = []
            month = int(month) + 1 #the fact I have to int() it is because after the format() function the value turns into a string type
            month = "{0:0=2d}".format(month) #this way i can have a 2-digit format when doing query
            #or {:02d} both work
            query = """SELECT id FROM reddit_tesla_title WHERE created_time like '{}{}-{}%' """.format(symbol, year, month)#format is a great funciton for substitution

            #**** I feel all those print() really help me to track
            #print(cur.execute(query),'this is printing query',year,'-',month)

            record = cur.fetchall()
            #print(record, 'this is record')
            #conn.commit()#don't know the difference with or without this

            #now the crawling begin
            #had to use regex to get exact id
            for id in record:
                obj1 = re.findall('[{](.*)[}]',str(id))
                #print(id, 'printing id')

                #this will turn id automatically into string type
                for id in obj1:
                    submission = reddit.submission(id=id)

                    submission.comments.replace_more(limit=None)
                    for comment in submission.comments.list():
                        ls.append(comment.body)

            df = pd.DataFrame(ls)


            df.to_csv('{}{}_tesla_reddit_comments.csv'.format(year,month), index=False)


            #print('the end',year,'-',month,record)
            if int(month) == 12:#should be 12
            #stops when month is 12, and go back for next year
                x = False

queryid(2015)

#here i wrote a recursive function partially but chose to switch to a for loop instead because my friend suggested that
#said, recursive could make stack overflow happen

# def queryid(self, year):
#     print('begin',self)
#     symbol = '{"'
#
#     x = True
#     month = 0
#
#     if (self < 2020-2016+1):
#         year += 1
#         month = 0
#         self += 1
#         while x is True:
#             month = int(month) + 1
#             month = "{0:0=2d}".format(month)
#             #or {:02d} both work
#             query = """SELECT id FROM reddit_tesla_title WHERE created_time like '{}20{}-{}%' """.format(symbol, year, month)
#
#             cur.execute(query)
#
#             record = cur.fetchall()
#             print(year,'-',month,record)
#             if int(month) == 12:
#                 x = False
#                 queryid(self, year)
#     else: return
# #
#
#             #conn.commit()
#
# queryid(0,15)
