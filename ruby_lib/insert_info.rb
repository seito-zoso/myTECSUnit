require 'json'
require_relative 'TECSInfo.rb'

begin
  json_hash = Hash.new()
  File.open("target.json") do |file|
    json_hash = JSON.load(file)
  end
  info = TECSInfo.new( 1, json_hash)
  info.insert
rescue => ex
  print ex.message, "\n"
end
