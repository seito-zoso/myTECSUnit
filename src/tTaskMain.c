/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * NAME_LEN         int16_t          ATTR_NAME_LEN
 * name             char_t*          VAR_name
 * name2            char_t*          VAR_name2
 *
 * 呼び口関数 #_TCPF_#
 * call port: cTECSInfo signature: nTECSInfo_sTECSInfo context:task
 *   ER             cTECSInfo_findNamespace( const char_t* namespace_path, Descriptor( nTECSInfo_sNamespaceInfo )* nsDesc );
 *   ER             cTECSInfo_findRegion( const char_t* namespace_path, Descriptor( nTECSInfo_sRegionInfo )* regionDesc );
 *   ER             cTECSInfo_findSignature( const char_t* namespace_path, Descriptor( nTECSInfo_sSignatureInfo )* signatureDesc );
 *   ER             cTECSInfo_findCelltype( const char_t* namespace_path, Descriptor( nTECSInfo_sCelltypeInfo )* celltypeDesc );
 *   ER             cTECSInfo_findCell( const char_t* namespace_path, Descriptor( nTECSInfo_sCellInfo )* cellDesc );
 *   ER             cTECSInfo_findRawEntryDescriptor( const char_t* namespace_path, Descriptor( nTECSInfo_sRawEntryDescriptorInfo )* rawEntryDescDesc, Descriptor( nTECSInfo_sEntryInfo )* entryDesc );
 *   ER             cTECSInfo_findRawEntryDescriptor_unsafe( const char_t* namespace_path, void** rawDesc );
 * call port: cNSInfo signature: nTECSInfo_sNamespaceInfo context:task optional:true
 *   bool_t     is_cNSInfo_joined()                     check if joined
 *   ER             cNSInfo_getName( char_t* name, int_t max_len );
 *   uint16_t       cNSInfo_getNameLength( );
 *   uint32_t       cNSInfo_getNNamespace( );
 *   ER             cNSInfo_getNamespaceInfo( uint32_t ith, Descriptor( nTECSInfo_sNamespaceInfo )* des );
 *   uint32_t       cNSInfo_getNSignature( );
 *   ER             cNSInfo_getSignatureInfo( uint32_t ith, Descriptor( nTECSInfo_sSignatureInfo )* des );
 *   uint32_t       cNSInfo_getNCelltype( );
 *   ER             cNSInfo_getCelltypeInfo( uint32_t ith, Descriptor( nTECSInfo_sCelltypeInfo )* des );
 *   [dynamic, optional]
 *      void           cNSInfo_set_descriptor( Descriptor( nTECSInfo_sNamespaceInfo ) desc );
 *      void           cNSInfo_unjoin(  );
 * call port: cRegionInfo signature: nTECSInfo_sRegionInfo context:task optional:true
 *   bool_t     is_cRegionInfo_joined()                     check if joined
 *   ER             cRegionInfo_getName( char_t* name, int_t max_len );
 *   uint16_t       cRegionInfo_getNameLength( );
 *   uint32_t       cRegionInfo_getNCell( );
 *   ER             cRegionInfo_getCellInfo( uint32_t ith, Descriptor( nTECSInfo_sCellInfo )* des );
 *   uint32_t       cRegionInfo_getNRegion( );
 *   ER             cRegionInfo_getRegionInfo( uint32_t ith, Descriptor( nTECSInfo_sRegionInfo )* des );
 *   [dynamic, optional]
 *      void           cRegionInfo_set_descriptor( Descriptor( nTECSInfo_sRegionInfo ) desc );
 *      void           cRegionInfo_unjoin(  );
 * call port: cCellInfo signature: nTECSInfo_sCellInfo context:task optional:true
 *   bool_t     is_cCellInfo_joined()                     check if joined
 *   ER             cCellInfo_getName( char_t* name, int_t max_len );
 *   uint16_t       cCellInfo_getNameLength( );
 *   uint32_t       cCellInfo_getNRawEntryDescriptorInfo( );
 *   ER             cCellInfo_getRawEntryDescriptorInfo( int_t index, Descriptor( nTECSInfo_sRawEntryDescriptorInfo )* desc );
 *   void           cCellInfo_getCelltypeInfo( Descriptor( nTECSInfo_sCelltypeInfo )* desc );
 *   void           cCellInfo_getCBP( void** cbp );
 *   void           cCellInfo_getINIBP( void** inibp );
 *   [dynamic, optional]
 *      void           cCellInfo_set_descriptor( Descriptor( nTECSInfo_sCellInfo ) desc );
 *      void           cCellInfo_unjoin(  );
 * call port: cSignatureInfo signature: nTECSInfo_sSignatureInfo context:task optional:true
 *   bool_t     is_cSignatureInfo_joined()                     check if joined
 *   ER             cSignatureInfo_getName( char_t* name, int_t max_len );
 *   uint16_t       cSignatureInfo_getNameLength( );
 *   uint32_t       cSignatureInfo_getNFunction( );
 *   ER             cSignatureInfo_getFunctionInfo( uint32_t ith, Descriptor( nTECSInfo_sFunctionInfo )* desc );
 *   [dynamic, optional]
 *      void           cSignatureInfo_set_descriptor( Descriptor( nTECSInfo_sSignatureInfo ) desc );
 *      void           cSignatureInfo_unjoin(  );
 * call port: cCelltypeInfo signature: nTECSInfo_sCelltypeInfo context:task optional:true
 *   bool_t     is_cCelltypeInfo_joined()                     check if joined
 *   ER             cCelltypeInfo_getName( char_t* name, int_t max_len );
 *   uint16_t       cCelltypeInfo_getNameLength( );
 *   uint32_t       cCelltypeInfo_getNAttr( );
 *   ER             cCelltypeInfo_getAttrInfo( uint32_t ith, Descriptor( nTECSInfo_sVarDeclInfo )* desc );
 *   uint32_t       cCelltypeInfo_getNVar( );
 *   ER             cCelltypeInfo_getVarInfo( uint32_t ith, Descriptor( nTECSInfo_sVarDeclInfo )* desc );
 *   uint32_t       cCelltypeInfo_getNCall( );
 *   ER             cCelltypeInfo_getCallInfo( uint32_t ith, Descriptor( nTECSInfo_sCallInfo )* desc );
 *   uint32_t       cCelltypeInfo_getNEntry( );
 *   ER             cCelltypeInfo_getEntryInfo( uint32_t ith, Descriptor( nTECSInfo_sEntryInfo )* desc );
 *   bool_t         cCelltypeInfo_isSingleton( );
 *   bool_t         cCelltypeInfo_isIDX_is_ID( );
 *   uint32_t       cCelltypeInfo_sizeOfCB( );
 *   uint32_t       cCelltypeInfo_sizeOfINIB( );
 *   [dynamic, optional]
 *      void           cCelltypeInfo_set_descriptor( Descriptor( nTECSInfo_sCelltypeInfo ) desc );
 *      void           cCelltypeInfo_unjoin(  );
 * call port: cVarDeclInfo signature: nTECSInfo_sVarDeclInfo context:task optional:true
 *   bool_t     is_cVarDeclInfo_joined()                     check if joined
 *   ER             cVarDeclInfo_getName( char_t* name, int_t max_len );
 *   uint16_t       cVarDeclInfo_getNameLength( );
 *   void           cVarDeclInfo_getLocationInfo( uint32_t* offset, int8_t* place );
 *   void           cVarDeclInfo_getTypeInfo( Descriptor( nTECSInfo_sTypeInfo )* desc );
 *   void           cVarDeclInfo_getSizeIsExpr( char_t* expr_str, int32_t max_len );
 *   ER             cVarDeclInfo_getSizeIs( uint32_t* size, const void* p_cb );
 *   [dynamic, optional]
 *      void           cVarDeclInfo_set_descriptor( Descriptor( nTECSInfo_sVarDeclInfo ) desc );
 *      void           cVarDeclInfo_unjoin(  );
 * call port: cTypeInfo signature: nTECSInfo_sTypeInfo context:task optional:true
 *   bool_t     is_cTypeInfo_joined()                     check if joined
 *   ER             cTypeInfo_getName( char_t* name, int_t max_len );
 *   uint16_t       cTypeInfo_getNameLength( );
 *   uint32_t       cTypeInfo_getSize( );
 *   int8_t         cTypeInfo_getKind( );
 *   uint32_t       cTypeInfo_getNType( );
 *   ER             cTypeInfo_getTypeInfo( Descriptor( nTECSInfo_sTypeInfo )* desc );
 *   uint32_t       cTypeInfo_getNMember( );
 *   ER             cTypeInfo_getMemberInfo( uint32_t ith, Descriptor( nTECSInfo_sVarDeclInfo )* desc );
 *   [dynamic, optional]
 *      void           cTypeInfo_set_descriptor( Descriptor( nTECSInfo_sTypeInfo ) desc );
 *      void           cTypeInfo_unjoin(  );
 * call port: cFunctionInfo signature: nTECSInfo_sFunctionInfo context:task optional:true
 *   bool_t     is_cFunctionInfo_joined()                     check if joined
 *   ER             cFunctionInfo_getName( char_t* name, int_t max_len );
 *   uint16_t       cFunctionInfo_getNameLength( );
 *   void           cFunctionInfo_getReturnTypeInfo( Descriptor( nTECSInfo_sTypeInfo )* desc );
 *   uint32_t       cFunctionInfo_getNParam( );
 *   ER             cFunctionInfo_getParamInfo( uint32_t ith, Descriptor( nTECSInfo_sParamInfo )* param );
 *   [dynamic, optional]
 *      void           cFunctionInfo_set_descriptor( Descriptor( nTECSInfo_sFunctionInfo ) desc );
 *      void           cFunctionInfo_unjoin(  );
 * call port: cParamInfo signature: nTECSInfo_sParamInfo context:task optional:true
 *   bool_t     is_cParamInfo_joined()                     check if joined
 *   ER             cParamInfo_getName( char_t* name, int_t max_len );
 *   uint16_t       cParamInfo_getNameLength( );
 *   ER             cParamInfo_getTypeInfo( Descriptor( nTECSInfo_sTypeInfo )* desc );
 *   ER             cParamInfo_getDir( int8_t* dir );
 *   [dynamic, optional]
 *      void           cParamInfo_set_descriptor( Descriptor( nTECSInfo_sParamInfo ) desc );
 *      void           cParamInfo_unjoin(  );
 * call port: cREDInfo signature: nTECSInfo_sRawEntryDescriptorInfo context:task optional:true
 *   bool_t     is_cREDInfo_joined()                     check if joined
 *   uint16_t       cREDInfo_getNRawEntryDescriptorInfo( );
 *   ER             cREDInfo_getRawDescriptor( int_t ith, void** rawDesc );
 *   [dynamic, optional]
 *      void           cREDInfo_set_descriptor( Descriptor( nTECSInfo_sRawEntryDescriptorInfo ) desc );
 *      void           cREDInfo_unjoin(  );
 * call port: cEntryInfo signature: nTECSInfo_sEntryInfo context:task optional:true
 *   bool_t     is_cEntryInfo_joined()                     check if joined
 *   ER             cEntryInfo_getName( char_t* name, int_t max_len );
 *   uint16_t       cEntryInfo_getNameLength( );
 *   void           cEntryInfo_getSignatureInfo( Descriptor( nTECSInfo_sSignatureInfo )* desc );
 *   uint32_t       cEntryInfo_getArraySize( );
 *   bool_t         cEntryInfo_isInline( );
 *   [dynamic, optional]
 *      void           cEntryInfo_set_descriptor( Descriptor( nTECSInfo_sEntryInfo ) desc );
 *      void           cEntryInfo_unjoin(  );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tTaskMain_tecsgen.h"
