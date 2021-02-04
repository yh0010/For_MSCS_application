hand=open('mbox-short.txt')
import string
dtm=dict()
for lines in hand:
    lin=lines.translate(lines.maketrans(' ',' ',string.punctuation))
    words=lin.lower().split()
    if len(words)==0: continue
    for element in words:
        for char in element:

            dtm[char]=cc.get(char,0)+1

dtm=sorted([(val,key) for key,val in cc.items()],reverse=True)
#cc=list(cc.items())
#cc.sort(reverse=True) just to test the function
print(dtm)
