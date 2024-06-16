def coin_change_util(coins, amount, cache)
  return 0 if amount == 0
  return cache[amount] if cache[amount]

  candidates = coins.map do |coin_value|
    coin_change_util(coins, amount - coin_value, cache) if amount >= coin_value
  end.compact

  return Float::INFINITY if candidates.empty?

  cache[amount] = candidates.min + 1
end

# @param {Integer[]} coins
# @param {Integer} amount
# @return {Integer}
def coin_change(coins, amount)
  result = coin_change_util(coins, amount, {})
  result == Float::INFINITY ? -1 : result
end
