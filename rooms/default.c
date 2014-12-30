#include "../fun.h"
int default_room(Artem*artem,Enemy*enemy){
 switch( ask(artem,"%m%m%f%h%F%H%a%v%v%v","First message",
	"Second message",
	10,// raise furioku by 10
	10,//raise health by 10
	50,//set furioku on 50
	40,//set heath on 40
	"You can choose\n","first variant\n","fight\n","third variant\n> ") ){
  case 1: ask(artem,"%m","first branch"); break;
  case 2: 
    ask(artem,"%m","fight!");
    init_enemy(enemy,1000);
    return fight(artem,enemy);
    break;
  case 3: ask(artem,"%m","third branch"); break;
  case -1: return DEATH;
  }
  return 0;
}
