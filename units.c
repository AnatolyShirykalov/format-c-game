#include "fun.h"
int init_enemy(Enemy *enemy,int level){
  srand(time(0));
  rand_message(enemy->name,4,"First enemy", "Second Enemy", "Third Enemy", "Forth Enemy");
  enemy->hp = 40+rand()%(int)sqrt(level);
  enemy->atack = rand()%(int)sqrt(level);
  enemy->dexterity = rand()%(int)sqrt(level);
  enemy->defence = 10+rand()%(int)sqrt(level);
  enemy->uron = 20+rand()%(int)sqrt(level);
  return 0;
}

int status(Artem *artem){
  printf("Текущее состояние %s\n",artem->name);
  printf("Здоровье: %d/%d\n",artem->hp,artem->max_hp);
  if (!strcmp(artem->name,"Артём")) printf("Фуриёку: %d\n",artem->fk);
  if (!strcmp(artem->name,"Артём")) printf("Пиво: %.1f\n",((double)(artem->beer))/2);
  printf("Сила: %d\n",artem->atack);
  printf("Урон: %d\n",artem->uron);
  printf("Ловкость: %d\n",artem->dexterity);
  printf("Защита: %d\n",artem->defence);
  if (!strcmp(artem->name,"Артём")) printf("Опыт: %d/%d\n",artem->experience,artem->next_level);
  if (!strcmp(artem->name,"Артём")) printf("Уровень: %d\n", artem->level);
  //printf("Здоровье: %d\n",artem->hp);
  return 0;
}
int e_status(Enemy*artem){
  printf("Текущее состояние %s\n",artem->name);
  printf("Здоровье: %d\n",artem->hp);
  printf("Сила: %d\n",artem->atack);
  printf("Урон: %d\n",artem->uron);
  printf("Ловкость: %d\n",artem->dexterity);
  printf("Защита: %d\n",artem->defence);
  //printf("Здоровье: %d\n",artem->hp);
  return 0;
}

