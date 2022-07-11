# require 'set'

def dfs(src, graph, parent, visited, reported_cycles)
  visited[src] = true
  reported_cycle_dst = nil

  graph[src].each do |dst|
    next if dst == parent

    if visited[dst]
      reported_cycles << [src, dst].sort
      reported_cycle_dst = dst
    else
      reported_cycle_dst_prev = dfs(dst, graph, src, visited, reported_cycles)
      if reported_cycle_dst_prev
        reported_cycles << [src, dst].sort
        reported_cycle_dst = reported_cycle_dst_prev unless reported_cycle_dst_prev == src
      end
    end
  end
    
  reported_cycle_dst
end

# @param {Integer} n
# @param {Integer[][]} connections
# @return {Integer[][]}
def critical_connections(n, connections)
  graph = Hash.new {|h, k| h[k] = []}
  connections.each do |n1, n2|
    graph[n1] << n2
    graph[n2] << n1
  end

  reported_cycles = []
  visited = Array.new(n, false)
  dfs(0, graph, nil, visited, reported_cycles)
    
  connections.map(&:sort) - reported_cycles
end
