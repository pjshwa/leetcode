# @param {Integer[][]} intervals
# @return {Integer[][]}
def merge(intervals)
  starts = intervals.map(&:first)
  ends = intervals.map(&:last)

  stack_instructions = []

  starts.each do |start_point|
    stack_instructions.push([start_point, 'push'])
  end

  ends.each do |end_point|
    stack_instructions.push([end_point, 'pop'])
  end

  stack_instructions.sort_by!(&:first)

  stack = []
  result = []
  stack_instructions.each do |item, modifier|
    if modifier == 'push'
      result << item if stack.empty?
      stack << nil # just push anything.
    else
      stack.pop
      result << item if stack.empty?
    end
  end
  
  result.each_slice(2).to_a
end
