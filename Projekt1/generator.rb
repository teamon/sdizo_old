#!/usr/bin/env ruby

if ARGV.size < 3
  puts "Usage: #{__FILE__} [matrix|list] N P"
  exit
end

N = ARGV[1].to_i
P = ARGV[2].to_i

case ARGV[0]
when "matrix"
  File.open("data/matrix_#{N}_#{P}.txt", "w") do |file|
    file.puts N
    N.times do |i|
      N.times do |j|
        file.write (rand(10) < P) ? (rand(10)+1) : 0
        file.write " "
      end
      file.puts
    end
  end
when "list"
  all = (0..N-1).to_a
  File.open("data/list_#{N}_#{P}.txt", "w") do |file|
    puts N
    N.times do |i|
      x = all.sample((rand(10) < P) ? (rand(10)+1) : 0)
      file.puts ([x.size] + x).join(" ")
    end
  end
end
