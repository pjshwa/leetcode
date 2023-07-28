# @param {String[]} words
# @return {String}

def palindrome?(string)
  string == string.reverse
end

def first_palindrome(words)
  words.each do |word|
    return word if palindrome?(word)
  end
  return ''
end
