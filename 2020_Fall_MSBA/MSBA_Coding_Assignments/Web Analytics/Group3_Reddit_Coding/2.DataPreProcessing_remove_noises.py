import pandas as pd
import re

file_year = 2015
file_month = 1

x = True

#these codes remove the weblink residual from the documents through regex
while x is True:
    try:
        while x is True:
            if file_month == 13:
                file_month = 1
                file_year += 1
            else:
                file_month = "{0:0=2d}".format(file_month)
                with open('{}{}_tesla_cooments.csv'.format(file_year,file_month), 'r+') as f:
                    ls = []
                    for line in f:
                        if '[deleted]' not in line:
                            if '[ deleted ]' not in line:
                                line = re.sub(r'https?:\/\/.*[)]','',line)
                                line = re.sub(r'https?:\/\/.*[jpg]','',line)
                                line = re.sub(r'https?:\/\/.*[png]','',line)
                                line = re.sub(r'https?:\/\/.*[html]','',line)
                                line = re.sub(r'https:\/\/.*[/]','',line)
                                line = re.sub(r'ur\.com\/.*','',line)

                                ls.append(line)

                    df = pd.DataFrame(ls)
                    df.to_csv('/Users/elaina/Desktop/cleanned_tesla/{}{}_tesla_cleaned.csv'.format(file_year,file_month),index=False)

                    file_month = int(file_month) + 1

                    if file_year == 2020 and int(file_month) == 12:
                        x = False


    except:

        file_month = int(file_month) + 1
