from numpy.polynomial.polynomial import Polynomial

adj = {}
val = {}
op = {}
with open("input.txt") as f:
    for line in f:
        if line[-1]=='\n':
            line = line[:-1]
        args = line.split(' ')
        args[0]=args[0][:-1]
        if len(args)==2:
            val[args[0]]=Polynomial(int(args[1]))
        else:
            adj[args[0]]=[args[1], args[3]]
            op[args[0]] = args[2]
op["root"]="-"
val["humn"]=Polynomial([0,1])
def dfs(u):
    if u in val:
        return val[u]
    if op[u]=="+":
        return dfs(adj[u][0]) + dfs(adj[u][1])
    elif op[u]=="-":
        return dfs(adj[u][0]) - dfs(adj[u][1])    
    elif op[u]=="*":
        return dfs(adj[u][0]) * dfs(adj[u][1])    
    elif op[u]=="/":
        return dfs(adj[u][0]) // dfs(adj[u][1])    
print(dfs("root").roots()[0])