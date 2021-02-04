#program to count total amount of tips+bills

while True: #start a while loop
    try: #start the failiure protection
        bills = float(input('How much is your original bill? ')) #assign input value into bills, convert the input in float digit
        percent_tip = float(input('what percentage is your tip? '))#assign input value into percent_tip, convert the input in float digit
        if bills >= 0 and percent_tip >= 0: #start if statement, if bill and percent_tip values are both >=0 then proceed
            def totalbill(bills, percent_tip): #create definition in totalbill with 2 parameters bills and percent_tip
                totalbill =  (bills * (percent_tip/100)) + bills #assign math function into sumup, assign the relationship between 2 parameters
                return totalbill #return sumup values
            finaltotal = totalbill(bills,percent_tip) #assign the defined function into finaltotal
            print('Your tip is based on ',percent_tip,'% is ',(percent_tip/100)*bills) #print as homework requested
            print('Your total bill is ',finaltotal) #return calculated value
        else : #if if statement was false, then proceed else statement
            print('cannot calculate negative digit') #alert user to re-input

    except : #if both the if and else statement were false, then proceed except statement
        print('please enter arabic number')
        break #break from the while loop
