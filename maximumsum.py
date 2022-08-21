def maximumsum(stock,k):
    sum,m,x=0,0,1
    for i in range(len(stock)-k+1):
        a=stock[i:i+k]
        x=1
        sum=0
        for j in a:
            if(a.count(j)>1):
                x=0
                break
            else:
                sum+=j
        if(x==1 and m<sum):
            m=sum
    if(m==0):
        return -1
    else:
        return m

print("Enter stock prices:")
stock=list(map(int,input().split()))
k=int(input("Enter k value:"))
print("\nResult=",maximumsum(stock,k))