from collections import deque

class Solution:
  def candyCrush(self, board: List[List[int]]) -> List[List[int]]:
    n, m = len(board), len(board[0])

    def crush_connected(board):
      marked = [[False for _ in range(m)] for _ in range(n)]

      # scan by row
      for i in range(n):
        streak = [1 for _ in range(m)]
        for j in range(1, m):
          if board[i][j] == board[i][j - 1] and board[i][j] != 0:
            streak[j] = streak[j - 1] + 1
        
        j = m - 1
        while j >= 0:
          str_num = streak[j]
          if str_num >= 3:
            for k in range(str_num): marked[i][j - k] = True
          j -= str_num
      
      # scan by column
      for j in range(m):
        streak = [1 for _ in range(n)]
        for i in range(1, n):
          if board[i][j] == board[i - 1][j] and board[i][j] != 0:
            streak[i] = streak[i - 1] + 1
        
        i = n - 1
        while i >= 0:
          str_num = streak[i]
          if str_num >= 3:
            for k in range(str_num): marked[i - k][j] = True
          i -= str_num

      action_done = False
      for i in range(n):
        for j in range(m):
          if marked[i][j]:
            action_done = True
            board[i][j] = 0

      return action_done

    def drop_remaining(board):
      for j in range(m):
        dq = deque()
        for i in range(n - 1, -1, -1):
          if not board[i][j] == 0: dq.append(board[i][j])
          board[i][j] = 0

        for i in range(n - 1, -1, -1):
          if len(dq) == 0: break
          board[i][j] = dq.popleft()
      
    while True:
      action_done = crush_connected(board)
      if not action_done: break
      drop_remaining(board)
    
    return board



      