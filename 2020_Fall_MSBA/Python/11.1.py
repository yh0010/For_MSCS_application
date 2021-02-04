import re
count=0
x=input('Enter a Regular Expression: ')
hand=open('mbox.txt')
for line in hand:
    line=line.rstrip()
    q=re.search(x,line)
    if q is None:continue
    else :
        count=count+1
print('mbox.txt had',count,'that matched',x)
