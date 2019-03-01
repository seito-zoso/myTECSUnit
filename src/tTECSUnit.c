/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tTECSUnit_templ.c => src/tTECSUnit.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cUnitTest1 signature: sTarget1 context:task optional:true
 *   bool_t     is_cUnitTest1_joined()                     check if joined
 *   int            cUnitTest1_double( int arg );
 *   [dynamic, optional]
 *      void           cUnitTest1_set_descriptor( Descriptor( sTarget1 ) desc );
 *      void           cUnitTest1_unjoin(  );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tTECSUnit_tecsgen.h"
#include <stdio.h>

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif
/* Prototype TECSUnit */
static void
call_sTarget1( CELLCB *p_cellcb, char_t *entry_path, int arg);
/* /Prototype TECSUnit */

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eMain
 * entry port: eMain
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMain_main
 * name:         eMain_main
 * global_name:  tTECSUnit_eMain_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMain_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

  /* Call TECSUnit */
	call_sTarget1( p_cellcb, "Target1.eTarget1", 5);
  /* /Call TECSUnit */

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

/* Function TECSUnit */
static void
call_sTarget1( CELLCB *p_cellcb, char_t *entry_path, int arg){
	ER     ercd;
	void   *rawEntryDesc;
	Descriptor( sTarget1 )      doubleDesc;
	ercd = getRawEntryDescriptor( p_cellcb, entry_path, &rawEntryDesc, "sTarget1" );
	if( ercd == E_OK ){
		setRawEntryDescriptor( doubleDesc, sTarget1, rawEntryDesc );
		cUnitTest1_set_descriptor( doubleDesc );
		if ( cUnitTest1_double( arg ) == 11){
			printf("OK");
		} else {
			printf("NG");
		}
	}
	else {
		printf( "call_sTarget1: errro: cUnitTest1_double() not called" );
	}
}
/* /Function TECSUnit */
