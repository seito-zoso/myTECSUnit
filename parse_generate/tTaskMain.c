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
 * call port: cPutString signature: sPutString context:task optional:true
 *   bool_t     is_cPutString_joined()                     check if joined
 *   void           cPutString_putString( const char_t* string );
 *   [dynamic, optional]
 *      void           cPutString_set_descriptor( Descriptor( sPutString ) desc );
 *      void           cPutString_unjoin(  );
 * call port: cTaskBody signature: sTaskBody context:task optional:true
 *   bool_t     is_cTaskBody_joined()                     check if joined
 *   void           cTaskBody_main( );
 *   [dynamic, optional]
 *      void           cTaskBody_set_descriptor( Descriptor( sTaskBody ) desc );
 *      void           cTaskBody_unjoin(  );
 * call port: cREDInfo signature: nTECSInfo_sRawEntryDescriptorInfo context:task optional:true
 *   bool_t     is_cREDInfo_joined()                     check if joined
 *   uint16_t       cREDInfo_getNRawEntryDescriptorInfo( );
 *   ER             cREDInfo_getRawDescriptor( int_t ith, void** rawDesc );
 *   [dynamic, optional]
 *      void           cREDInfo_set_descriptor( Descriptor( nTECSInfo_sRawEntryDescriptorInfo ) desc );
 *      void           cREDInfo_unjoin(  );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tTaskMain_tecsgen.h"
#include <stdio.h>

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

static void
call_sTask( CELLCB *p_cellcb, char_t *entry_path );
static void
call_sPutString( CELLCB *p_cellcb, char_t *entry_path, char_t *message );
/* Prototype TECSUnit */
static void
call_sTest1( CELLCB *p_cellcb, char_t *entry_path, int arg);


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
    CELLCB	*p_cellcb;
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

    printf( "--- rawEntryDescriptor test ---\n" );
    call_sTask( p_cellcb, "HelloWorld.eMain" );
    call_sPutString( p_cellcb, "PutStringStdio.ePutString", "Hello World!\n" );
    /* Call TECSUnit */
	call_sTest1( p_cellcb, "UnitTest1.eUnitTest1", 5);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/

ER getRawEntryDescriptor( CELLCB *p_cellcb, char_t *entry_path, void **rawEntryDesc, char_t *expected_signature )
{
    Descriptor( nTECSInfo_sRawEntryDescriptorInfo ) rawEntryDescDesc;
    Descriptor( nTECSInfo_sEntryInfo )              entryDesc;
    ER     ercd;
    void   *rawDesc;

    ercd = cTECSInfo_findRawEntryDescriptor( entry_path, &rawEntryDescDesc, &entryDesc );
    if( ercd != E_OK ){
        printf( "call_sTask: error cTECSInfo_findRawEntryDescriptor( entry_path=%s ) = %d\n", entry_path, ercd );
    }
    else {
#define NAME_LEN  (256)
        Descriptor( nTECSInfo_sSignatureInfo )  signatureDesc;
        char_t  name[ NAME_LEN ];

        cREDInfo_set_descriptor( rawEntryDescDesc );
        cEntryInfo_set_descriptor( entryDesc );
        cEntryInfo_getSignatureInfo( &signatureDesc );
        cSignatureInfo_set_descriptor( signatureDesc );
        ercd = cSignatureInfo_getName( name, NAME_LEN );
        if( ercd != E_OK ){
            printf( "getRawEntryDescriptor: error cannot get signature name. expectd: '%s'\n", expected_signature );
        }
        if( strcmp( name, expected_signature ) != 0 ){
            printf( "getRawEntryDescriptor: error signature name '%s' mismatch expecting '%s'\n", name, expected_signature );
            ercd = E_NOEXS;
        }
        cREDInfo_getRawDescriptor( 0, rawEntryDesc );
    }
    return ercd;
}

static void
call_sTask( CELLCB *p_cellcb, char_t *entry_path )
{
    ER     ercd;
    void   *rawEntryDesc;
    Descriptor( sTaskBody )      taskBodyDesc;

    ercd = getRawEntryDescriptor( p_cellcb, entry_path, &rawEntryDesc, "sTaskBody" );
    if( ercd == E_OK ){
        setRawEntryDescriptor( taskBodyDesc, sTaskBody, rawEntryDesc );
        cTaskBody_set_descriptor( taskBodyDesc );
        cTaskBody_main();
    }
    else {
        printf( "call_sTask: errro: cTaskBody_main() not called\n" );
    }
}


static void
call_sPutString( CELLCB *p_cellcb, char_t *entry_path, char_t *message )
{
    ER     ercd;
    void   *rawEntryDesc;
    Descriptor( sPutString )      putStringDesc;

    ercd = getRawEntryDescriptor( p_cellcb, entry_path, &rawEntryDesc, "sPutString" );
    if( ercd == E_OK ){
        setRawEntryDescriptor( putStringDesc, sPutString, rawEntryDesc );
        cPutString_set_descriptor( putStringDesc );
        cPutString_putString( message );
    }
    else {
        printf( "call_sPutString: errro: cPutString_putString() not called\n" );
    }
}
/* Function TECSUnit */
static void
call_sTest1( CELLCB *p_cellcb, char_t *entry_path, int arg){
	ER     ercd;
	void   *rawEntryDesc;
	Descriptor( sTest1 )      func1Desc;
	ercd = getRawEntryDescriptor( p_cellcb, entry_path, &rawEntryDesc, "sTest1" );
	if( ercd == E_OK ){
		setRawEntryDescriptor( func1Desc, sTest1, rawEntryDesc );
		cUnitTest1_set_descriptor( sTest1Desc );
		cUnitTest1_func1( arg );
	}
	else {
		printf( "call_sTest1: errro: cUnitTest1_func1() not called" );
	}
}

