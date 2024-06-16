# @param {Integer[]} nums
# @return {Integer[]}
def next_greater_elements(nums)
  n = nums.size
  stack = []
  result = Array.new(2 * n, -1)

  (2 * n - 1).downto(0) do |i|
    stack.pop while !stack.empty? && stack.last <= nums[i % n]
    result[i] = stack.last unless stack.empty?

    stack << nums[i % n]
  end

  result[0...n]
end

# next_greater_elements([1,2,3,4,1]) == [2, 3, 4, -1, 2]
# next_greater_elements([3, 1, 3, 1, 2, 3, 4, 2, 1]) == [4, 3, 4, 2, 3, 4, -1, 3, 3]
# next_greater_elements([1,2,1]) == [2, -1, 2]
