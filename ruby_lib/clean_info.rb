require 'json'
require_relative 'TECSInfo.rb'

begin
  json_hash = Hash.new()
  info = TECSInfo.new( json_hash )
  info.clean
rescue => ex
  print ex.message, "\n"
end
