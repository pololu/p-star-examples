# Ruby script that helps us check that source files that should be the
# same are actually the same.

require 'pathname'
require 'digest'

SourceExtensions = %w{.c .h .asm}
ExcludedNames = %w{main.c}

def source_files(pathname)
  case
  when pathname.directory?
    pathname.children.flat_map { |c| source_files(c) }
  when pathname.file? \
    && SourceExtensions.include?(pathname.extname) \
    && !ExcludedNames.include?(pathname.basename.to_s)
    [pathname]
  else
    []
  end
end

top_level = Pathname(__FILE__).dirname

examples = top_level.children.select do |child|
  child.directory? && child.extname == '.X'
end

files = examples.flat_map { |example| source_files(example) }

groups = files.group_by { |f| f.basename.to_s }

groups.each do |name, files|
  next if files.size < 2

  hashes = files.collect do |file|
    Digest::SHA256::hexdigest(File.open(file, 'rb', &:read))
  end

  if hashes.uniq.size != 1
    files.zip(hashes) do |file, hash|
      puts "%-40s %7s" % [file, hash[0, 7]]
    end
  end
end
