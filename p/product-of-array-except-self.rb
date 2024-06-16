# @param {Integer[]} nums
# @return {Integer[]}
def product_except_self(nums)
  size = nums.size

  products = [1]
  (size - 1).times do |i|
    products << products.last * nums[size - 1 - i]
  end
  products.reverse!

  left_num = 1
  size.times do |i|
    products[i] *= left_num
    left_num *= nums[i]
  end

  products
end
