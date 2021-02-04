try:
    xh=float(input('Enter hours: '))
    xr=float(input('Enter rate: '))
    if xh<41 :
        a1=rate*hours
        print('Pay :',a1)
    else :
        a2=(xh-40)*1.5*xr+40*xr
    #a2=(xh-40)*1.5*xr+xh*xr
        #a2=xr*((xh-40)*1.5+xh)
        print('Pay :',a2)
except:
    print('Error, please enter numeric input')
