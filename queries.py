n,m = [int(x) for x in input().split()]
arr = [int(x) for x in input().split()]
q= int(input())

modulos = [0]*m
for i in arr:
    modulos[i%m]+=1

for _ in range(q):
    i = [int(x) for x in input().split()]
    if i[0]==1:
        modulos[arr[i[1]-1]%m] -= 1
        arr[i[1]-1] = i[2]
        modulos[i[2]%m]+=1
    else:
        print(modulos[i[1]])