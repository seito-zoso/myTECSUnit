class TECSUnit

  def initialize(index,json_hash)
    @lines = []
    @cdl = "../TECSUnit.cdl" # 必要に応じて書き換える
    @celltype_code = "../src/tTECSUnit.c" # 必要に応じて書き換える
    @insert_idx = 0
    @delete_idx = 0
    @index = index
    @target = json_hash["target#{@index}"]
  end

# cdlとcelltype_codeに挿入
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

# celltypeコードの三ヵ所にコードを挿入
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

# 挿入したコードを削除
  def clean
    code_clean(@cdl,"TECSUnit test")
    code_clean(@celltype_code,"Prototype TECSUnit")
    code_clean(@celltype_code,"Call TECSUnit")
    code_clean(@celltype_code,"Function TECSUnit")
  end

  def code_clean(file_name,keyword)
    search_idx(file_name, keyword)
    @lines.slice!(@insert_idx+1..@clean_idx-1)
    insert_lines(file_name)
  end

# @linesにファイル内容、またキーワードの開始終了indexを得る
  def search_idx(file_name,keyword)
    flag = true
    File.open(file_name,"r") do |file|
      @lines = file.readlines
      @lines.each_with_index do |line,idx|
        if line.include?(keyword) && flag
          @insert_idx = idx
          flag = false # もう来ない
        end
        if line.include?("/#{keyword}")
          @clean_idx = idx
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