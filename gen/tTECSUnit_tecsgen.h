/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tTECSUnit_TECSGEN_H
#define tTECSUnit_TECSGEN_H

/*
 * celltype          :  tTECSUnit
 * global name       :  tTECSUnit
 * idx_is_id(actual) :  no(no)
 * singleton         :  no
 * has_CB            :  true
 * has_INIB          :  false
 * rom               :  yes
 * CB initializer    :  yes
 */

/* グローバルヘッダ #_IGH_# */
#include "global_tecsgen.h"

/* シグニチャヘッダ #_ISH_# */
#include "sTaskBody_tecsgen.h"
#include "sTarget1_tecsgen.h"
#include "sTarget2_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル CB 型宣言 #_CCTPA_# */
typedef struct tag_tTECSUnit_CB {
    /* call port #_TCP_# */
    struct tag_sTarget1_VDES *cUnitTest1;
    struct tag_sTarget2_VDES *cUnitTest2;
    /* call port #_NEP_# */ 
}  tTECSUnit_CB;
extern tTECSUnit_CB  tTECSUnit_CB_tab[];

/* セルタイプのIDX型 #_CTIX_# */
typedef struct tag_tTECSUnit_CB *tTECSUnit_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sTaskBody */
void         tTECSUnit_eMain_main(tTECSUnit_IDX idx);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

#define tTECSUnit_ID_BASE           (1)  /* ID のベース  #_NIDB_# */
#define tTECSUnit_N_CELL            (1)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define tTECSUnit_VALID_IDX(IDX) (1)

/* optional 呼び口をテストするマクロ #_TOCP_# */
#define tTECSUnit_is_cUnitTest1_joined(p_that) \
	  ((p_that)->cUnitTest1!=0)
#define tTECSUnit_is_cUnitTest2_joined(p_that) \
	  ((p_that)->cUnitTest2!=0)

/* セルCBを得るマクロ #_GCB_# */
#define tTECSUnit_GET_CELLCB(idx) (idx)
 /* 呼び口関数マクロ #_CPM_# */
#define tTECSUnit_cUnitTest1_double( p_that, arg ) \
	  (p_that)->cUnitTest1->VMT->double__T( \
	   (p_that)->cUnitTest1, (arg) )
#define tTECSUnit_cUnitTest2_add( p_that, arg1, arg2 ) \
	  (p_that)->cUnitTest2->VMT->add__T( \
	   (p_that)->cUnitTest2, (arg1), (arg2) )

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* 受け口スケルトン関数プロトタイプ宣言（VMT不要最適化により参照するもの） #_EPSP_# */

#ifndef TOPPERS_CB_TYPE_ONLY

/* ディスクリプタ設定関数 #_SDF_# */
/* [dynamic] cUnitTest1 */
Inline void
tTECSUnit_cUnitTest1_set_descriptor( tTECSUnit_CB  *p_that, Descriptor( sTarget1 ) des )
{
    tTECSUnit_CB *p_cellcb = p_that;
    assert( des.vdes != NULL );
    (p_cellcb)->cUnitTest1 = des.vdes;
}

/* [dynamic,optional] cUnitTest1 */
Inline void
tTECSUnit_cUnitTest1_unjoin( tTECSUnit_CB  *p_that  )
{
    tTECSUnit_CB *p_cellcb = p_that;
    (p_cellcb)->cUnitTest1 = NULL;
}

/* [dynamic] cUnitTest2 */
Inline void
tTECSUnit_cUnitTest2_set_descriptor( tTECSUnit_CB  *p_that, Descriptor( sTarget2 ) des )
{
    tTECSUnit_CB *p_cellcb = p_that;
    assert( des.vdes != NULL );
    (p_cellcb)->cUnitTest2 = des.vdes;
}

/* [dynamic,optional] cUnitTest2 */
Inline void
tTECSUnit_cUnitTest2_unjoin( tTECSUnit_CB  *p_that  )
{
    tTECSUnit_CB *p_cellcb = p_that;
    (p_cellcb)->cUnitTest2 = NULL;
}

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

/* IDXの正当性チェックマクロ（短縮形） #_CVIA_# */
#define VALID_IDX(IDX)  tTECSUnit_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tTECSUnit_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tTECSUnit_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tTECSUnit_IDX

/* 呼び口関数マクロ（短縮形）#_CPMA_# */
#define cUnitTest1_double( arg ) \
          tTECSUnit_cUnitTest1_double( p_cellcb, arg )
#define cUnitTest2_add( arg1, arg2 ) \
          tTECSUnit_cUnitTest2_add( p_cellcb, arg1, arg2 )



/* ディスクリプタ設定マクロ（短縮形） #_SDMA_# */
#define cUnitTest1_set_descriptor( desc )\
          tTECSUnit_cUnitTest1_set_descriptor( p_cellcb, desc )
#define cUnitTest1_unjoin(  )\
          tTECSUnit_cUnitTest1_unjoin( p_cellcb )
#define cUnitTest2_set_descriptor( desc )\
          tTECSUnit_cUnitTest2_set_descriptor( p_cellcb, desc )
#define cUnitTest2_unjoin(  )\
          tTECSUnit_cUnitTest2_unjoin( p_cellcb )

/* optional 呼び口をテストするマクロ（短縮形） #_TOCPA_# */
#define is_cUnitTest1_joined()\
		tTECSUnit_is_cUnitTest1_joined(p_cellcb)
#define is_cUnitTest2_joined()\
		tTECSUnit_is_cUnitTest2_joined(p_cellcb)

/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eMain_main       tTECSUnit_eMain_main

/* イテレータコード (FOREACH_CELL)の生成 #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < tTECSUnit_N_CELL; (i)++ ){ \
       (p_cb) = &tTECSUnit_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB(p_that)	(void)(p_that);
#define SET_CB_INIB_POINTER(i,p_that)\
	/* empty */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tTECSUnit_TECSGENH */
