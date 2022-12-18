st = set()
ans = 0

def val(c):
    if ord(c) <= ord('z') and ord(c) >= ord('a'):
        return ord(c)-ord('a')+1
    return ord(c)-ord('A')+27

with open("input.txt") as f:
    for line in f:
        st.clear()
        n = len(line)

        for i in range(n//2):
            st.add(line[i])
        for i in range(n//2):
            if line[n//2 + i] in st:
                ans+=val(line[n//2+i])
                break
print(ans)
                
        