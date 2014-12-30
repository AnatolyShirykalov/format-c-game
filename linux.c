#include "fun.h"
int main(int argc,char **argv){
  Artem art,*artem; Enemy enm,*enemy;
  setlocale(0, "");
  art.hp = art.max_hp = 50; art.fk = 40; art.beer = 0; art.girl = 0; art.girl_name[0]='\0';  art.next_level = 10;
  art.atack = 10; art.defence = 10; art.luck = 10; art.dexterity = 7; art.uron = 10; art.level = 1; art.experience=1;
  strcpy(art.name,"Артём\0");
  artem = &art;
  enemy = &enm;
  if (default_room(artem,enemy)==DEATH) death(artem);
  return 0;
}
