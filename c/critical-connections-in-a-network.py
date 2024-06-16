from collections import defaultdict

class Solution:
  def __init__(self):
    self.graph = defaultdict(list) # default dictionary to store graph 
    self.Time = 0
    self.bridges = []
   
  '''A recursive function that finds and prints bridges 
  using DFS traversal 
  u --> The vertex to be visited next 
  visited[] --> keeps tract of visited vertices 
  disc[] --> Stores discovery times of visited vertices 
  parent[] --> Stores parent vertices in DFS tree'''
  def bridgeUtil(self, u, visited, parent, low, disc): 
    # Mark the current node as visited and print it 
    visited[u] = True

    # Initialize discovery time and low value 
    disc[u] = self.Time 
    low[u] = self.Time 
    self.Time += 1

    # Recur for all the vertices adjacent to this vertex 
    for v in self.graph[u]:
      # If v is not visited yet, then make it a child of u 
      # in DFS tree and recur for it 
      if visited[v] == False : 
        parent[v] = u 
        self.bridgeUtil(v, visited, parent, low, disc) 

        # Check if the subtree rooted with v has a connection to 
        # one of the ancestors of u 
        low[u] = min(low[u], low[v]) 

        ''' If the lowest vertex reachable from subtree 
        under v is below u in DFS tree, then u-v is 
        a bridge'''
        if low[v] > disc[u]: 
          self.bridges.append([u, v])
                
      elif v != parent[u]: # Update low value of u for parent function calls. 
          low[u] = min(low[u], disc[v]) 

  # DFS based function to find all bridges. It uses recursive 
  # function bridgeUtil() 
  def find_bridges(self): 
    # Mark all the vertices as not visited and Initialize parent and visited,  
    # and ap(articulation point) arrays 
    visited = [False] * (self.V) 
    disc = [float("Inf")] * (self.V) 
    low = [float("Inf")] * (self.V) 
    parent = [-1] * (self.V) 

    # Call the recursive helper function to find bridges 
    # in DFS tree rooted with vertex 'i' 
    for i in range(self.V): 
      if visited[i] == False: 
        self.bridgeUtil(i, visited, parent, low, disc) 

  def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
    self.V = n
    for x, y in connections:
      self.graph[x].append(y)
      self.graph[y].append(x)

    self.find_bridges()
    return self.bridges