#include <stdio.h>

#ifndef E_OK
#define E_OK    0       /* success */
#define E_ID    (-18)   /* illegal ID */
#endif

static void
print_indent( int level );
static void
print_cell_by_path( CELLCB *p_cellcb, char_t *path );
static void
print_cell( CELLCB *p_cellcb, Descriptor( nTECSInfo_sCellInfo )  CELLdesc, int level );
static void
print_signature( CELLCB *p_cellcb, Descriptor( nTECSInfo_sSignatureInfo )  signatureDesc, int level );
static void
print_function( CELLCB *p_cellcb, Descriptor( nTECSInfo_sFunctionInfo ) functionDesc, int level);
static void
print_param( CELLCB *p_cellcb, Descriptor( nTECSInfo_sParamInfo ) paramDesc, int level);
static void
print_celltype( CELLCB   *p_cellcb, Descriptor( nTECSInfo_sCelltypeInfo )  CTdesc, int level );
static void
print_entry(CELLCB  *p_cellcb, Descriptor( nTECSInfo_sEntryInfo )  Edesc, int level );

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eBody
 * entry port: eBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eBody_main
 * name:         eBody_main
 * global_name:  tTaskMain_eBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eBody_main(CELLIDX idx)
{
    CELLCB  *p_cellcb;
    ER      ercd;
    uint32_t  n;
    Descriptor( nTECSInfo_sNamespaceInfo ) NSdesc;
    Descriptor( nTECSInfo_sRegionInfo )    RGNdesc;

    if (VALID_IDX(idx)) {
        p_cellcb = GET_CELLCB(idx);
    }
    else {
        /* エラー処理コードをここに記述します */
    } /* end if VALID_IDX(idx) */

    /* ここに処理本体を記述します #_TEFB_# */
    printf( "started\n" );

    print_cell_by_path( p_cellcb, "Target1" /* ユーザ入力 */);

}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
static void
print_cell_by_path( CELLCB *p_cellcb, char_t *path )
{
    Descriptor( nTECSInfo_sCellInfo )  desc;
    ER    ercd;

    printf( "print_cell_by_path( path=\"%s\" )\n", path );
    ercd = cTECSInfo_findCell( path, &desc );
    if( ercd == E_OK ){
        print_cell( p_cellcb, desc, 1 );
    }
    else{
        printf( "cell %s not found\n", path );
    }
}

