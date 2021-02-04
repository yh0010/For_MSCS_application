count=0
sum=0
large=None
small=None

while True:
    try:
        str=input('Enter a number: ')
        if str=='done':
            break
        num=float(str)
        count=count+1
        sum=sum+num
        if large is None or large<num:
            large=num
        if small is None or small>num:
            small=num
    except:
        print('invalid input, please enter digits')

print('Count: ',count)
print('Sum: ',sum)
print('Max: ',large)
print('Min: ',small)
