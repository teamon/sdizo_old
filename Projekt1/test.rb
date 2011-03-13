#!/usr/bin/env ruby

n = 1000
p = 100

10.times do |i|
  puts "Test ##{i+1}"
  
  puts "+ Generate #{n} #{p}"
  system("./generator.rb both #{n} #{p}")
  
  ans = []
  
  puts "+ Prim / matrix"
  ans << `time ./main pmatrix data/matrix_#{n}_#{p}.txt`

  puts "+ Prim / list"
  ans << `time ./main plist data/list_#{n}_#{p}.txt`
  
  puts "+ Kruskal / matrix"
  ans << `time ./main kmatrix data/matrix_#{n}_#{p}.txt`

  puts "+ Kruskal / list"
  ans << `time ./main klist data/list_#{n}_#{p}.txt`

  f = ans.first
  

  if ans.all?{|e| e == f}
    puts "  Correct :D"
  else
    puts "  Error :("
    puts
    
    puts "- Prim / matrix"
    puts ans[0]

    puts "- Prim / list"
    puts ans[1]

    puts "- Kruskal / matrix"
    puts ans[2]

    puts "- Kruskal / list"
    puts ans[3]
    
    exit
  end
  
  puts
end
