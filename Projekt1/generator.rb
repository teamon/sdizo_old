#!/usr/bin/env ruby

if ARGV.size < 3
  puts "Usage: #{__FILE__} [matrix|list] N P"
  exit
end

N = ARGV[1].to_i
P = ARGV[2].to_i
W = 10

ar = N.times.map {|i| 
   N.times.map { 0 }
}

(N*P).times.each {
  x = rand(N)
  y = rand(N)
  
  next if x == y
  
  w = rand(W)+1
  ar[x][y] = ar[y][x] = w
}

case ARGV[0]
when "matrix"
  File.open("data/matrix_#{N}_#{P}.txt", "w") do |file|
    file.puts N

    N.times do |i|
      N.times do |j|
        file.write ar[i][j]
        file.write " "
      end
      file.puts
    end
  end

when "list"
  all = (0..N-1).to_a
  File.open("data/list_#{N}_#{P}.txt", "w") do |file|
    file.puts N
    
    N.times do |i|
      (i..N-1).each do |j|
        if ar[i][j] > 0
          file.puts "#{i} #{j} #{ar[i][j]}"
        end
      end
    end
  end
end
