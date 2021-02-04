hand=open('words.txt')
ac=dict()
for i in hand:
    lines=i.split()
    for q in lines:
        words=q.split()
        if not q in ac:
            ac[q]=1
        else:
            ac[q]=ac[q]+1
if 'can' in ac:
    print('haha')
else:
    print('oh no')
