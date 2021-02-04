hand=open('mbox.txt')
hi=dict()
lala=list()

for lines in hand:
    words=lines.split()

    if len(words)==0:continue
    if words[0]=='From':
        hi[words[1]]=hi.get(words[1],0)+1

x,y=max(sorted([(val,key) for key,val in hi.items()],reverse=True))
print(y,x)
