"""https://www.hackerrank.com/challenges/coin-change/problem"""

def lcs(n,m,nums):
        arr=[[0]*(n+1) for _ in range(m)]
        for i in range(m):
            for j in range(n+1):
                if(j==0):
                    arr[i][j]=1
                elif(nums[i]>j):
                    arr[i][j]=arr[i-1][j]
                else:
                    arr[i][j]=arr[i-1][j]+arr[i][j-nums[i]]
        return arr[-1][-1]
n,m=map(int,input().split())
nums=list(map(int,input().split()))
print(lcs(n,m,nums))
