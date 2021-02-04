x=open('romeo.txt')
c=list()
for i in x:
    o=i.split()
    #print(o)
    for mm in o:
        if mm in c: continue
        else: c.append(mm)
c.sort()
print(c)
