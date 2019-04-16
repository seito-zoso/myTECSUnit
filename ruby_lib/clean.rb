require 'json'
require_relative 'TECSInfo.rb'
require_relative 'TECSUnit.rb'

begin
  json_hash = Hash.new()
  info = TECSInfo.new( json_hash )
  unit = TECSUnit.new( json_hash )
  info.clean( "src/tTaskMain.c", "json_insert" )
  unit.clean( "src/tTECSUnit.c", "json_insert" )
rescue => ex
  print ex.message, "\n"
end
