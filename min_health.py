#1ST APPROACH
def findminhealth(power,armor):
    n=len(power)
    ans=0
    arm=True
    for i in range(n):
        if power[i]>armor and arm==True:
            ans+=power[i]-armor
            arm=False
        else:
            ans+=power[i]
    if arm == True:
        temp = max(power)
        ans-=temp
        arm=False
    return ans+1

#2ND APPROACH
def findminhealth(power,armour):
    return sum(power)-min(armour,max(power))+1


power=list(map(int,input().split()))
armour = int(input())
print(findminhealth(power,armour))

#2nd 

