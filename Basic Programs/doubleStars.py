print("Enter a number")
num = int(input())
print("Type 1 or 0")
num2 = int(input())
b = bool(num2)
if(b == True):
    for i in range(1, num+1):
        for j in range(1, i+1):
            print("*", end=" ")
        print()
elif (b == False):
    for i in range(num, 0, -1):
        for j in range(1, i+1):
            print("*", end=" ")
        print()
