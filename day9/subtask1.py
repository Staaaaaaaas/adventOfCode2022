h = [0,0]
t = [0,0]
vis = set()
move = {"L":[-1,0], "R":[1,0], "D":[0,-1], "U":[0,1]}
with open("input.txt") as f:
    for line in f:
        params = line.split(' ')
        if params[1][-1] == '\n':
            params[1] = params[1][:-1]
        for i in range(int(params[1])):
            
            new_h = [h[j]+move[params[0]][j] for j in range(2)]
            if abs(new_h[0] - t[0])>1 or abs(new_h[1] - t[1])>1:
                t = h.copy()
            h = new_h.copy()
            vis.add(str(t))
print(len(vis))

