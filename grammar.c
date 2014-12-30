#include "fun.h"
char * plural(char *dest, int n, char *form1, char*form2,char*form5){
  int m100,			m10;
  m100 = abs(n) % 100;		m10 = m100 % 10;
  if (m100 > 10 && m100 < 20)   return strcpy(dest,form5);
  if (m10  >  1 && m10  <  5)	return strcpy(dest,form2);
  if (m10  == 1) 		return strcpy(dest,form1);
  				return strcpy(dest,form5);
}
