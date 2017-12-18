with open("input.txt") as txt:
    inlist = txt.readlines()

maze = []

for x in range(len(inlist)):
    maze += [int(inlist[x])]
#PART 1
loc = 0
jumps = 0

while loc in range(len(maze)):
    if loc in range(len(maze)):
        maze[loc] += 1
    loc += maze[loc] - 1
    jumps += 1

print(jumps)

#KILLER QUEEN DAISAN NO BAKUDAN BITES ZA DUSTO
maze = []
for x in range(len(inlist)):
    maze += [int(inlist[x])]
#PART 2
loc = 0
jumps = 0

while loc in range(len(maze)):
    #print(maze[loc])
    if loc in range(len(maze)):
        if maze[loc] < 3:
            maze[loc] += 1
            loc += maze[loc] - 1
        else:
            maze[loc] -= 1
            loc += maze[loc] + 1
    jumps += 1

print(jumps)