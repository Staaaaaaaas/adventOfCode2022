total = 0
with open("input.txt") as f:
    for line in f:
        opponent = ord(line[0])-ord('A')
        me = ord(line[2])-ord('X')
        total += me+1
        if me == opponent:
            total += 3
        elif (me - opponent + 3)%3 == 1:
            total += 6
print(total)
