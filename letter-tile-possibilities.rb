Array.class_eval do
  def tally
    result = Hash.new(0)
    each do |item|
      result[item] += 1
    end

    result
  end
end

# (a + b + c)! / a! * b! * c!
def count_with_duplicates(counts)
  total_count = 1
  n = counts.sum
  counts.each do |count|
    count.times do |i|
      total_count *= n
      n -= 1
      total_count /= (i + 1)
    end
  end

  total_count
end

def gather_distinct_combinations(tile_counts, tile_combination_set)
  tile_combination_set << tile_counts
  return 0 if tile_counts.all?(&:zero?)

  tile_counts.size.times.sum do |idx|
    next 0 if tile_counts[idx].zero?

    new_tile_counts = tile_counts[0...idx]
    new_tile_counts += [tile_counts[idx] - 1]
    new_tile_counts += tile_counts[idx + 1..-1]
    gather_distinct_combinations(new_tile_counts, tile_combination_set)
  end
end

# @param {String} tiles
# @return {Integer}
def num_tile_possibilities(tiles)
  tile_combination_set = Set.new
  gather_distinct_combinations(tiles.chars.tally.values, tile_combination_set)

  tile_combination_set.sum do |tile_combination|
    count_with_duplicates(tile_combination)
  end - 1
end
