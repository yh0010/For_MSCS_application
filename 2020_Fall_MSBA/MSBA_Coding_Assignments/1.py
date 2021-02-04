# def change(amount):
#
#   if amount < 24 or amount > 1000:
#     return 'exceed range'
#
#   lst = []
#
#   while True:
#     if (amount/5).is_integer():
#       for i in range(int(amount/5)):
#         lst.append(5)
#       return lst
#
#     lst.append(7)
#     amount += -7
#
#     while amount > 0:
#       break
#
# change(24)

def whendoesitreach(initialnumber,ratesdaily,goal):
    daycounter = 0
    while initialnumber < goal:
        initialnumber += ratesdaily*initialnumber
        daycounter += 1
    print(initialnumber, daycounter)

whendoesitreach(1000, .1, 1000000)
