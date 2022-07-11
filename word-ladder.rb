# @param {String} begin_word
# @param {String} end_word
# @param {String[]} word_list
# @return {Integer}
def ladder_length(begin_word, end_word, word_list)
  word_length = begin_word.size
  graph = Hash.new {|h, k| h[k] = []}
  
  (word_list + [begin_word]).each do |word|
    candidate_words = word_length.times.map do |i|
      word[0...i] + '*' + word[i + 1..-1]
    end
    candidate_words.each {|cw| graph[cw] << word}
  end
  visited = (word_list + [begin_word]).map {|w| [w, false]}.to_h

  result = 0
  queue = []
  queue << [begin_word, 1]
  visited[begin_word] = true
  until queue.empty?
    item, idx = queue.shift
    if item == end_word
      result = idx
      break
    end

    visited[item] = true
    word_length.times do |i|
      candidate_word = item[0...i] + '*' + item[i + 1..-1]
      graph[candidate_word].each {|dst| queue << [dst, idx + 1] unless visited[dst]}
    end
  end

  result
end
