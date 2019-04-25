/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tJSMN_templ.c => src/tJSMN.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * LEN              int16_t          ATTR_LEN
 * key_cell         char_t*          ATTR_key_cell
 * key_entry        char_t*          ATTR_key_entry
 * key_function     char_t*          ATTR_key_function
 * key_arg          char_t*          ATTR_key_arg
 * key_exp          char_t*          ATTR_key_exp
 * json_str         char_t*          VAR_json_str
 * counter          int              VAR_counter
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tJSMN_tecsgen.h"
#include <stdio.h>
#include <jsmn.h>
#define N 128

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

static int
jsoneq( const char *json, jsmntok_t *tok, const char *s);
static void
strcpy_n( char_t *str1, int num, const char *str2 );

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eJSMN
 * entry port: eJSMN
 * signature:  sJSMN
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eJSMN_json_open
 * name:         eJSMN_json_open
 * global_name:  tJSMN_eJSMN_json_open
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eJSMN_json_open(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
    char str_tmp[N];
    int co_flag = 0, co_start, i, j;
    FILE *fp;

    if( ( fp = fopen("target.json", "r") ) == NULL ){
        printf("Failed to open\n");
        return -1;
    }
    while( fgets( str_tmp , N, fp ) != NULL ) {
        co_start = 0;
        for( i = 0; i < N -1; i++ ){
            if( str_tmp[i] == '/' && str_tmp[i+1] == '/' && !co_flag ){
                str_tmp[i] = '\0';
                break;
            }
            if( str_tmp[i] == '/' && str_tmp[i+1] == '*' && !co_flag ){
                co_start = i;
                co_flag = 1;
            }
            if( str_tmp[i] == '*' && str_tmp[i+1] == '/' && co_flag ){
                for(j = 0; str_tmp[(i+2)+j] != '\0'; j++ ){
                    str_tmp[co_start + j] = str_tmp[(i+2)+j];
                }
                str_tmp[co_start + j] = '\0';
                i = co_start;
                co_flag = 0;
            }
        }
        if( co_flag && co_start > 0 ){
            str_tmp[co_start] = '\0';
            strcat( VAR_json_str, str_tmp );
        }
        if( str_tmp[0] != '\0' && str_tmp[0] != '\n' && !co_flag ){
            strcat( VAR_json_str, str_tmp );
        }
    }
    fclose( fp );
    // printf("%s\n", VAR_json_str);
    return 0;
}

/* #[<ENTRY_FUNC>]# eJSMN_json_parse
 * name:         eJSMN_json_parse
 * global_name:  tJSMN_eJSMN_json_parse
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eJSMN_json_parse(CELLIDX idx, char_t* c_path, char_t* e_path, char_t* f_path, int target_num, int btr)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
    int r, i, j, k, l;
    jsmn_parser p;
    jsmntok_t t[128]; /* We expect no more than 128 tokens */
    char target_path[10];

    sprintf( target_path, "target%d", target_num );

    jsmn_init(&p);
    r = jsmn_parse( &p, VAR_json_str, strlen(VAR_json_str), t, sizeof(t)/sizeof(t[0]) );
    if(r < 0){
        printf( "Failed to parse JSON: %d\n", r );
        return -1;
    }
  /* Assume the top-level element is an object */
    if( r < 1 || t[0].type != JSMN_OBJECT ){
        printf( "Object expected\n" );
        return -1;
    }

    if( VAR_counter >= t[0].size ){
        printf( "All target are checked\n" );
        return -1;
    }
  /* Loop over all keys of the root object */
    for( l = 1; l < r; l++ ){
        if( jsoneq( VAR_json_str, &t[l], target_path ) == 0 ){
            if( t[l+1].type != JSMN_OBJECT ){
                printf("Object expected for target\n");
                return -1;
            }
            i = l + 2;
            for( k = 0; k < t[l+1].size; k++ ){
                if( jsoneq( VAR_json_str, &t[i], ATTR_key_cell ) == 0 ){
                    strcpy_n( c_path, t[i+1].end-t[i+1].start, VAR_json_str + t[i+1].start );
                    i += 2;
                }else if( jsoneq( VAR_json_str, &t[i], ATTR_key_entry ) == 0 ){
                    strcpy_n( e_path, t[i+1].end-t[i+1].start, VAR_json_str + t[i+1].start );
                    i += 2;
                }else if( jsoneq( VAR_json_str, &t[i], ATTR_key_function ) == 0 ){
                    strcpy_n( f_path, t[i+1].end-t[i+1].start, VAR_json_str + t[i+1].start );
                    i += 2;
                }else if( jsoneq( VAR_json_str, &t[i], ATTR_key_arg ) == 0 ){
                    if( t[i+1].type != JSMN_ARRAY ){
                        continue;
                    }
                    for( j = 0; j < t[i+1].size; j++ ) {
                        jsmntok_t *g = &t[i+j+2];
                    }
                    i += t[i+1].size + 2;
                }else if( jsoneq( VAR_json_str, &t[i], ATTR_key_exp ) == 0 ) {
                    i += 2;
                }else{
                    printf( "Unexpected key: %.*s\n", t[i].end-t[i].start, VAR_json_str + t[i].start );
                    return -1;
                }
            }
            VAR_counter += 1;
            return 0;
        }
    }
    // printf( "Not exist after %s", target_path );
    // return -1;
    return 1;
}

