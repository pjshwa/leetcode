# @param {Integer[]} stones
# @return {Boolean}

require 'set'

def dfs(val, k, max, stones_set, visited)
  return false if k <= 0
  return false if visited.include?([val, k])
  return false unless stones_set.include?(val + k)
  return true if val + k == max

  visited << [val, k]
  (k - 1..k + 1).any? do |k_c|
    dfs(val + k, k_c, max, stones_set, visited)
  end
end

def can_cross(stones)
  n = stones.size
  stones_set = stones.to_set
  visited = Set.new

  dfs(stones.first, 1, stones.last, stones_set, visited)

  # init_el = [stones.first, 1]
  # queue = Queue.new
  # if stones_set.include?(stones.first + 1)
  #   queue << init_el
  #   visited << init_el
  # end

  # result = false
  # until queue.empty?
  #   val, k = queue.shift
  #   new_val = val + k
  #   if new_val == stones.last
  #     result = true
  #     break
  #   end

  #   (k - 1..k + 1).each do |k_c|
  #     if stones_set.include?(new_val + k_c) && !visited.include?([new_val, k_c])
  #       queue << [new_val, k_c]
  #       visited << [new_val, k_c]
  #     end
  #   end
  # end

  # result
end

# can_cross [0,1,3,4,5,7,9,10,12]
# can_cross [0,1,3,5,6,8,12,17]
# can_cross [0,1,2,3,4,8,9,11]
# can_cross (0..999).to_a
