hand=open('mbox-short.txt')
hi=dict()

for lines in hand:
    words=lines.split()

    if len(words)==0:continue
    if words[0]=='From':
        k=words[1].split('@')
        hi[k[1]]=hi.get(k[1],0)+1
print(hi)
