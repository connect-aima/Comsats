
board = [
    ['M', 'S', 'E', 'F'],
    ['R', 'A', 'T', 'D'],
    ['L', 'O', 'N', 'E'],
    ['K', 'A', 'F', 'B']
]


dictionary = {"START", "NOTE", "SAND", "STONED"}


rows = len(board)
cols = len(board[0])


directions = [(-1, -1), (-1, 0), (-1, 1),
              (0, -1),          (0, 1),
              (1, -1),  (1, 0),  (1, 1)]


found_words = set()

def dfs(i, j, visited, current_word):
   
    current_word += board[i][j]
    visited.add((i, j))
    
  
    if current_word in dictionary:
        found_words.add(current_word)
    
    
    for dx, dy in directions:
        new_i, new_j = i + dx, j + dy
        if 0 <= new_i < rows and 0 <= new_j < cols and (new_i, new_j) not in visited:
            dfs(new_i, new_j, visited, current_word)
    
   
    visited.remove((i, j))


# calling function

for i in range(rows):
    for j in range(cols):
        dfs(i, j, set(), "")

print("Valid words found:", found_words)
