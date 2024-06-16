# @param {String[]} words
# @return {Integer}
def minimum_length_encoding(words)
  words = words.sort_by(&:size).reverse
  seen = Set.new
  ans = 0

  words.each do |word|
    next if seen.include?(word)
    ans += word.size + 1

    loop do
      break if word.empty?
      seen << word
      word = word[1..-1]
    end
  end

  ans
end
