def minimizeMemory(processes, m):
        n=len(processes)
        if(n < m):
            return -1
        res = 0
        for i in range(m):
            res +=processes[i] 
        curr_sum = res
        for i in range(m,n):
                curr_sum +=processes[i] - processes[i-m]
                res = max(res,curr_sum)
        return sum(processes)-res

m = int(input())
processes=list(map(int,input().split()))
print(minimizeMemory(processes,m))