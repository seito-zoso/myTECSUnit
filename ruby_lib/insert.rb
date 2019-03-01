require 'json'
require_relative 'TECSUnit.rb'

begin
  json_hash = Hash.new()
  File.open("target.json") do |file|
    json_hash = JSON.load(file)
  end
  unit1 = TECSUnit.new(1,json_hash)
  unit1.cdl_insert
  unit1.celltype_code_insert
rescue => ex
  print ex.message, "\n"
end
