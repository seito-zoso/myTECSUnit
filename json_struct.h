struct tecsunit_obj{
  char    type[16]; /* TECSInfoにより型名を格納します */
  union{ /* typeから判断し1つだけ選択される */
    int     mem_int;
    int*    mem_int_p;
    double  mem_double;
    double* mem_double_p;
    char*   mem_char;
  } data;
};