static void
print_cell( CELLCB  *p_cellcb, Descriptor( nTECSInfo_sCellInfo )  CELLdesc, int level )
{
    Descriptor( nTECSInfo_sCelltypeInfo ) CTdesc;
    void  *cbp, *inibp;

    cCellInfo_set_descriptor( CELLdesc );
    cCellInfo_getName( VAR_name, ATTR_NAME_LEN );

    cCellInfo_getCelltypeInfo( &CTdesc );
    print_indent( level );
    printf( "cell = %s\n", VAR_name);

    /* celltype info */
    print_celltype( p_cellcb, CTdesc, level + 1 );
}

static void
print_celltype( CELLCB  *p_cellcb, Descriptor( nTECSInfo_sCelltypeInfo )  CTdesc, int level )
{

    Descriptor( nTECSInfo_sEntryInfo ) entryDesc;
    int i, n;
    cCelltypeInfo_set_descriptor( CTdesc );
    cCelltypeInfo_getName( VAR_name, ATTR_NAME_LEN );
    print_indent( level );
    printf( "celltype name = %s\n", VAR_name );
    n = cCelltypeInfo_getNEntry();

    for( i = 0; i < n; i++ ){
      cCelltypeInfo_getEntryInfo(i, &entryDesc);
      print_entry(p_cellcb, entryDesc, level );
    }
}

