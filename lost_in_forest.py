from re import I


m=int(input())
ans=-1
final=-1
for i in range(1,m+1):
    count=0
    temp=i 
    while(temp!=1):
        if(temp%2):
            temp=(3*temp)+1
        else:
            temp=temp/2
        count+=1
    if(count>ans):
        ans=count
        final=i 
print(final)