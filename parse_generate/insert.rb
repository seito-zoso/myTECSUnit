require 'json'
class TECSUnit

  def initialize(index,json_hash)
    @lines = []
    @cdl = "unit.cdl"
    @celltype_code = "tTaskMain.c"
    @insert_idx = 0
    @index = index
    @target = json_hash["target#{@index}"]
  end

  def cdl_insert
    search_idx(@cdl,"TECSUnit test")
    add_text("\t[dynamic, optional]\n")
    add_text("\t\tcall #{@target["signature"]} cUnitTest#{@index};\n")
    insert_lines(@cdl)
  end

  def celltype_code_insert
    self.prototype_insert
    self.call_insert
    self.function_insert
  end

  def prototype_insert
    search_idx(@celltype_code,"Prototype TECSUnit")
    add_text("static void\n")
    add_text("call_#{@target["signature"]}( CELLCB *p_cellcb, char_t *entry_path, int arg);\n")
    insert_lines(@celltype_code)
  end

  def call_insert
    search_idx(@celltype_code,"Call TECSUnit")
    add_text("\tcall_#{@target["signature"]}( p_cellcb, \"#{@target["cell"]}.#{@target["entry"]}\", #{@target["arguments"][0]});\n")
    insert_lines(@celltype_code)
  end

  def function_insert
    search_idx(@celltype_code,"Function TECSUnit")
    add_text("static void\n")
    add_text("call_#{@target["signature"]}( CELLCB *p_cellcb, char_t *entry_path, int arg){\n")
    add_text("\tER     ercd;\n")
    add_text("\tvoid   *rawEntryDesc;\n")
    add_text("\tDescriptor( #{@target["signature"]} )      #{@target["function"]}Desc;\n")
    add_text("\tercd = getRawEntryDescriptor( p_cellcb, entry_path, &rawEntryDesc, \"#{@target["signature"]}\" );\n")
    add_text("\tif( ercd == E_OK ){\n")
    add_text("\t\tsetRawEntryDescriptor( #{@target["function"]}Desc, #{@target["signature"]}, rawEntryDesc );\n")
    add_text("\t\tcUnitTest#{@index}_set_descriptor( #{@target["signature"]}Desc );\n")
    add_text("\t\tcUnitTest#{@index}_#{@target["function"]}( arg );\n")
    add_text("\t}\n")
    add_text("\telse {\n")
    add_text("\t\tprintf( \"call_#{@target["signature"]}: errro: cUnitTest#{@index}_#{@target["function"]}() not called\" );\n")
    add_text("\t}\n")
    add_text("}\n")
    insert_lines(@celltype_code)
  end

  def search_idx(file_name,keyword) # keywordと一致する場所を返す
    File.open(file_name,"r") do |file|
      @lines = file.readlines
      @lines.each_with_index do |line,idx|
        if line.include?(keyword)
          @insert_idx = idx
          break
        end
      end
    end
  end

  def insert_lines(file_name)
    File.open(file_name,"w") do |file|
      file.puts(@lines)
      @lines.clear
    end
  end

  def add_text(text)
    @lines.insert(@insert_idx += 1,text)
  end

end



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
