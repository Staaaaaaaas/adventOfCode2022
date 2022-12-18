ans = 0
with open("input.txt") as f:
    for line in f:
        if line[-1] == '\n':
            line = line[:-1]
        inp = line.split(',')
        ranges = [rng.split('-') for rng in inp]
        tmp = [[int(rr) for rr in ranges[0]],[int(rr) for rr in ranges[1]]]
        ranges = tmp
        ranges.sort()
        flag = ranges[0][1] < ranges[1][0]
        print(ranges)
        if not flag:
            ans+=1

print(ans)