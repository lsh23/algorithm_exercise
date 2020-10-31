from collections import deque

dy = [1,0,-1,0]
dx = [0,1,0,-1]

def solution(v):
    q = deque([])
    n = len(v)
    visited = [[0]*n for _ in range(n)]

    radish = 0
    sweet_potato = 0
    potato = 0

    answer = [radish,sweet_potato,potato]

    for i in range(n):
        for j in range(n):
            if visited[i][j]==0:
                crops = v[i][j]
                q.append([i,j])
                answer[crops]+=1
                while q:
                    point = q.popleft()
                    y = point[0]
                    x = point[1]
                    for k in range(4):
                        next_y = y + dy[k]
                        next_x = x + dx[k]
                        if(next_y < 0 or next_y >= n or next_x < 0 or next_x >= n):
                            continue
                        if(visited[next_y][next_x]==1):
                            continue
                        if(v[next_y][next_x]!=crops):
                            continue
                        visited[next_y][next_x]=1
                        q.append([next_y,next_x])
            
    return answer