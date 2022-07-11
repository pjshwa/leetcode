class FreqStack
  def initialize()
    @counts = Hash.new(0)
    @count_stack = Hash.new {|h, k| h[k] = []}
    @max_count = 0
  end


=begin
  :type x: Integer
  :rtype: Void
=end
  def push(x)
    @counts[x] += 1
    @max_count = [@max_count, @counts[x]].max
    @count_stack[@counts[x]] << x
  end


=begin
  :rtype: Integer
=end
  def pop()
    result = @count_stack[@max_count].pop
    @counts[result] -= 1
    @max_count -= 1 if @count_stack[@max_count].empty?

    result
  end
end

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack.new()
# obj.push(x)
# param_2 = obj.pop()
