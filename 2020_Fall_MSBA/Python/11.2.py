import re
c=list()
count=0
fil=input('Please Enter a file name: ')
hand=open(fil)
for line in hand:
    line=line.rstrip()
    lst=re.findall('New.+: ([0-9]+)',line)
    if len(lst)>0:
        count=count+1
        c.append(int(lst[0]))
    else :continue
    #str(lst)
print(int(sum(c)/count))
