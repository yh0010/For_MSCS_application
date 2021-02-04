import re #import regex module
from statistics import mean #import function mean from stats module

handle = open('new_purchases_c.txt','r') #create a handle to store the read-only version file
NY_ls = list() #create list for NY specific
SF_ls = list() #create list for SF specific
NY_count = 0 #assign 0 value to NY_count variable
SF_count = 0 #assign 0 value to SF_count variable

#start for loop
for i in handle :
    ny_cost = re.findall('New York.*?([0-9.]+)',i) #extract the corresponding transaction amount from NY records
    NY_count += len(ny_cost) #assign the number of extracted value from above into the NY_count
    NY_ls += ny_cost #assign the extracted value into NY_ls

#repeat the same process for San Francisco
    sf_cost = re.findall('San Francisco.*?([0-9.]+)',i)
    SF_count += len(sf_cost)
    SF_ls += sf_cost

#nest a for loop to convert 'list' into 'float' number for later arithmatic purpose
NY_ls = [float(i) for i in NY_ls]
SF_ls = [float(i) for i in SF_ls]

#handle.close()
n1 = mean(NY_ls)
n2 = round(mean(SF_ls),3)

l1 = 'The average transaction amount based on the {} transactions in New York is {}\n'.format(NY_count, n1)#use the mean function from stats module
l2 = 'The average transaction amount based on the {} transactions in New York is {}\n'.format(SF_count, n2)#rounded to 3 decimals
l3 = 'New York has a higher average transaction amount than San Francisco'

with open('output.txt','w') as file:
    file.writelines([l1,l2,l3])


file.close()
handle.close()
