def read_errno_list
  list = []
  File.foreach("errno.txt") {|line|
    line.sub!(/#.*/, '')
    line.strip!
    next if line.empty?
    list << line
  }
  list.sort!
  list.uniq!
  list
end

