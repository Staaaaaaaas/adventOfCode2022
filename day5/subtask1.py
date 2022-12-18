stacks = []
commands = False
with open("input.txt") as f:
    for line in f:
        n = len(line)
        if len(stacks) == 0:
            for i in range(n//4):
                stacks.append([])
        if n < 2:
            continue
        if commands:
            args = line.split(' ')
            m = int(args[1])
            i = int(args[3])-1
            if args[5][-1] == '\n':
                args[5]=args[5][:-1]
            j = int(args[5])-1
            rmd = []
            for l in range(m):
                rm = stacks[i].pop()
                rmd.append(rm)
            rmd.reverse()
            for rm in rmd:
                stacks[j].append(rm)
            continue
        if not commands and line[1]=='1':
            for s in stacks:
                s.reverse()
            commands=True
            continue
        for i in range(0,n,4):
            val = line[i+1]
            if val == ' ':
                continue
            stacks[i//4].append(val)
for s in stacks:
    print(s[-1], end='')