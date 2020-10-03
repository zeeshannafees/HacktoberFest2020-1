x = int(input())
y = int(input())
z = int(input())
n = int(input())
per = []
f= []
for i in range(x+1):
    for j in range(y+1):
        for k in range(z+1):
            per.append([i,j,k])
            if i+j+k != n:
                f.append([i,j,k])
print(f)
