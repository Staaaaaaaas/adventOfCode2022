total = 0
with open("input.txt") as f:
    for line in f:
        opponent = ord(line[0])-ord('A')
        outcome = ord(line[2])-ord('X')
        total += 3 * outcome
        total += (opponent + outcome - 1 + 3)%3+1
print(total)

