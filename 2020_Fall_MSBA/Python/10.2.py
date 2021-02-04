#purpose: get the counts of hour in dictionary
hand=open('mbox-short.txt')
hi=dict()

count=0

for lines in hand:
    words=lines.split()

    if len(words)==0:continue
    if words[0]=='From':

        hr=(words[5].split(':'))[0]
        hi[hr]=hi.get(hr,0)+1
print(hi)
