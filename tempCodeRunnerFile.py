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