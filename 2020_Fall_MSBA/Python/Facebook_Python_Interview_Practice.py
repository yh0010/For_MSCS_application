#1.bit manipulation, set kth bit to 0
n=37
k=3
m=37&. ~(1<<2)
print(m)

#2.count the number of times c appear in two consecutive spots inside s
s = 'Mississippis'
c = 's'
def countDuplicate2(s,c):
    prev_is_s = False # whether the previous character is 's'
    count = 0
    for l in s:
        if l == c:
            if prev_is_s is True:
                count += 1
            else:
                prev_is_s = True
        else:
            prev_is_s = False
    return count

print(countDuplicate2(s,c))

#3.find common words in order between 2 strings
firstText = 'AniMAL zoo iS fantastic on SaTUrdaY'
secondText = 'we ALL lOve aNImaL because sAtuRDay ZoO'

list_final = []
list_compare = []
Counter = 0

for words in firstText.casefold().split():
    if words in secondText.casefold().split():

        if words not in list_compare:
            list_final.append(firstText.split()[counter])
            list_compare.append(firstText.split()[counter].lower())
Counter += 1

print(list_final)

#4.ipv4 ；
#https://leetcode.com/problems/validate-ip-address/

from ipaddress import ip_address, IPv6Address
def validIPAddress(IP) :
    try:
        return "IPv6" if type(ip_address(IP)) is IPv6Address else "IPv4"
    except ValueError:
        return "Neither"

print(validIPAddress("192.168.1.1"))

#5. Number of words in a sentence 'Hello World' -> 2
sentence = 'Hello World'
words = sentence.split()
print(words)
print(len(words))

#6. avg length words in the sentence
#>>> sentence = "Hi my name is Bob"
#>>> words = sentence.split()
#>>> average = sum(len(word) for word in words) / len(words))
#>>> average

#test = sum((5 for i in range(5)))
#The removal of extra parentheses is ￼syntactic sugar: it has no impact on your algorithm.
#The (5 for i in range(5)) component is a generator expression which, on each iteration, yields the value 5. Your generator expression has 5 iterations in total, as defined by range(5). Therefore, the generator expression yields 5 exactly 5 times.
#sum, as the docs indicate, accepts any iterable, even those not held entirely in memory. Generators, and by extension generator expressions, are memory efficient. Therefore, your logic will sum 5 exactly 5 times, which equals 25.
#A convention when you don't use a variable in a closed loop is to denote that variable by underscore (_), so usually you'll see your code written as:

#7. count friends input: [[A,B],[A,C],[C,B],[B,D],[E]] output: {'A':2,'B':3,'C':2,'D':1,'E':0}
graph = [['A','C'],['B','A'],['C','D'],['B','C'],['E']]
from collections import defaultdict

friend_counter = defaultdict(int)

for group in graph:
    for person in group:
        friend_counter[person] += len(group) - 1

print(dict(friend_counter))

>>> {'A': 2, 'C': 3, 'B': 2, 'D': 1, 'E': 0}

#another solution for 7
import networkx as nx
graph = [['A','B'],['A','C'],['C','B'],['B','D']]

G = nx.Graph()
G.add_edges_from(graph)
G.add_node('E')

dict(G.degree)
>>> {'A': 2, 'B': 3, 'C': 2, 'D': 1, 'E': 0}

#another solution for 7
from collections import Counter
counts=Counter(word) # Counter({'l': 2, 'H': 1, 'e': 1, 'o': 1})
for i in word:
    print(i,counts[i])


#8. find the least prime Number
prime = [x for x in range(1,101) if x % 2 != 0 and x > 17]
print(prime)
#another solution for 8
num_list = []
final_list = []
for num in range(0,101):
    num_list.append(num)
print(num_list)
#another solution for 8
for num in num_list:
    if num % 2 == 0: continue
    else :
        if num > 17:
            final_list.append(num)
print(final_list)

#9. Flatten array: [1,2,3[4,5,[6]]] -> [1,2,3,4,5,6]
import numpy as np
array_0 = np.array([1,2,3,[4,5,[6]]])
array_1 = np.hstack(array_0)
array_2 = np.hstack(array_1)
print(array_2)

#anotehr solution for 9
array = [2,5,3,4,[8,5,7,[3,6]]]
flat_array = []
for num in array:
    if isinstance(num, int) is True:
        flat_array.append(num)
    else:
        for num2 in num :
            if isinstance(num2, int) is True:
                flat_array.append(num2)
            else:
                for num3 in num2 :
                    if isinstance(num3, int) is True:
                        flat_array.append(num3)
                    else: break
print(flat_array)

#10. Valid anagram

s = 'anagram'
t = 'nagaram'

def isAnagram(str1, str2):
    str1_list = list(str1)
    str1_list.sort()
    str2_list = list(str2)
    str2_list.sort()

    return (str1_list == str2_list)

print(isAnagram(s,t))
#another solution for 10
array1=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
print(len(array1))
array2=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

a="apple"
b="pleap"
for i in range(len(a)):
    array1[ord(a[i])-ord('a')] += 1
    array2[ord(b[i])-ord('a')] += 1

print(array1)
print(array2)


#11. Count number of substrings in a string
#https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/

#use dictionary, for I in word, if I not in d: d[I] = 1, else d[I] += 1, print(d)
#set a recorder, record parsed every element, in the next parsing, if word == None: word = recorder

list = [1,None,0,0,None,1,1,0] #-> [1,1,0,0,1,1,1,0]
new_list = []
recorder = 0
for num in list:
    if not num == None:
        new_list.append(num)
        recorder = num
    elif num == None:
        new_list.append(recorder)


print(new_list)

#12.# Simple Python program to compare dates
  
# importing datetime module
import datetime
  
# date in yyyy/mm/dd format
d1 = datetime.datetime(2018, 5, 3)
d2 = datetime.datetime(2018, 6, 1)
  
# Comparing the dates will return
# either True or False
print("d1 is greater than d2 : ", d1 > d2)
print("d1 is less than d2 : ", d1 < d2)
print("d1 is not equal to d2 : ", d1 != d2)

#13. find the distance of 2 points
import math
p1 = (3, 5)  # point 1 coordinate
p2 = (5, 7)  # point 2 coordinate
math.hypot(p2[0] - p1[0], p2[1] - p1[1]) # Linear distance
>>> 2.8284271247461903
