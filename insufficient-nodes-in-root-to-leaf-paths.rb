# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val = 0, left = nil, right = nil)
#         @val = val
#         @left = left
#         @right = right
#     end
# end
# @param {TreeNode} root
# @param {Integer} limit
# @return {TreeNode}

class TreeNode
  attr_reader :remove

  def initialize(val = 0, left = nil, right = nil)
    @val = val
    @left = left
    @right = right
    @remove = false
  end

  def traverse_and_mark(limit)
    if left || right
      left.traverse_and_mark(limit - val) if left
      right.traverse_and_mark(limit - val) if right

      @remove = true if [(!@left || @left.remove), (!@right || @right.remove)].all?
    else
      @remove = true if val < limit
    end
  end

  def remove_marked
    if @left&.remove
      @left = nil
    else
      @left&.remove_marked
    end

    if @right&.remove
      @right = nil
    else
      @right&.remove_marked
    end
  end
end

def sufficient_subset(root, limit)
  root.traverse_and_mark(limit)
  root.remove_marked
  root.remove ? nil : root
end
