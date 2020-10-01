initial_state = [[1, 2, 3],
                [0, 4, 6], 
                [7, 5, 8]]
final_state=[[1, 2, 3], 
            [4, 5, 6],
            [7, 8, 0]]

N = 3 
char_value=65
def count(A,B):
    c=0
    for i in range(3):
      for j in range(3):
         if A[i][j] != B[i][j] and A[i][j]!=0:
             c+=1
    return c
def areSame(A,B): 
      
    for i in range(N): 
        for j in range(N): 
            if (A[i][j] != B[i][j]): 
                return 0
    return 1
def up_check(arr,i,j):
    arr[i][j],arr[i-1][j]= arr[i-1][j],arr[i][j]
    change=count(arr,final_state)
    arr[i-1][j],arr[i][j]=arr[i][j],arr[i-1][j]
    return change
def low_check(arr,i,j):
    arr[i][j],arr[i+1][j]= arr[i+1][j],arr[i][j]
    change=count(arr,final_state)
    arr[i+1][j],arr[i][j]=arr[i][j],arr[i+1][j]
    return change
def left_check(arr,i,j):
    arr[i][j],arr[i][j-1]= arr[i][j-1],arr[i][j]
    change=count(arr,final_state)
    arr[i][j-1],arr[i][j]=arr[i][j],arr[i][j-1]
    return change
def right_check(arr,i,j):
    arr[i][j],arr[i][j+1]= arr[i][j+1],arr[i][j]
    change=count(arr,final_state)
    arr[i][j+1],arr[i][j]=arr[i][j],arr[i][j+1]
    return change 

    
a=1
b=0
opened=[]
num=count(initial_state,final_state)
tup=(chr(char_value),num)
opened.append(tup)
closed=[]

while areSame(initial_state,final_state)!=1:
    print("Opened list : ",opened)
    print("closed list : ",closed)
    t=opened.pop(0)
    closed.append(t)
    count1=100
    count2=100
    count3=100
    count4=100
    if (a!=0):
        count1=up_check(initial_state,a,b)
    if(a!=2):
        count2=low_check(initial_state,a,b)
    if(b!=0):
        count3=left_check(initial_state,a,b)
    if(b!=2):
        count4=right_check(initial_state,a,b)
    
    minimum=min(count1,count2,count3,count4)
    com_list=[]
    com_list.append(count1)
    com_list.append(count2)
    com_list.append(count3)
    com_list.append(count4)
    com_list.sort()
    for i in com_list:
        if i!=100:
            char_value+=1
            t=(chr(char_value),i)
            opened.append(t)

    if minimum==count1:
        initial_state[a][b],initial_state[a-1][b]= initial_state[a-1][b],initial_state[a][b]
        a-=1
    elif minimum==count2:
        initial_state[a][b],initial_state[a+1][b]= initial_state[a+1][b],initial_state[a][b]
        a+=1
    elif minimum==count3:
        initial_state[a][b],initial_state[a][b-1]= initial_state[a][b-1],initial_state[a][b]
        b-=1
    else:
        initial_state[a][b],initial_state[a][b+1]= initial_state[a][b+1],initial_state[a][b]
        b+=1
    
