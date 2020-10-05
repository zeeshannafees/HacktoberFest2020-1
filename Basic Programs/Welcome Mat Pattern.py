print("Mat size must be in a odd natural number")
a=int(input('Enter value of M'))
b=a * 3
x=3
for i in range(int(a/2)):
    for j in range(int((b-x)/2)):
        print('-', end ="")
    for j in range(int(x/3)):
        print(".|.", end ="")
    for j in range(int((b-x)/2)):
        print('-', end = "")
    print("")
    x=x+6

for i in range(int((b-7)/2)):
    print('-', end = "")
print("WELCOME",end ="")
for i in range(int((b-7)/2)):
    print('-', end = "")
print("")
x=x-6
for i in range(int(a/2)):
    for j in range(int((b-x)/2)):
        print('-', end ="")
    for j in range(int(x/3)):
        print(".|.", end ="")
    for j in range(int((b-x)/2)):
        print('-', end = "")
    print("")
    x=x-6
