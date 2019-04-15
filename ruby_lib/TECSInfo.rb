class TECSInfo

  def initialize( json_hash )
    @lines = []
    @insert_idx = 0
    @delete_idx = 0
    @target = json_hash
    @arg = @target["arg"]
  end

  def insert_info( file_name )
    search_idx( file_name )
    if @insert_idx + 1 == @delete_idx then
      add_text( "\tstrcpy( VAR_cell_path, \"#{@target["cell"]}\" );\n" )
      add_text( "\tstrcpy( VAR_entry_path_tmp, \"#{@target["entry"]}\" );\n" )
      add_text( "\tstrcpy( VAR_function_path_tmp, \"#{@target["function"]}\" );\n" )
    end
    insert_lines( file_name )
  end

  def insert_unit(file_name)
    search_idx( file_name )
    if @insert_idx + 1 == @delete_idx then
      p @insert_idx
      add_arg
      add_exp
    end
    insert_lines( file_name )
  end

  def search_idx( file_name )
    keyword = "json_insert"
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
  def add_exp
    if @target["exp_val"].kind_of?( String ) then
      add_text( "\tchar exp_val[] = \"#{@target["exp_val"]}\";\n" )
      add_text( "\tchar *ret_val;\n" )
    end
    if @target["exp_val"].kind_of?( Fixnum ) then
      add_text( "\tint exp_val = #{@target["exp_val"]};\n" )
      add_text( "\tint ret_val;\n" )
    end
    if @target["exp_val"].kind_of?( Float ) then
      add_text( "\tdouble exp_val = #{@target["exp_val"]};\n" )
      add_text( "\tdouble ret_val;\n" )
    end
  end

  def clean( file_name )
    keyword = "json_insert"
    search_idx( file_name )
    @lines.slice!( @insert_idx+1 .. @delete_idx-1 )
    insert_lines( file_name )
  end

end