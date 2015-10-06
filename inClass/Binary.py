#Nathan Berton Intro to Open Source 2015
# In class excercise Tuesday October 6th 


#input sorted array A, X
# A sorted low to high
#output 1 if x in A
# 		0 if !x in A
def binary_search(a,x):
	low = 0
	high = len(a)-1
	while low <= high:
		mid = (low + high)/ 2
		print "Low: " + str(low)
		print "High: " + str(high)
		print "Mid: " + str(mid)
		print "Mid Content: " + str(a[mid])
		if a[mid] == x:
			return 1
		#catch case for list size of 1
		elif x < a[mid]:
			#search lower valued list
			high = mid-1
		elif x > a[mid]:
			#search higher valued list
			low = mid+1		
	return 0
def main():
	#test array
	test = range(10)
	# print of test array 
	print "Test Array: " + str(test)
	#search variable
	search = 11
	print "Searching for: " + str(search)
	print binary_search(test,search)

if __name__ == '__main__':
	main()