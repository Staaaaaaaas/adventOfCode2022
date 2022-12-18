monks = []
params = []

mods = []
for i in range(24):
    mods.append([])
cnt = 0
class Monkey:
    def __init__(self, start_items, op, tst, ift, iff):
        self.items = start_items
        self.op = op
        self.tst = tst
        self.ift = ift
        self.iff = iff
        self.tot=0
    def inspect(self):
        for item in self.items:
            self.tot+=1
            for j in range(2,24):

                if self.op[0] == "+":
                    mods[j][item] += int(self.op[1:])
                elif self.op[0] == "*":
                    mods[j][item] *= int(self.op[1:])
                else:
                    mods[j][item] *= mods[j][item]
                
                mods[j][item]%=j
            #item //=3
            if mods[self.tst][item] == 0:
                monks[self.ift].items.append(item)
            else:
                monks[self.iff].items.append(item)
        self.items = []

def cmp(monk):
    return monk.tot

with open("input.txt") as f:
    for line in f:
        if line[-1]=='\n':
            line = line[:-1]
        args = line.split(' ')
        if len(args) < 3:
            continue
        if args[2]=='Starting':
            li = []
            for i in range(4,len(args)):
                if args[i][-1]==',':
                    args[i]=args[i][:-1]
                
                for j in range(2,24):
                    mods[j].append(int(args[i])%j)
                    
                
                li.append(cnt)
                cnt+=1
            
            params.append(li)
        elif args[2]=="Operation:":
            if args.count("old")==2:
                params.append("sq")
            else:
                params.append(args[-2]+args[-1]) 
        elif args[2]=='Test:':
            params.append(int(args[-1]))
        elif args[5]=="true:":
            params.append(int(args[-1]))
        elif args[5]=="false:":
            params.append(int(args[-1]))
            monks.append(Monkey(*params))
            #print(params)
            params = []


# for j in range(2,24):
#     print(mods[j])

for i in range(10000):
    for mnk in monks:
        mnk.inspect()
    # if (i+1)%1000 == 0 or i==19:
    #     for m in monks:
    #         print(m.tot)
    #     print('-'*20)
    
monks.sort(key=cmp, reverse=True)
print(monks[0].tot*monks[1].tot)
