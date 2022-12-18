ans = 0

def val(c):
    if ord(c) <= ord('z') and ord(c) >= ord('a'):
        return ord(c)-ord('a')+1
    return ord(c)-ord('A')+27

sts = [set()]*3

with open("input.txt") as f:
    for i,line in enumerate(f):
        line = line[:-1]
        sts[i%3] = set(line)
        if(i%3 == 2):
            ans+= val((sts[0].intersection(sts[1])).intersection(sts[2]).pop())
            for st in sts:
                st.clear()
print(ans)