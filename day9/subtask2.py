knots = []
for i in range(10):
    knots.append([0,0])
move = {"L":[-2,0], "R":[2,0], "D":[0,-2], "U":[0,2]}
vis = set()
with open("input.txt") as f:
    for line in f:
        if line[-1]=='\n':
            line=line[:-1]
        args = line.split(' ')
        # inace ide na prethodno mesto
        for i in range(int(args[1])):
            vec = move[args[0]].copy()
            for j in range(10):
                if abs(vec[0]) < 2 and abs(vec[1])<2:
                    vec = [0,0]
                elif vec[0]==0:
                    knots[j][1]+=vec[1]//2
                elif vec[1]==0:
                    knots[j][0]+=vec[0]//2
                elif abs(vec[0])==2 and abs(vec[1])==2:
                    knots[j][0]+=vec[0]//2
                    knots[j][1]+=vec[1]//2
                else:
                    knots[j][0]+=(1 if vec[0]>0 else -1)
                    knots[j][1]+=(1 if vec[1]>0 else -1)
                if j != 9:
                    print(vec)
                    vec = [knots[j][0]-knots[j+1][0],knots[j][1]-knots[j+1][1]]
                else:
                    vis.add(tuple(knots[9]))
        # for j in range(10):
        #     print(knots[j])
        # print('-'*10)
print(len(vis))

                    

        