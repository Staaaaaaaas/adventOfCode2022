lf = -1
rt = []
ind = 0
ans = 0
def cmp(l1, l2):
    if type(l1)==int and type(l2)==int:
        if l1<l2: return 1
        if l1>l2: return -1
        return 0
    
    if type(l1)==list and type(l2)==int:
        return cmp(l1,[l2])
    if type(l2)==list and type(l1)==int:
        return cmp([l1],l2)
    for i in range(min(len(l1), len(l2))):
        ret = cmp(l1[i],l2[i])
        if ret!=0:
            return ret
    if len(l1)<len(l2):
        return 1
    if len(l1)>len(l2):
        return -1
    return 0

def str_to_li(line):
    ans = []
    stack = [ans]
    curr = ""
    for c in line:
        #print(c)
        if c==',':
            if len(curr):
                stack[-1].append(int(curr))
                curr = ""
        elif c=='[':
            stack[-1].append([])
            stack.append(stack[-1][-1])
        elif c==']':
            if len(curr):
                stack[-1].append(int(curr))
                curr=""
            stack.pop()
        elif c!=' ':
            curr+=c
    return ans[0]
with open("input.txt") as f:
    for line in f:
        if len(line)<2:
            
            continue
        if line[-1]=='\n':
            line = line[:-1]
        
        if lf ==-1:
            lf = str_to_li(line)
        else:
            rt = str_to_li(line)
            tmp = cmp(lf,rt)
            print(tmp)
            print(lf)
            print(rt)
            #print(tmp)
            ind += 1
            #print(ans, ind, tmp)
            if tmp==1:
                ans += ind
            lf = -1

print(ans)