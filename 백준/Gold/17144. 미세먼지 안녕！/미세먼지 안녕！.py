import sys

def isIn(i, j): return 0 <= i and i < R and 0 <= j and j < C
def isAC(i, j): return j == 0 and (i == upper or i == down)

def diffuse_dust():
    global arr
    newarr = [tmp[:] for tmp in arr]
    
    for i in range(R):
        for j in range(C):
            if arr[i][j] <= 0: continue
            curr_val = arr[i][j] // 5
            cnt = 0
            for k in range(4):
                y, x = i+dy[k], j+dx[k]
                if isAC(y, x) or not isIn(y, x): continue
                
                newarr[y][x] += curr_val
                cnt += 1

            newarr[i][j] -= curr_val * cnt
    arr = newarr
    return

def blow_wind():
    global arr
    newarr = [tmp[:] for tmp in arr]
    newarr[upper][1] = 0
    newarr[down][1] = 0

    for j in range(1, C-1):
        newarr[upper][j+1] = arr[upper][j]
    for i in range(upper, 0, -1):
        newarr[i-1][C-1] = arr[i][C-1]
    for j in range(C-1, 0, -1):
        newarr[0][j-1] = arr[0][j]
    for i in range(upper-1):
        newarr[i+1][0] = arr[i][0]

    for j in range(1, C-1):
        newarr[down][j+1] = arr[down][j]
    for i in range(down, R-1):
        newarr[i+1][C-1] = arr[i][C-1]
    for j in range(C-1, 0, -1):
        newarr[R-1][j-1] = arr[R-1][j]
    for i in range(R-1, down+1, -1):
        newarr[i-1][0] = arr[i][0]
    arr = newarr
    return

input = sys.stdin.readline
dx, dy = [0, 1, 0, -1], [-1, 0, 1, 0]
R, C, T = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(R)]
upper, down = -1, -1

for i in range(R):
    if arr[i][0] == -1:
        upper, down = i, i+1
        break

for i in range(T):
    diffuse_dust()
    blow_wind()

total_sum = 0
for i in range(R):
    for j in range(C):
        if arr[i][j] == -1: continue
        total_sum += arr[i][j]

print(total_sum)