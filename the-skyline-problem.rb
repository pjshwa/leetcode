# @param {Integer[][]} buildings
# @return {Integer[][]}
Array.class_eval do
  def second
    self[1]
  end

  def third
    self[2]
  end
end

def get_skyline(buildings)
  building_pushes = buildings.map {|b| [b.first, b.third]} # Already sorted by first
  building_pops = buildings.map {|b| [b.second, b.third]}.sort_by(&:first)

  # heights get pushed or popped
  # max height should be calculated at each pushes or pops

  # This should always stay sorted
  building_heights = []
  stack_items = []

  building_pushes.each do |push_item, push_height|
    while !building_pops.first&.first || building_pops.first.first < push_item
      pop_item, pop_height = building_pops.shift
      stack_items.push([pop_item, pop_height, 'pop'])
    end

    stack_items.push([push_item, push_height, 'push'])
  end

  # Take care of remainders
  building_pops.each do |pop_item, pop_height|
    stack_items.push([pop_item, pop_height, 'pop'])
  end

  result = []
  stack_items.each do |x_coord, height, modifier|
    if modifier == 'push'
      insert_at = building_heights.bsearch_index {|h| h >= height}
      insert_at ? building_heights.insert(insert_at, height) : building_heights.push(height)
    else
      delete_at = building_heights.bsearch_index {|h| h >= height}
      building_heights.delete_at(delete_at)
    end

    cur_max_height = building_heights.last || 0
    result.push([x_coord, cur_max_height]) if result.last&.last != cur_max_height
  end

  # Find last height by x-coordinate
  result_hash = Hash.new
  result.each do |x_coord, height|
    result_hash[x_coord] = height
  end

  result_hash.keys.sort.map {|k| [k, result_hash[k]]}
end

# get_skyline([ [2, 9, 10],  [3, 7, 15],  [5, 12, 12],  [15, 20, 10],  [19, 24, 8], ])
# get_skyline([ [1,2,1],[1,2,2],[1,2,3]] )
# get_skyline([[2,4,7],[2,4,5],[2,4,6]])

