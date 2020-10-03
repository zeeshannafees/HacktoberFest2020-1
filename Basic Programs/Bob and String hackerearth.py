from collections import Counter 
def ans(s,t):
    dict1=Counter(s)
    dict2=Counter(t)
    return (len(s)+len(t))-(2*sum((dict1&dict2).values()))
    
n=int(input())
for i in range(n):
    s=input()
    t=input()
    print(ans(s,t))