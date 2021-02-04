try:
    num=float(input('Please enter a number between 0.0~1.0: '))
    if num>=0.9 and num<=1.0:
        print('A')
    if num<0.9 and num>=0.8:
        print('B')
    if num<0.8 and num>=0.7:
        print('C')
    if num<0.7 and num>=0.6:
        print('D')
    if num<0.6 and num>=0.0:
        print('C')
    if num<0.0 or num>1.0:
        print('Bad score')
except:
    print('Bad score')
