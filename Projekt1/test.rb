#!/usr/bin/env ruby

n = 100
p = 100

1000.times do |i|
  puts "Test ##{i+1}"
  
  puts "+ Generate #{n} #{p}"
  system("./generator.rb both #{n} #{p}")
  
  puts "+ Prim / matrix"
  pm = `./main matrix data/matrix_#{n}_#{p}.txt`

  puts "+ Prim / list"
  pl = `./main list data/list_#{n}_#{p}.txt`

  if pl == pm
    puts "  Correct :D"
  else
    puts "  Error :("
    puts
    
    puts "matrix:"
    puts "=" * 20
    puts pm
    puts
    puts "list:"
    puts "=" * 20
    puts pl
    
    exit
  end
  
  puts
end