/* #[<ENTRY_FUNC>]# eJSMN_json_arg
 * name:         eJSMN_json_arg
 * global_name:  tJSMN_eJSMN_json_arg
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eJSMN_json_arg(CELLIDX idx, struct tecsunit_obj* arguments, struct tecsunit_obj* exp_val, int target_num, int btr)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
    int r, i, j, k, l;
    jsmn_parser p;
    jsmntok_t t[128]; /* We expect no more than 128 tokens */
    char str_tmp[8];
    char target_path[10];

    sprintf( target_path, "target%d", target_num );

    jsmn_init(&p);
    r = jsmn_parse( &p, VAR_json_str, strlen(VAR_json_str), t, sizeof(t)/sizeof(t[0]) );
    if( r < 0 ){
        printf( "Failed to parse JSON: %d\n", r );
        return -1;
    }
    /* Assume the top-level element is an object */
    if( r < 1 || t[0].type != JSMN_OBJECT ){
        printf( "Object expected\n" );
        return -1;
    }
  /* Loop over all keys of the root object */

    for( l = 1; l < r; l++ ){
        if( jsoneq( VAR_json_str, &t[l], target_path ) == 0 ){
            if( t[l+1].type != JSMN_OBJECT ){
                printf("Object expected for target\n");
                return -1;
            }
            i = l + 2;

            for( k = 0; k < t[l+1].size; k++ ){
                if( jsoneq( VAR_json_str, &t[i], ATTR_key_cell ) == 0 ){
                    i += 2;
                }else if( jsoneq( VAR_json_str, &t[i], ATTR_key_entry ) == 0 ){
                    i += 2;
                }else if( jsoneq( VAR_json_str, &t[i], ATTR_key_function ) == 0 ){
                    i += 2;
                }else if( jsoneq( VAR_json_str, &t[i], ATTR_key_arg ) == 0 ) {
                    if(t[i+1].type != JSMN_ARRAY){
                        continue; /* We expect groups to be an array of strings */
                    }
                    for( j = 0; j < t[i+1].size; j++ ){
                        jsmntok_t *g = &t[i+j+2];
                        if( g->type == JSMN_STRING ){
                            strcpy( arguments[j].type, "char" );
                            strcpy_n( arguments[j].str, g->end - g->start, VAR_json_str + g->start );
                        }else if( g->type == JSMN_PRIMITIVE ){
                            strcpy_n( arguments[j].str, g->end - g->start, VAR_json_str + g->start );
                            if( strstr( arguments[j].str, "." ) ){
                                strcpy( arguments[j].type, "double" );
                                arguments[j].double_num = atof( arguments[j].str );
                            }else{
                                strcpy( arguments[j].type, "int" );
                                arguments[j].int_num = atoi( arguments[j].str );
                            }
                        }else if( g->type == JSMN_UNDEFINED ){
                            strcpy( arguments[j].type, "undefined" );
                            printf( "Unexpected value: %.*s\n", g->end - g->start, VAR_json_str + g->start );
                        }
                    }
                    i += t[i+1].size + 2;
                }else if( jsoneq( VAR_json_str, &t[i], ATTR_key_exp ) == 0 ){
                    /* We may want to do strtol() here to get numeric value */
                    if( t[i+1].type == JSMN_STRING ){
                        strcpy( exp_val->type, "char" );
                        strcpy_n( exp_val->str, t[i+1].end - t[i+1].start, VAR_json_str + t[i+1].start );
                    }else if( t[i+1].type == JSMN_PRIMITIVE ){
                        strcpy_n( exp_val->str, t[i+1].end - t[i+1].start, VAR_json_str + t[i+1].start );
                        if( strstr( exp_val->str, "." ) ){
                            strcpy( exp_val->type, "double" );
                            exp_val->double_num = atof( exp_val->str );
                        }else{
                            strcpy( exp_val->type, "int" );
                            exp_val->int_num = atoi( exp_val->str );
                        }
                    }else if( t[i+1].type == JSMN_UNDEFINED ){
                        strcpy( exp_val->type, "undefined" );
                        printf( "Unexpected value: %.*s\n", t[i+1].end - t[i+1].start, VAR_json_str + t[i+1].start );
                    }
                    strcpy_n( str_tmp, t[i+1].end-t[i+1].start, VAR_json_str + t[i+1].start );
                    i += 2;
                }else{
                    printf( "Unexpected key: %.*s\n", t[i].end-t[i].start, VAR_json_str + t[i].start );
                    return -1;
                }
            }
        }
        break;
    }
    return 0;
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
static int
jsoneq(const char *json, jsmntok_t *tok, const char *s)
{
    if( tok->type == JSMN_STRING && (int) strlen(s) == tok->end - tok->start
        && strncmp(json + tok->start, s, tok->end - tok->start) == 0 ){
        return 0;
    }
    return -1;
}

static void
strcpy_n( char_t *str1, int num, const char *str2 )
{
    int i;
    for(i = 0; i < num; i++){
        str1[i] = str2[i];
    }
    str1[num] = '\0';
}
