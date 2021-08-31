#include "GameHeader.h"
#include "minion.c"

int main(int argc, char **argv){
	if(argc!=1){
		fprintf(stderr, "This function takes no input.");
		return 0;
	}
	Minion* test = Minion_create(4);
	int* bonus = Minion_bonuses(test);
	int* penalty = Minion_penalties(test);
	int* defend = Minion_defends(test);
	printf("Bonus Array is: {");
	for(int i=0; i<4; i++){
		printf("%d", bonus[i]);
		if(i<3){
			printf(",");
		}
	}
	printf("} and should be:{0,0,0,0}\nPenalty Array is: {");
	for(int i=0; i<4; i++){
		printf("%d,", penalty[i]);
		if(i<3){
			printf(",");
		}
	}
	printf("} and should be:{0,0,0,0}\nDefend Array is: {");
	for(int i=0; i<2; i++){
		printf("%d", defend[i]);
		if(i<1){
			printf(",");
		}
	}
	printf("} and should be:{0,0}\nTests Complete.");
	Minion_destroy(test);
	return 0;
}