require 'json'
require_relative 'TECSInfo.rb'
require_relative 'TECSUnit.rb'

begin
  json_hash = Hash.new()
  File.open("target.json") do |file|
    json_hash = JSON.load(file)
  end
  info = TECSInfo.new( json_hash )
  unit = TECSUnit.new( json_hash )
  info.insert_info("src/tTaskMain.c")
  unit.insert_unit("src/tTECSUnit.c")
rescue => ex
  print ex.message, "\n"
end
