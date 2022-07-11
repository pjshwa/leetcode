# @param {String} s
# @return {Integer}

# https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
def length_of_longest_substring(s)
  occurred = Array.new(128, nil)
  max_substring_length = 0
  last_substring_start_index = 0

  s.chars.each_with_index do |char, idx|
    ord = char.ord
    if occurred[ord]
      max_substring_length = [max_substring_length, idx - last_substring_start_index].max
      last_substring_start_index = [last_substring_start_index, occurred[ord] + 1].max
    end

    occurred[ord] = idx
  end

  [s.size - last_substring_start_index, max_substring_length].max
end

# p length_of_longest_substring('bbbbb')
# p length_of_longest_substring('abcabcbb')
# p length_of_longest_substring('dbdf')
# p length_of_longest_substring('cdd')
# p length_of_longest_substring('cddc')
# p length_of_longest_substring('cdbdc')
