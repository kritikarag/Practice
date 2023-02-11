def get_skilled(required,already,Books,price):
    to_gain=0
    for skill in required:
        to_gain|=(1<<skill)
    for x in already:
        if to_gain&(1<<x):
            to_gain^=(1<<x)
    m=len(Books)
    //@cache
    def solve(i,mask):
        if mask==0:return 0
        if i==m:return float('inf')
        res=solve(i+1,mask)
        v=0
        for skill in Books[i]:
            if mask&(1<<skill):
                v|=(1<<skill)
        res=min(res,price[i]+solve(i+1,mask^v))
        return res
    b=solve(0,to_gain)
    return b if b<float('inf') else -1