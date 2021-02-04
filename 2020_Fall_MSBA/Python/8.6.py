#Purpose: use input to collect a list of #s and get max&min

o=list()
while True:
    num=input('plz enter a #,thx:')

    if num=='done':
        break
    else:
        k=float(num) #either this or use try/except at the top
        o.append(k)
#o.pop() if there's no 'else', then the pop() could remove 'done' to not interfere with #s.

print('Maximum: ',max(o))
print('Minimum: ',min(o))
