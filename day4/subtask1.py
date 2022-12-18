ans = 0
with open("input.txt") as f:
    for line in f:
        if line[-1] == '\n':
            line = line[:-1]
        inp = line.split(',')
        ranges = [rng.split('-') for rng in inp]
        flag1 = int(ranges[0][0]) <= int(ranges[1][0]) and int(ranges[0][1]) >= int(ranges[1][1])
        flag2 = int(ranges[0][0]) >= int(ranges[1][0]) and int(ranges[0][1]) <= int(ranges[1][1])
        if flag1 or flag2:
            ans+=1

print(ans)