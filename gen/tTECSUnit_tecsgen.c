/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#include "tTECSUnit_tecsgen.h"
#include "tTECSUnit_factory.h"

/* 受け口ディスクリプタ型 #_EDT_# */
/* eMain : omitted by entry port optimize */

/* 受け口スケルトン関数 #_EPSF_# */
/* eMain : omitted by entry port optimize */

/* 受け口スケルトン関数テーブル #_EPSFT_# */
/* eMain : omitted by entry port optimize */

/* 呼び口の参照する受け口ディスクリプタ(実際の型と相違した定義) #_CPEPD_# */
extern struct tag_sTarget1_VDES Target1_eTarget1_des;
extern struct tag_sTarget2_VDES Target2_eTarget2_des;

/* 呼び口配列 #_CPA_# */

/* 属性・変数の配列 #_AVAI_# */
/* セル CB #_CB_# */
struct tag_tTECSUnit_CB tTECSUnit_CB_tab[] = {
    /* cell: tTECSUnit_CB_tab[0]:  TECSUnit id=1 */
    {
        /* call port (CB_DYNAMIC) #_CP_# */ 
        &Target1_eTarget1_des,                   /* cUnitTest1 #_CCP1_# */
        &Target2_eTarget2_des,                   /* cUnitTest2 #_CCP1_# */
        /* entry port #_EP_# */ 
    },
};

/* 受け口ディスクリプタ #_EPD_# */
/* eMain : omitted by entry port optimize */
