# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.

def move_zeroes(nums)
  length = nums.length
  length.times do |i|
    (length - i - 1).times do |j|
      if nums[j].zero?
        x, y = nums[j], nums[j + 1]
        nums[j], nums[j + 1] = y, x
      end
    end
  end
end


def move_zeroes(nums)
  zeroes_count = nums.count(&:zero?)
  nums.select!(&:nonzero?)
  zeroes_count.times {nums.push(0)}
end



def move_zeroes(nums)
  next_append_index = 0
  nums.each do |num|
    if num.nonzero?
      nums[next_append_index] = num
      next_append_index += 1
    end
  end

  while nums[next_append_index]
    nums[next_append_index] = 0
    next_append_index += 1
  end
end
