#include "fun.h"

int get_task(char *str){
  if (!strcmp(str,"quit\n")||!strcmp(str,"exit\n")) return -1;
  if (!strcmp(str,"status\n")||!strcmp(str,"s\n"))  return  1;
  if (!strcmp(str,"usage\n")||!strcmp(str,"u\n"))   return  2;
  if (!strcmp(str,"y\n")) return NEW;
  if (!strcmp(str,"k\n")) return KICK;
  if (!strcmp(str,"b\n")) return BEER;
  if (!strcmp(str,"us\n")) return US;
  return 0;
}
int r_u_sure(char *msg){
  char answ[500];
  printf("Уверен в своём желании %s?(y/N)\n",msg);
  fgets(answ,500,stdin);
  switch (answ[0]){
    case 'y': return 1;
    case 'N': return 0;
  }
  return 0;
}




int fight(Artem*artem,Enemy*enemy){
   int task; char str[500];
   for (task = -100; task!=ENEMY_DEATH && task!=DEATH; ){
     printf("ХП: %d/%d\tФК: %d\tпива: %d\n> ",artem->hp,artem->max_hp,artem->fk,artem->beer);
     fgets(str,500,stdin); task = get_task(str);
     switch (task){
       case 1: status(artem); break;
       case 2: usage();       break;
       case US: e_status(enemy); break;
       case -1: task = -r_u_sure("выйти"); break;
       case KICK: task = kick(enemy,artem);break;
       case BEER: if (artem->beer>0) ask(artem,"%b%h",-1,5); break;
     }
   }
   if (task==DEATH) return DEATH;
   if (task==ENEMY_DEATH) bonus_from_enemy(artem,enemy);
}

int mid_uron(Enemy *enemy,Artem*artem,int j){
  if (j) 
    return ((double)(enemy->atack))/((double)(artem->defence))*(enemy->uron);
  return ((double)(artem->atack))/((double)(enemy->defence))*(artem->uron);
}

int sauron(int mid,int dexterity){
  srand(time(0));
  if (mid==0) return 0;
  if (dexterity<19 && dexterity >= 0) 
    return ( ((double)(rand()   %(2*mid))) - mid )*
         exp(-((double)(dexterity)/20)) + mid;
  return (int)((((double)(rand()%(2*mid))) - mid )*exp(-1) + mid);
}


int kick(Enemy *enemy,Artem* artem){
  int popal,popad,uron,mid,n,i,j,dext;
  char str[400];
  srand(time(0));
  for (j=0;j<2;j++){
    dext = j<1?(artem->dexterity):enemy->dexterity; 
    mid = mid_uron(enemy,artem,j); 
    n = dext / 19; 
    if (n>0) printf("У %s хватает ловкости сделать %d %s\n",
		  j<1?"тебя":enemy->name,n+1,
		  plural(str,n+1,"удар","удара","ударов"));
    for (i=0; i<=n;i++) {
      if (i==n && dext%19==0) break;
      popal = rand()%100; popad = (i==n?(dext%19)*5:95);  
      if (popal>popad) {  printf("%s\n",miss_msg(str,j<1?"Ты":enemy->name)); continue;}
      uron = sauron(mid,i==n?(dext %19):19); 
      printf("%s нанёс %d единиц%s урона\n",j<1?"Ты":enemy->name,
				uron,plural(str,uron,"у","ы",""));
      if (j) artem->hp-=uron; else enemy->hp-=uron;
      if (enemy->hp<=0) return ENEMY_DEATH;
      if (artem->hp<=0) return DEATH;
      if (j==0) printf("осталось %d\n",enemy->hp);    
    }
  }
  return 0;
}

int bonus_from_enemy(Artem*artem,Enemy*enemy) {
  int skill,bonus; char str[500];
  srand(time(0));
  bonus= enemy->atack + enemy->defence + enemy->dexterity + enemy->hp/5;
  artem->experience += bonus;
  ask(artem,"%a%m","Пиво победителю\n",rand_message(str,3,"Враг сдох","Ты вшатал ему","Славная победа"));
  artem->beer+= (rand()%5 * bonus)/2 + 1;
  printf("Ты получаешь %d опыта\n",bonus);
  while (artem->experience>=artem->next_level){
    artem->level+=1;
    artem->next_level+=rand()%3; artem->next_level*=2;
    printf("Ты стал круче\n");
    skill = rand()%5;
    bonus = sqrt(artem->level);
    switch(skill){
      case 2: artem->hp+=bonus*5; artem->max_hp+=bonus*5;break;
      case 1: artem->atack+=bonus; break;
      case 0: artem->defence+=bonus; break;
      case 3: artem->dexterity+=bonus; break;
      case 4: artem->uron+=bonus; break;
    }
    status(artem);
  }
  return 0;
}

