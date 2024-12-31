
puts `g++ es2.cpp -o es2`

Dir["inputs/**"].each do |input_path|
  puts `./es2 < #{input_path}`
end
