#quick=input("enter a file's name: ")
hand=open('mbox-short.txt')
hi=dict()
#hand=('From fantasy to old days\n
       #From curly hair to straight\n
       #From apple tree to pears\n')
for lines in hand:
    words=lines.split()

    if len(words)==0:continue
    if words[0]=='From':
        hi[words[1]]=hi.get(words[1],0)+1

    #or
    #for w in words:
        #if len(w)==0:continue
        #if w=='From':
            #hi[words[1]]=hi.get(words[1],0)+1

#lines='From fantasy to old days'
#words=['From', 'fantasy', 'to', 'old', 'days']
#words[0]
#w='From'
#words[1]='fantasy'
#hi={'fantasy':1,'apple':2}


print(hi)#this is 9.3

print(max(hi.values()))
