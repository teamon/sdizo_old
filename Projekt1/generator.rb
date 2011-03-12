#!/usr/bin/env ruby

if ARGV.size < 3
  puts "Usage: #{__FILE__} [matrix|list] N P"
  exit
end

N = ARGV[1].to_i
P = ARGV[2].to_i
W = 10

case ARGV[0]
when "matrix"
  File.open("data/matrix_#{N}_#{P}.txt", "w") do |file|
    file.puts N

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
    

    N.times do |i|
      N.times do |j|
        print ar[i][j]
        print " "
      end
      puts
    end
  end

when "list"
  all = (0..N-1).to_a
  File.open("data/list_#{N}_#{P}.txt", "w") do |file|
    file.puts N
    N.times do |i|
      x = all.sample((rand(10) < P) ? (rand(N)+1) : 0).map {|e| [e, rand(W) + 1] }
      file.puts ([x.size] + x).flatten.join(" ")
    end
  end
end
