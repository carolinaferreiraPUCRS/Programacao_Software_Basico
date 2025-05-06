#include <stdio.h>
#include "fracao.h"

int main() {
   fracao_t a = {2,5}, b = {2,6}, res;
   char a_str[40], b_str[40], res_str[40];
   fracao2str(a_str,a);
   fracao2str(b_str,b);
   res = soma(a,b);
   fracao2str(res_str,res);    // 2/5 + 2/6 = 11/15
   printf("%s + %s = %s\n", a_str, b_str, res_str);
   res = subtrai(a,b);
   fracao2str(res_str,res);    // 2/5 - 2/6 = 1/15
   printf("%s - %s = %s\n", a_str, b_str, res_str);
   res = multiplica(a,b);
   fracao2str(res_str,res);    // 2/5 * 2/6 = 2/15
   printf("%s * %s = %s\n", a_str, b_str, res_str);
   res = divide(a,b);
   fracao2str(res_str,res);    // 2/5 / 2/6 = 6/5
   printf("%s / %s = %s\n", a_str, b_str, res_str);
   return 0;
}
