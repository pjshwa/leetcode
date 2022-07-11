# @param {String} path
# @return {String}
def simplify_path(path)
  rel_path = []
  path.split('/').each do |dir|
    next if dir == '.' || dir.empty?
    if dir == '..'
      rel_path.pop
    else
      rel_path << dir
    end
  end

  '/' + rel_path.join('/')
end
