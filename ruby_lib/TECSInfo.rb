class TECSInfo

  def initialize( json_hash )
    @lines = []
    @code = "src/tTaskMain.c" # 必要に応じて書き換える
    @insert_idx = 0
    @delete_idx = 0
    @target = json_hash
    @arg = @target["arg"]
  end

  def add_arg
    n = @arg.count
    p n
    for i in 0..n-1
      if @arg[i].kind_of?( String ) then
        add_text( "\tchar arg#{i+1}[] = \"#{@arg[i]}\";\n" )
      end
      if @arg[i].kind_of?( Fixnum ) then
        add_text( "\tint arg#{i+1} = #{@arg[i]};\n" )
      end
      if @arg[i].kind_of?( Float ) then
        add_text( "\tdouble arg#{i+1} = #{@arg[i]};\n" )
      end
    end
  end

  def insert
    search_idx( @code, "json_insert" )
    if @insert_idx + 1 == @delete_idx then
      add_arg()
      add_text( "\tstrcpy( VAR_cell_path, \"#{@target["cell"]}\" );\n" )
      add_text( "\tstrcpy( VAR_entry_path_tmp, \"#{@target["entry"]}\" );\n" )
      add_text( "\tstrcpy( VAR_function_path_tmp, \"#{@target["function"]}\" );\n" )
    end
    insert_lines( @code )
  end

# 挿入したコードを削除
  def clean
    code_clean( @code , "json_insert" )
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