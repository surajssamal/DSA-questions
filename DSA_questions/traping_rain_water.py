


def solution(input_arr):
    n = len(input_arr)
    left_max=[0]*n
    right_max=[0]*n 
    left_max[0]=input_arr[0]

    for i in range(1,n):
       left_max[i]=max(left_max[i-1],input_arr[i]) 


    right_max[n-1]=input_arr[n-1]

    for i in range(n-2,-1,-1):
       right_max[i]=max(right_max[i+1],input_arr[i]) 

    res =0
    for i in range(n):
        res+=min(right_max[i],left_max[i])-input_arr[i]
    return res

input_arr = [0,2,0,3,1,0,1,3,2,1]
print(solution(input_arr))
