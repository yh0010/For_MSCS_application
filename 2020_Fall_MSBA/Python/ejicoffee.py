# michael = 'Eric, the half a bee.'
# print_twice(michael)

# Coffee class definition
class Coffee:
    bean = ''
    # Coffee class constructor
    def __init__(self, bean_name):
        self.bean = bean_name
        print("construct coffee: " + bean_name)

# Coffee class object
# starbucks_coffee = Coffee("Starbucks")
# Coffee class object
# blue_bottle_coffee = Coffee("Blue Bottle")

class Latte(Coffee):
    milk = True

    def Print(self):
        print("I'm latte")

class Mocha(Coffee):
    chocolate = True

    def Print(self):
        print("I'm mocha")

bean = "Peets"

# make coffee function
# arg:
#   initial(str) - person's initial
def make_coffee(initial):
    if initial == "yh":
        return Latte(bean)
    if initial == "ym":
        return Mocha(bean)


coffee = make_coffee("yh")
coffee.Print()
coffee = make_coffee("ym")
coffee.Print()