static void
print_entry(CELLCB  *p_cellcb, Descriptor( nTECSInfo_sEntryInfo )  Edesc, int level )
{
    Descriptor( nTECSInfo_sSignatureInfo ) sigDesc;
    cEntryInfo_set_descriptor( Edesc );
    cEntryInfo_getName(VAR_name, ATTR_NAME_LEN);
    if(!strcmp(VAR_name, "eTarget1" /* ユーザ入力 */)){
      print_indent( level );
      printf( "entry name = %s\n", VAR_name );
      cEntryInfo_getSignatureInfo( &sigDesc );
      print_signature(p_cellcb, sigDesc, level );
    }
}

static void
print_signature( CELLCB *p_cellcb, Descriptor( nTECSInfo_sSignatureInfo )  signatureDesc, int level )
{
    int n, i;
    Descriptor( nTECSInfo_sFunctionInfo )  functionDesc;
    /* signatureInfoセルに動的結合 */
    cSignatureInfo_set_descriptor( signatureDesc );
    cSignatureInfo_getName( VAR_name, ATTR_NAME_LEN );
    n = cSignatureInfo_getNFunction();
    print_indent( level );
    printf( "signature name = %s\n", VAR_name );
    print_indent( level );
    printf( "# of function = %d\n", n );
    for(i = 0; i < n; i++){
        cSignatureInfo_getFunctionInfo(i, &functionDesc);
        print_function( p_cellcb, functionDesc, level + 1);
    }
}

static void
print_function( CELLCB *p_cellcb, Descriptor( nTECSInfo_sFunctionInfo ) functionDesc, int level)
{
    int n, i;
    Descriptor( nTECSInfo_sParamInfo ) paramInfo;
    cFunctionInfo_set_descriptor( functionDesc );
    cFunctionInfo_getName( VAR_name, ATTR_NAME_LEN );
    if(!strcmp(VAR_name, "double" /* ユーザ入力 */)){
      n = cFunctionInfo_getNParam();
      print_indent( level );
      printf( "function name = %s\n", VAR_name );
      print_indent( level );
      printf( "# of param = %d\n", n );
      for(i = 0; i < n; i++){
          cFunctionInfo_getParamInfo(i, &paramInfo);
          print_param( p_cellcb, paramInfo, level + 1);
      }
    }
}

static void
print_param( CELLCB *p_cellcb, Descriptor( nTECSInfo_sParamInfo ) paramDesc, int level)
{
    Descriptor( nTECSInfo_sTypeInfo ) typeInfo;
    cParamInfo_set_descriptor( paramDesc );
    cParamInfo_getName( VAR_name, ATTR_NAME_LEN );
    cParamInfo_getTypeInfo( &typeInfo );
    cTypeInfo_set_descriptor( typeInfo );
    cTypeInfo_getName( VAR_name2, ATTR_NAME_LEN);
    print_indent( level );
    printf( "%s %s\n", VAR_name2, VAR_name );
}

void
print_indent( int level )
{
    int i;
    for( i = 0; i < level; i++ ){
        fputs( "  ", stdout );
    }
}
