#quick=input("a file's name: ")
hand=open('mbox-short.txt')

hi=dict()

for lines in hand:
    words=lines.split()
    # words.startswith('From') this will return strings, the others' returns lists
    if len(words)==0:continue
    if words[0]=='From':
        hi[words[2]]=hi.get(words[2],0)+1

print(hi)
