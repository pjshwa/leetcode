def rob_util(pos, nums, cache)
  return cache[pos] if cache[pos]

  if nums.size == pos
    result = 0
  elsif nums.size == pos + 1
    result = nums.last
  elsif nums.size == pos + 2
    result = nums.last(2).max
  else
    result = [
      rob_util(pos + 1, nums, cache),
      nums[pos] + rob_util(pos + 2, nums, cache)
    ].max
  end

  cache[pos] = result
end

# @param {Integer[]} nums
# @return {Integer}
def rob(nums)
  rob_util(0, nums, {})
end
