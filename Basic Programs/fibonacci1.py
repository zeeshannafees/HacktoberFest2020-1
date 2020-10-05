def fibonacci(n):  
  
     a=0
     b=1
     print(a,b,end=" ")
      
     for i in range(n-2):
         c=a+b
         print(c,end=" ")
         a=b
         b=c
      
# take input from the user  
nterms = int(input("How many terms? "))  
# check if the number of terms is valid  
if nterms <= 0:  
   print("Plese enter a positive integer")  
else:  
   print("Fibonacci sequence:")  
   fibonacci(nterms) 
   
   
