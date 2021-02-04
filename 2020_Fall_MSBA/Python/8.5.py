#The purpose of this hm is to slice strings and get the piece that we want from a text file

hand=open('mbox-short.txt')
count=0
for i in hand:
    if len(i)==0:continue
    if i.startswith('From'):
        o=i.strip().split()
        k=o[1].split('@')
        p=k[0].split('.')
        count=count+1
        print(p[0])
print('There were',count,'lines in the file')
