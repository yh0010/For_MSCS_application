count=0
sum=0
avg=0
while True:
    try:
        num=input('Enter a number: ')
        if num=='done':
            break
        count=count+1
        sum=sum+float(num)
        avg=sum/count
    except:
        print('invalid input, please enter digits')

print('Count: ',count)
print('Sum: ',sum)
print('Avg: ',avg)
