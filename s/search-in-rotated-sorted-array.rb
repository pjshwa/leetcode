# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}
def search(nums, target)
  left = 0
  right = nums.size - 1
  mid = (left + right) / 2

  found = false
  while left < right
    # Found the index
    if nums[mid + 1] < nums[mid]
      found = true
      break
    end

    if nums[left] < nums[mid]
      left = mid + 1
    else
      right = mid
    end

    mid = (left + right) / 2
  end

  if found
    if target <= nums[-1]
      idx = nums[mid + 1..-1].bsearch_index {|el| el >= target} + mid + 1
    else
      idx = nums[0..mid].bsearch_index {|el| el >= target} || mid
    end
      
    nums[idx] == target ? idx : -1
  else
    # Array is already sorted
    idx = nums.bsearch_index {|el| el >= target} || nums.size
    nums[idx] == target ? idx : -1
  end
end
