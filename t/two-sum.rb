# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
  len = nums.size
  front = 0
  back = len - 1

  nums_sorted = nums.sort
  while true
    sum = nums_sorted[front] + nums_sorted[back]
    if sum == target
      a, b = nums_sorted[front], nums_sorted[back]
      a_index = nums.each_with_index.find {|n, i| n == a}.last
      b_index = len - nums.reverse_each.with_index.find {|n, i| n == b}.last - 1
      return [a_index, b_index]
    elsif sum > target
      back -= 1
    elsif sum < target
      front += 1
    end
  end
end
