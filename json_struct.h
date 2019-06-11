struct tecsunit_obj{
  char    type[16]; /* TECSInfoにより型名を格納します */
  union{
/* 以下の型よりtypeから判断し、1つだけ選択される */
/* 参照：https://tecs-docs.readthedocs.io/ja/latest/tecs/CDLref_type.html?highlight=%E5%9E%8B */
    /* 組込み型：範囲が不明瞭 */
    char    mem_char;
    int     mem_int;
    short   mem_short;
    long    mem_long;
    float   mem_float;
    double  mem_double;
    /* typedef型 */
    int_t     mem_int_t;
    uint_t    mem_uint_t;
    long_t    mem_long_t;
    ulong_t   mem_ulong_t;
    short_t   mem_short_t;
    ushort_t  mem_ushort_t;
    /* 組込み型：範囲が明瞭 */
    int8_t      mem_int8_t;
    int16_t     mem_int16_t;
    int32_t     mem_int32_t;
    int64_t     mem_int64_t;
    uint8_t     mem_uint8_t;
    uint16_t    mem_uint16_t;
    uint32_t    mem_uint32_t;
    uint64_t    mem_uint64_t;
    float32_t   mem_float32_t;
    double64_t  mem_double64_t;
    char_t      mem_char_t;
    /* ポインタ */
    char*   mem_char_buf;
    char_t* mem_char_t_buf;
    /* 配列 ※サイズは事前に決めなければいけない。 */
    int8_t     mem_int8_t_buf[10];
    // double* mem_double_p;
  } data;
};