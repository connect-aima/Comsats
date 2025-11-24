from collections import deque

def bfs_maze(maze, start, goal):
    rows, cols = len(maze), len(maze[0])
    directions = [(-1,0), (1,0), (0,-1), (0,1)]  # Up, Down, Left, Right
    
    queue = deque([(start, [start])])  # (position, path)
    visited = set([start])
    
    while queue:
        (x, y), path = queue.popleft()
        
        if (x, y) == goal:
            return path  # shortest path found
        
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < rows and 0 <= ny < cols and maze[nx][ny] == 0 and (nx, ny) not in visited:
                visited.add((nx, ny))
                queue.append(((nx, ny), path + [(nx, ny)]))
    
    return None  # No path found



maze = [
  [1,1,1,1,1,0,1,1],
  [1,0,0,0,0,0,0,1],
  [1,0,1,1,1,1,0,1],
  [1,0,1,0,1,0,0,1],
  [1,0,1,0,1,1,0,1],
  [1,0,1,0,1,0,0,1],
  [1,0,0,0,0,0,0,1],
  [1,1,1,1,1,1,1,1]
]

start = (3,3)
goal = (0,5)

path = bfs_maze(maze, start, goal)
print("Shortest path:", path)
print("Steps:", len(path)-1)
