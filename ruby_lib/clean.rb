require 'json'
require_relative 'TECSUnit.rb'

begin
  json_hash = Hash.new()
  unit1 = TECSUnit.new(1,json_hash)
  unit1.clean
rescue => ex
  print ex.message, "\n"
end
