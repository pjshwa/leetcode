# @param {Integer[][]} mat
# @param {Integer} k
# @return {Integer[]}
def k_weakest_rows(mat, k)
  mat = mat.each_with_index.sort_by {|row, i| [row.count(1), i]}
  mat.map {|row, i| i}.take(k)
end
