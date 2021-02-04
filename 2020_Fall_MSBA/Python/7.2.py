
txt=input("Enter file's name: ")
if txt=='na na boo boo':
    print('ok')
else:
    hand=open(txt)
    d=0
    count=0
    for mike in hand:
        if not mike.startswith('X-DSPAM-Confidence:'): continue
        k=mike.find('X-DSPAM-Confidence:')
        count=count+1
        c=float(mike[k+20:])
        d=d+c
    print('Average spam confidence: ',d/count)
