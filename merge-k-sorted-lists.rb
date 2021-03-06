# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
# @param {ListNode[]} lists
# @return {ListNode}

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

  alias :<< :add

  def replace(element)
    @heap[0] = element
    rebalance_down(0)
  end

  def offer(element)
    if compare(peak, element)
      result = peak
      replace(element)
      result
    else
      element
    end
  end

  def clear
    @heap = []
    @size = 0
  end

  def to_a
    @heap.dup
  end

  private

  def initialize_compare(symbol, &fn)
    @compare = if block_given?
      fn
    elsif symbol == :< or symbol.nil?
      lambda{|a, b| a < b}
    elsif symbol == :>
      lambda{|a, b| a > b}
    else
      raise ArgumentError.new("The comparison symbol needs to be either :> or :<")
    end
  end

  def compare(a, b)
    @compare.call(a, b)
  end

  def rebalance_up(i)
    parent_i = parent(i)

    if has_parent(i) and compare(@heap[i], @heap[parent_i])
      @heap[i], @heap[parent_i] = @heap[parent_i], @heap[i]
      rebalance_up(parent_i)
    end
  end

  def rebalance_down(i)
    left_i = left(i)
    right_i = right(i)

    if has_left(i) and compare(@heap[left_i], @heap[i]) and (not has_right(i) or compare(@heap[left_i], @heap[right_i]))
      @heap[i], @heap[left_i] = @heap[left_i], @heap[i]
      rebalance_down(left_i)
    elsif has_right(i) and compare(@heap[right_i], @heap[i])
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

def merge_k_lists(lists)
  return if lists.empty? || lists.all? {|ln| ln.nil?}

  result = ListNode.new
  min_heap = Heap.new {|a, b| a[1] < b[1]}

  lists = lists.dup
  lists.each_with_index do |list_node, index|
    min_heap << [index, list_node.val] if list_node
  end

  next_node = result
  while true
    index, val = min_heap.pop
    next_node.val = val

    lists[index] = lists[index].next
    min_heap << [index, lists[index].val] if lists[index]

    if min_heap.peak
      next_node.next = ListNode.new
      next_node = next_node.next
    else
      break
    end
  end

  result
end
