class TECSInfo

  def initialize( index, json_hash )
    @lines = []
    @code = "src/tTaskMain.c" # 必要に応じて書き換える
    @insert_idx = 0
    @delete_idx = 0
    @index = index
    @target = json_hash["target#{@index}"]
  end

  def insert
    search_idx( @code, "json_insert" )
    if @insert_idx + 1 == @delete_idx then
      add_text( "\t\tstrcpy( VAR_cell_name, \"#{@target["cell"]}\" );\n" )
      add_text( "\t\tstrcpy( VAR_entry_name_tmp, \"#{@target["entry"]}\" );\n" )
      add_text( "\t\tstrcpy( VAR_function_name_tmp, \"#{@target["function"]}\" );\n" )
    end
    insert_lines( @code )
  end

# 挿入したコードを削除
  def clean
    code_clean( @code ,"json_insert" )
  end

  def code_clean( file_name, keyword )
    search_idx( file_name, keyword )
    @lines.slice!( @insert_idx+1 .. @delete_idx-1 )
    insert_lines( file_name )
  end

# @linesにファイル内容、またキーワードの開始終了indexを得る
  def search_idx( file_name, keyword )
    flag = true
    File.open( file_name, "r" ) do |file|
      @lines = file.readlines
      @lines.each_with_index do |line, idx|
        if line.include?( keyword ) && flag
          @insert_idx = idx
          flag = false # もう来ない
        end
        if line.include?( "/#{keyword}" )
          @delete_idx = idx
        end
      end
    end
  end

  def insert_lines( file_name )
    File.open( file_name, "w" ) do |file|
      file.puts( @lines )
      @lines.clear
    end
  end

  def add_text( text )
    @lines.insert( @insert_idx += 1, text )
  end

end