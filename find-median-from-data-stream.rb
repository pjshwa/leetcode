# https://github.com/florian/rb_heap/blob/master/lib/rb_heap/heap.rb
class Heap
  def initialize(compare_symbol = :<, storage = [], &compare_fn)
    @heap = storage
    @size = 0
    initialize_compare(compare_symbol, &compare_fn)
  end

  attr_reader :size

  def empty?
    size == 0
  end

  def peak
    @heap[0]
  end

  def pop
    result = peak

    if size > 1
      @size -= 1
      @heap[0] = @heap[@size]
      rebalance_down(0)
    else
      @size = 0
    end

    @heap[@size] = nil

    result
  end

  def add(element)
    @heap[@size] = element
    @size += 1
    rebalance_up(size - 1)
    self
  end

  alias << add

  private

  def initialize_compare(symbol, &fn)
    @compare = if block_given?
                 fn
               elsif (symbol == :<) || symbol.nil?
                 ->(a, b) { a < b }
               elsif symbol == :>
                 ->(a, b) { a > b }
               else
                 raise ArgumentError, 'The comparison symbol needs to be either :> or :<'
    end
  end

  def compare(a, b)
    @compare.call(a, b)
  end

  def rebalance_up(i)
    parent_i = parent(i)

    if has_parent(i) && compare(@heap[i], @heap[parent_i])
      @heap[i], @heap[parent_i] = @heap[parent_i], @heap[i]
      rebalance_up(parent_i)
    end
  end

  def rebalance_down(i)
    left_i = left(i)
    right_i = right(i)

    if has_left(i) && compare(@heap[left_i], @heap[i]) && (!has_right(i) || compare(@heap[left_i], @heap[right_i]))
      @heap[i], @heap[left_i] = @heap[left_i], @heap[i]
      rebalance_down(left_i)
    elsif has_right(i) && compare(@heap[right_i], @heap[i])
      @heap[i], @heap[right_i] = @heap[right_i], @heap[i]
      rebalance_down(right_i)
    end
  end

  def has_parent(i)
    i >= 1
  end

  def parent(i)
    ((i - 1) / 2).floor
  end

  def has_left(i)
    left(i) < size
  end

  def left(i)
    i * 2 + 1
  end

  def has_right(i)
    right(i) < size
  end

  def right(i)
    i * 2 + 2
  end
end

class MedianFinder
  def initialize
    @min_heap = Heap.new
    @max_heap = Heap.new(:>)
  end

  def add_num(num)
    if @min_heap.empty? || num < @min_heap.peak
      @min_heap << num
    else
      @max_heap << num
    end

    # Rebalance
    @max_heap << @min_heap.pop if @min_heap.size > @max_heap.size + 1
    @min_heap << @max_heap.pop if @max_heap.size > @min_heap.size + 1
  end

  def find_median
    if @min_heap.size == @max_heap.size
      (@min_heap.peak + @max_heap.peak) / 2.0
    else
      @min_heap.size > @max_heap.size ? @min_heap.peak : @max_heap.peak
    end
  end
end
