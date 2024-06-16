class Solution:
    def minimumMoves(self, grid: List[List[int]]) -> int:
        if not grid: return -1
        rows, cols = len(grid), len(grid[0])
        queue = deque()
        queue.append((0,0,'h',0))    
        visited = set()
        while queue:
            r, c, p, m = queue.popleft()
            if r == rows - 1 and c == cols - 2 and p == 'h': return m
            if (r,c,p) in visited: continue
            visited.add((r,c,p))
            if p == 'h':
                if c + 2 < cols and grid[r][c+2] == 0: # move one cell to right
                    queue.append((r,c+1,'h',m+1))
                if r + 1 < rows and grid[r+1][c] == 0 and grid[r+1][c+1] == 0: # move down
                    queue.append((r+1,c,'h',m+1))
                if r + 1 < rows and grid[r+1][c] == 0 and grid[r+1][c+1] == 0: # rotate clockwise
                    queue.append((r,c,'v',m+1))
            elif p == 'v':
                if c + 1 < cols and grid[r][c+1] == 0 and grid[r+1][c+1] == 0: # move one cell to right
                    queue.append((r,c+1,'v',m+1))
                if r + 2 < rows and grid[r+2][c] == 0: # move down
                    queue.append((r+1,c,'v',m+1))
                if c + 1 < cols and grid[r][c+1] == 0 and grid[r + 1][c+1] == 0: # rotate counterclockwise
                    queue.append((r,c,'h',m+1))
        return -1
