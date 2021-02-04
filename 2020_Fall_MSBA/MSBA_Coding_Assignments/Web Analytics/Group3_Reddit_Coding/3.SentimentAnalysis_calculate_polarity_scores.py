import pandas as pd

import string

import nltk

from nltk.sentiment.vader import SentimentIntensityAnalyzer as SIA
#Here import the vader package

from pprint import pprint

nltk.download('vader_lexicon')

sia = SIA()

results = []
year = 2015
month = 1

x = True
y = True

#The first while loop ensures the loop keeps running if there's no corresponding file name then increase the month value to search again
#the x is determined by the nested loop
while x is True:
    try:
        #the second while loop ensures the loop keeps running until reaches the last file in the local folder
        #if the month value is 13 that means the year has to increase by 1
        while x is True:
            if month == 13:
                month = 1
                year += 1
            else:
                month = "{0:0=2d}".format(month) #this way the 1 digit integer will present in a 2-digits format to match the corresponding file name
                with open('/Users/elaina/Desktop/cleanned_tesla/{}{}_tesla_cleaned.csv'.format(year,month)) as f:
                    for line in f:
                        non_punc = line.translate(str.maketrans('', '', string.punctuation)) #remove punctuation
                        if len(non_punc) > 2: #skip residual meaningless characters
                            #print('im non punc',non_punc, len(non_punc))
                            pol_score = sia.polarity_scores(non_punc) #getting polarity scores
                            pol_score['comment'] = non_punc
                            results.append(pol_score)
                            #pprint(results[:7], width=100)

                df1 = pd.DataFrame.from_records(results) #create DataFrame

                #keep a record of all cleanned comments(322k)
                df3 = df1['comment']
                df3.to_csv('tesla_reddit_comments.csv', header = False, index=False)

                #here the compound scores is recommended by the vader guideline
                df1['label'] = 0
                df1.loc[df1['compound'] >= 0.05, 'label'] = 1
                df1.loc[df1['compound'] <= -0.05, 'label'] = -1

                #counting the total frequency of each polarity factor
                neu = 0
                pos = 0
                neg =0
                for num in df1['label']:
                    if num == 0:
                        neu += 1
                    if num == 1:
                        pos += 1
                    if num == -1:
                        neg += 1


                df2 = pd.DataFrame({'date':'{}-{}'.format(year,month),
                'positive':[pos],
                'negative':[neg],
                'neutral':[neu]
                })

                #create the file if doesn't exist
                if y is True:
                    df2.to_csv('201509-202011_polarity_scores.csv',mode='w+', index=False)
                    y = False
                else: #append mode without the header
                    df2.to_csv('201509-202011_polarity_scores.csv',mode='a', header=False, index=False)
                    if year == 2020 and int(month) == 11:
                        x = False


    except:
        month = int(month) + 1
