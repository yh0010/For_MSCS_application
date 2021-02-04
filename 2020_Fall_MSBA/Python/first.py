#while function
n = 5
while n > 0:
    print(n)
    n = n - 1
print('bbk')

#input string words
nam=input('who are you?')
print('welcome', nam)

#input digit
inp=input('Europe floor?')
usf=int(inp) + 1
print('US floor', usf)

#float/int
minute=23
float(minute/60)

#\n create new line
name = input('What is your name?\n')
print('hi ', name )

#digit/word string
prompt = 'What...is the airspeed velocity of an unladen swallow?\n'
speed = input(prompt)

#exer1.
nam=input("what's your name?\n")
print('Hello', nam)

#exer2.
hours=35
rate=2.75
print(round(hours*rate))
#print(pay) not working?

#exer3.
#//(int) /(could be float)

#exer4. input C to F
cel=input('what celsius temp do you want to convert to F?\n')
fah=int(cel)*(9/5)+32
print(fah)



inp = input('Enter Fahrenheit Temperature:')
try:
    fahr = float(inp)
    cel = (fahr - 32.0) * 5.0 / 9.0
    print(cel)
except:
    print('Please enter a number')
