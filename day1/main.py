s = []
current = 0
with open("input.txt") as f:
    for line in f:
        inp = line
        if inp == '\n':
            s.append(current)
            current = 0
        else:
            current+=int(inp)
s.append(current)
s.sort(reverse=True)
# print(s[0])
print(s[0]+s[1]+s[2])
