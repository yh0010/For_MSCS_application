try:
    num=float(input('Please enter a number between 0.0~1.0: '))
    def computegrade():
        if num>1.0 or num<0.0:
            print('Bad score')
        elif num>=0.9:
            print('A')
        elif num>=0.8:
            print('B')
        elif num>=0.7:
            print('C')
        elif num<=0.6:
            print('D')
    computegrade()
except:
    print('Bad score')
