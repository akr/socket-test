def read_errno_list
  list = []
  File.foreach("errno.txt") {|line|
    line.sub!(/#.*/, '')
    line.strip!
    next if line.empty?
    list << line
  }
  list.uniq!
  list
end

