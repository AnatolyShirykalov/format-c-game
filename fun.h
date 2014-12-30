#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>
#include <locale.h>
#define FIGHT 23
#define NOTHING 32
#define KICK 44
#define MEET_ENEMY 98
#define ENEMY_DEATH 212
#define DEATH -19
#define NEW 234
#define QUEST 2354
#define US 2312
#define MOSCOW 333
#define PORECHIE 762
#define VARIANTS 9999
#define SESSIA 4545
#define BEER 8888
typedef struct Item_{
  int hp,atack,defence,dexterity,luck;
} Item;
typedef struct Artem_{
  int max_hp, hp, fk,atack, defence, dexterity, experience, level, beer, money,
                             next_level, uron, luck, girl;//есть ли у него тёлка
  char girl_name[100];
  char name[500];
} Artem;
typedef struct Enemy_{
  char name[100];
  int hp, max_hp, atack, defence, dexterity, money, luck,uron;
} Enemy;
typedef struct Branch_{
  char invitation[500];
} Branch;
int usage(void);
int init_oleg(Enemy *e);
int init_enemy(Enemy *enemy,int level);
int death(Artem*artem);
int kick(Enemy *enemy,Artem*artem);
int mid_uron(Enemy *enemy,Artem*artem,int j);
char * plural(char *dest, int n, char *form1, char*form2,char*form5);
char *rand_message(char *dest,int n,...);
int sauron(int mid,int dexterity);
char *miss_msg(char*dest,char*person);
int bonus_from_enemy(Artem*artem,Enemy*enemy);
int status(Artem *artem);
int e_status(Enemy*artem);
int ask(Artem*artem,char *format,...);

// Rooms
int academ_room(Artem*artem,Enemy*enemy);
int kinomir_room(Artem*artem,Enemy*enemy);
int moscow_room(Artem*artem,Enemy*enemy);
int porechie_room(Artem*artem,Enemy*enemy);
int sessia_room(Artem*artem,Enemy*enemy);
