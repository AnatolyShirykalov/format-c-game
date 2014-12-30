#include "fun.h"
int usage(void){
  int n,i;
  printf("Ну как вообще жизнь устроена\n");
  printf("status или s\tтекущее состояние(hp, пиво и т. д.)\n");
  printf("usage или u\tпоказать команды\n");
  printf("exit или quit\tвыйти\n");
  printf("b\t пить пиво");
  printf("k пинать суку\n");
  return 0;
}


char *rand_message(char *dest,int n,...){
  int i,p; va_list msg;
  srand(time(0));  p = rand()%n;
  for (i=0, va_start(msg,n); i<=p; i++ )
    strcpy(dest,va_arg(msg,char *) );
  va_end(msg);
  return dest;
}

char *miss_msg(char*dest,char*person){
  char str[500];
  sprintf(str,"%s %s\0",person,"промазал\n");
  return rand_message(dest,3,str,"Мимо\n","Попади уже\n");
}

int ask(Artem*artem,char *fmt,...){
  va_list msg; char *s; int i,d,item; char str[500],*label,*status_text;
  va_start(msg,*fmt); item = 0;
  str[0]='\0'; status_text = label = str;
  while(*fmt) {
    switch (*fmt++){
    case 'm': //какое-то сообшение
      s = va_arg(msg,char*); // прочесть его
      printf("%s",s); getchar(); //Ну и вывести сразу с ожиданием enter
      break;
    case 'a': //сам вопрос
      s = va_arg(msg,char*); // прочесть его
      printf("%s",s);
      break;
    case 'v': // Начать слушать вариант ответа
      s = va_arg(msg,char*); // сразу принимается текст варианта
      if (label[0]!='\0') printf("%c %s",label[item++],s); //Модифицированный label (вместо 1 2 3 например w d)
      else printf("%d %s",++item,s); // печатается приглашение
      break;
    case 'h': // change health points
      artem->hp += va_arg(msg,int); 
      if (artem->hp <=0) return -1;
      break;
    case 'H':
      artem->hp = va_arg(msg,int);
      break;
    case 'f': // change fk points
      d = va_arg(msg,int);
      artem->fk += d;
      if (artem->fk <= 0) artem->fk = 0;
      break;
    case 'F':
      artem->fk = va_arg(msg,int);
      break;
    case 'A':              /* int */
      label = va_arg(msg, char *);
      break;
    case 's': // Изменить стандартный текст статуса
      status_text = va_arg(msg, char *);
      break;
    case 'b':
      artem->beer +=va_arg(msg,int);
      break;
    case 'o': // open question
      s = va_arg(msg,char*); 
      fgets(s,500,stdin); s[strlen(s)-1]='\0';
      return -10000;
    }
  }
  va_end(msg);
  if (item ==0) return 0; // Не надо ждать ответа
  if (label[0]=='\0'){  // Ловить числовой ответ
    for (str[0]='\0'; str[0]< '1'||(str[0]>(item<10?item+'0':'9')); ) {
      fgets(str,500,stdin); 
      if (str[0]=='s') {
	if (status_text[0]) printf("%s",status_text); else status(artem);
      }
    }
    return atoi(str);
  }
  else{// Ловить ответ в виде символа
    while(1){
      fgets(str,500,stdin);
      if (str[0]=='s') {
	if (status_text[0]) printf("%s",status_text); else status(artem);
      }
      for (i=0;label[i]; i++) if (label[i]==str[0]) return label[i];
    }
  }  
}
int death(Artem*artem){
  ask(artem,"%m","You died. Game over. Type Enter to exit\n");
  exit ;
}
