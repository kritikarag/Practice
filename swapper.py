s = input()
s = list(s)
res=0
while s:
    i = s.index(s[-1])
    if i == len(s)-1:
        res+=i/2
    else:
        res+=i
        s.pop()
    s.pop()
res = int(res)
print(res)
