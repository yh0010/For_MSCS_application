try:
    hours=float(input('Enter hours: '))
    rate=float(input('Enter rate: '))

    if hours<41 :
        def computepay(hours,rate):
            a3=hours*rate
            return a3
        x=computepay(hours,rate)
        print('Pay :',x)
    else :
        def computepay(hours,rate):
            a2=rate*((hours-40)*1.5+40)
            return a2
        x=computepay(hours,rate)
        print('Pay :',x)

except:
    print('Error, please enter numeric input')
