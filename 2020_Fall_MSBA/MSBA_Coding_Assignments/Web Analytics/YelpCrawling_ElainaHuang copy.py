from bs4 import BeautifulSoup
import urllib.request
import re
import csv
import pandas as pd

x = True
while x is True:

    id = []
    rating = []
    review = []

    #first page
    url = 'https://www.yelp.com/biz/madame-vo-new-york'
    ourUrl = urllib.request.urlopen(url)

    soup = BeautifulSoup(ourUrl,'html.parser')

    counter = 0

    for i in soup.find_all('li', {'lemon--li__373c0__1r9wz margin-b3__373c0__q1DuY padding-b3__373c0__342DA border--bottom__373c0__3qNtD border-color--default__373c0__3-ifU'}):

        name = i.find('a', 'lemon--a__373c0__IEZFH link__373c0__1G70M link-color--inherit__373c0__3dzpk link-size--inherit__373c0__1VFlE')
        id.append(re.findall('.*[>](.*).*?[<]', str(name)))

        rating.append(re.findall('.*[="](.* star rating).*', str(i)))

        a1 = i.find('span','lemon--span__373c0__3997G raw__373c0__3rcx7')
        a2 = re.findall('.*[>](.*).*?[<]', str(a1))
        review.append(re.findall('.*[>](.*).*?[<]', str(a1)))
        counter += 1

#second page
    url = 'https://www.yelp.com/biz/madame-vo-new-york?start=20'
    ourUrl = urllib.request.urlopen(url)

    soup = BeautifulSoup(ourUrl,'html.parser')

    for i in soup.find_all('li', {'lemon--li__373c0__1r9wz margin-b3__373c0__q1DuY padding-b3__373c0__342DA border--bottom__373c0__3qNtD border-color--default__373c0__3-ifU'}):

        name = i.find('a', 'lemon--a__373c0__IEZFH link__373c0__1G70M link-color--inherit__373c0__3dzpk link-size--inherit__373c0__1VFlE')
        id.append(re.findall('.*[>](.*).*?[<]', str(name)))

        rating.append(re.findall('.*[="](.* star rating).*', str(i)))

        a1 = i.find('span','lemon--span__373c0__3997G raw__373c0__3rcx7')
        a2 = re.findall('.*[>](.*).*?[<]', str(a1))
        review.append(re.findall('.*[>](.*).*?[<]', str(a1)))
        counter += 1


#third page
    url = 'https://www.yelp.com/biz/madame-vo-new-york?start=40'
    ourUrl = urllib.request.urlopen(url)

    soup = BeautifulSoup(ourUrl,'html.parser')

    for i in soup.find_all('li', {'lemon--li__373c0__1r9wz margin-b3__373c0__q1DuY padding-b3__373c0__342DA border--bottom__373c0__3qNtD border-color--default__373c0__3-ifU'}):

        name = i.find('a', 'lemon--a__373c0__IEZFH link__373c0__1G70M link-color--inherit__373c0__3dzpk link-size--inherit__373c0__1VFlE')
        id.append(re.findall('.*[>](.*).*?[<]', str(name)))

        rating.append(re.findall('.*[="](.* star rating).*', str(i)))

        a1 = i.find('span','lemon--span__373c0__3997G raw__373c0__3rcx7')
        a2 = re.findall('.*[>](.*).*?[<]', str(a1))
        review.append(re.findall('.*[>](.*).*?[<]', str(a1)))
        counter += 1


#fourth page
    url = 'https://www.yelp.com/biz/madame-vo-new-york?start=60'
    ourUrl = urllib.request.urlopen(url)

    soup = BeautifulSoup(ourUrl,'html.parser')

    for i in soup.find_all('li', {'lemon--li__373c0__1r9wz margin-b3__373c0__q1DuY padding-b3__373c0__342DA border--bottom__373c0__3qNtD border-color--default__373c0__3-ifU'}):

        name = i.find('a', 'lemon--a__373c0__IEZFH link__373c0__1G70M link-color--inherit__373c0__3dzpk link-size--inherit__373c0__1VFlE')
        id.append(re.findall('.*[>](.*).*?[<]', str(name)))

        rating.append(re.findall('.*[="](.* star rating).*', str(i)))

        a1 = i.find('span','lemon--span__373c0__3997G raw__373c0__3rcx7')
        a2 = re.findall('.*[>](.*).*?[<]', str(a1))
        review.append(re.findall('.*[>](.*).*?[<]', str(a1)))
        counter += 1


#fifth page
    url = 'https://www.yelp.com/biz/madame-vo-new-york?start=80'
    ourUrl = urllib.request.urlopen(url)

    soup = BeautifulSoup(ourUrl,'html.parser')

    for i in soup.find_all('li', {'lemon--li__373c0__1r9wz margin-b3__373c0__q1DuY padding-b3__373c0__342DA border--bottom__373c0__3qNtD border-color--default__373c0__3-ifU'}):

        name = i.find('a', 'lemon--a__373c0__IEZFH link__373c0__1G70M link-color--inherit__373c0__3dzpk link-size--inherit__373c0__1VFlE')
        id.append(re.findall('.*[>](.*).*?[<]', str(name)))

        rating.append(re.findall('.*[="](.* star rating).*', str(i)))

        a1 = i.find('span','lemon--span__373c0__3997G raw__373c0__3rcx7')
        a2 = re.findall('.*[>](.*).*?[<]', str(a1))
        review.append(re.findall('.*[>](.*).*?[<]', str(a1)))
        counter += 1


    id = "\n".join(str(line) for line in id)
    rating = "\n".join(str(line) for line in rating)
    review = "\n".join(str(line) for line in review)


    df = pd.DataFrame({'ReviewID': [id], 'reviewRating': [rating], 'reviewText': [review], 'Total': 'There are '+str([counter])+ 'rows of data crawled from Yelp.com'})

    df.to_csv('YelpCrawling_ElainaHuang.csv', index = False)
    x = False
