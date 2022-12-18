ans = {}
q = []
with open("input.txt") as f:
    for line in f:
        if line[0] == '$' and line[2]=='c':
            curr = line[5:]
            if curr[-1] == '\n':
                curr = curr[:-1]
            if curr == "..":
                q.pop()
                continue
            if curr == "/":
                q = ["/"]
                continue
            q.append(curr)
        if line[0]<='9' and line[0]>='0':
            params = line.split(' ')
            temp = q.copy()
            while len(temp)>0:
                dr = "".join(temp)
                if ans.get(dr) is None:
                    ans[dr] = 0
                ans[dr] += int(params[0])
                temp.pop()
        
            
tot = 0

free_space = 70000000 - ans["/"]
smallest = ans["/"]
print(free_space)
for k in ans:
    if free_space + ans[k] >= 30000000:
        smallest = min(smallest, ans[k])

print(smallest)

