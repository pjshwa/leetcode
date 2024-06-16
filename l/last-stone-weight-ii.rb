def max_values_knapsack(n, limit, weights, values)
  dp_board = (n + 1).times.map {(limit + 1).times.map {0}}
  (n + 1).times do |i|
    (limit + 1).times do |j|
      next if i == 0 || j == 0

      if weights[i - 1] <= j
        dp_board[i][j] = [values[i - 1] + dp_board[i - 1][j - weights[i - 1]], dp_board[i - 1][j]].max
      else
        dp_board[i][j] = dp_board[i - 1][j]
      end
    end
  end
  
  dp_board[n][limit]
end

# @param {Integer[]} stones
# @return {Integer}
def last_stone_weight_ii(stones)
  filled = max_values_knapsack(stones.count, stones.sum / 2, stones, stones)
  (stones.sum - 2 * filled).abs
end
