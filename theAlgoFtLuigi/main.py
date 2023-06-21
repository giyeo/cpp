import random
import time
def generate_random_numbers(n):
    random_numbers = []
    
    for _ in range(n):
        random_number = random.randint(1, 10000)  # Generate a random number between 1 and 100
        random_numbers.append(random_number)
    
    return random_numbers


# X = generate_random_numbers(3000)
X = [50 ,46 ,100 ,66 ,81 ,28 ,70 ,64 ,76 ,14 ,61 ,75 ,86 ,35 ,88 ,17 ,51 ,97 ,99 ,21 ,56 ,68 ,67 ,92 ,18 ,47 ,16 ,82 ,95 ,12 ,65 ,63 ,94 ,77 ,37 ,54 ,43 ,72 ,10 ,33 ,20 ,55 ,26 ,42 ,90 ,71 ,39 ,25 ,74 ,15]
n = len(X)

start = time.time()
#Group the elements of X into n/2 pairs of elements,
# arbitrarily, leaving one element unpaired if there is an odd number of elements.
L = [] 
temp = []
straggler = -1
if(n % 2 == 1):
	straggler = X[-1]
	X.pop(-1)

for i, each in enumerate(X):
	temp.append(each)
	if (i % 2 == 1):
		L.append(temp)
		temp = []

#print(L, straggler)
#O QUE TENHO, UM VECTOR E UM VECTOR<VECTOR>

#Perform n / 2 comparisons, one per pair,
# to determine the larger of the two elements in each pair.

for each in L:
	if(each[0] > each[1]):
		tmpNum = each[1]
		each[1] = each[0]
		each[0] = tmpNum

#print(L, straggler)

#Recursively sort the [n / 2] larger elements from each pair,
#creating a sorted sequence S of [n/2] of the input elements
#in ascending order.

S = []

for each in L:
	S.append(each[1])

S = sorted(S)

#print(L, straggler)
#print(S)
#2 VECTORS E 1 VECTOR<VECTOR>

#4 Insert at the start of S the element that was paired
#  with the first and smallest element of S

# firstSmallest = 0
# toPop = 0
# for i, each in enumerate(L):
# 	if(each[1] == S[0]):
# 		firstSmallest = each[0]
# 		toPop = i
# 	else:
# 		each.pop(1)
# L.pop(toPop)
# S.insert(0, firstSmallest)

#print("----------")
#print("L [n/2]", L, straggler)
#print("----------")
#print("S", S)
#5 Insert the remaining [n / 2] - 1 elements of X \ S into S, one at a time
#with a specially chosen insertion ordering described below.
#Use binary search in subsequences of S (as described below)
# to determine the position at which each element should be inserted.
counter = 0
def binary_search_insert(S, n):
    left = 0
    right = len(S) - 1

    while left <= right:
        mid = (left + right) // 2
        #print("RUN:",counter,">",mid,":",left,",",right,"{\}",S[mid],n)
        if S[mid] == n:
            # If the number already exists in the list, insert it at the rightmost position
            S.insert(mid + 1, n)
            return S

        if n < S[mid]:
            right = mid - 1
        else:
            left = mid + 1

    S.insert(left, n)
    return S

for each in L:
	index = binary_search_insert(S, each[0])
	counter += 1
if(straggler != -1):
	index = binary_search_insert(S, straggler)

end = time.time()
#print("---------------------")
print(end - start)

print("final result", "yes" if S == sorted(S) else "no")

