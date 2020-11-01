n,m,x,y,k = map(int,input().split())

map_infos = [[0]*m for _ in range(n)]

map_infos

for i in range(n):
    map_info = [ int(x) for x in input().split()]
    map_info
    for j in range(m):
        map_infos[i][j] = map_info[j]

commands = [ int(x) for x in input().split()]

# 1-6
# 3-4
# 2-5

bottom = 0
up = 0
left = 0
right = 0
down = 0
top = 0


for command in commands:
    _bottom = bottom
    _left = left
    _right = right
    _top = top
    _up = up
    _down = down
    if(command == 1):
        next_x = x
        next_y = y+1
        if(0<=next_y<m):
            bottom = _right
            left = _bottom
            right = _top
            top = _left
            if(map_infos[next_x][next_y]==0):
                map_infos[next_x][next_y] = bottom
            else:
                bottom = map_infos[next_x][next_y] #주사위 바닥면 = map_infos[next_x][next_y]
                map_infos[next_x][next_y] = 0
            print(top)
        else:
            pass
    if(command == 2):
        next_x = x
        next_y = y-1
        if(0<=next_y<m):
            bottom = _left
            left = _top
            right = _bottom
            top = _right
            if(map_infos[next_x][next_y]==0):
                map_infos[next_x][next_y] = bottom
            else:
                bottom = map_infos[next_x][next_y] #주사위 바닥면 = map_infos[next_x][next_y]
                map_infos[next_x][next_y] = 0
            print(top)
        else:
            pass
    if(command == 3):
        next_x = x-1
        next_y = y
        if(0<=next_x<n):
            bottom = _up
            up = _top
            down = _bottom
            top =  _down
            if(map_infos[next_x][next_y]==0):
                map_infos[next_x][next_y] = bottom
            else:
                bottom = map_infos[next_x][next_y] #주사위 바닥면 = map_infos[next_x][next_y]
                map_infos[next_x][next_y] = 0
            print(top)
        else:
            pass
    if(command == 4):
        next_x = x+1
        next_y = y
        if(0<=next_x<n):
            bottom = _down
            up = _bottom
            down = _top
            top =  _up
            if(map_infos[next_x][next_y]==0):
                map_infos[next_x][next_y] = bottom
            else:
                bottom = map_infos[next_x][next_y] #주사위 바닥면 = map_infos[next_x][next_y]
                map_infos[next_x][next_y] = 0
            print(top)
        else:
            pass

#    2
#  4 1 3
#    5
#    6

# 좌우 커맨드로는 4 1 3

# 상화 커맨드로는 2 1 5 6

# 동 서 북 남
# 1  2  3  4

# 이동한 칸에 쓰여있는 수가 0 이면 주사위의 바닥면에 쓰여 있는 수가 바닥으로 복사
# 0이 아니면 바닥면에 있는 수가 주사위의 바닥면으로 복사되고 해당 칸은 0으로
