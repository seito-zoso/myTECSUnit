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
call_sTest1( CELLCB *p_cellcb, char_t *entry_path, int arg);

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
	call_sTest1( p_cellcb, "UnitTest1.eUnitTest1", 5);

}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
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
