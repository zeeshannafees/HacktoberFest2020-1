# pattern printing
# print any pattern you like.

# Printing characters
def alphapat(n): 	
	
	num = 65
	for i in range(0, n): 
	
		for j in range(0, i+1): 
		
			ch = chr(num) 
			
			print(ch, end=" ") 
	
		num = num + 1 
		print("\r") 

n = 7
alphapat(n) 
