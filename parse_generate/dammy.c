static void
call_#{@target["signature"]}( CELLCB *p_cellcb, char_t *entry_path, int arg){
    ER     ercd;
    void   *rawEntryDesc;
    Descriptor( #{@target["signature"]} )      #{@target["function"]}Desc;

    ercd = getRawEntryDescriptor( p_cellcb, entry_path, &rawEntryDesc, \"#{@target["signature"]}\" );
    if( ercd == E_OK ){
        setRawEntryDescriptor( #{@target["function"]}Desc, #{@target["signature"]}, rawEntryDesc );
        cUnitTest#{@index}_set_descriptor( #{@target["signature"]}Desc );
        cUnitTest#{@index}_#{@target["function"]}( arg );
    }
    else {
        printf( "call_#{@target["signature"]}: errro: cUnitTest#{@index}_#{@target["function"]}() not called\n" );
    }
}