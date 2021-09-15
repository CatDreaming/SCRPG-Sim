#include "Minion.h"

//This is a generic minion function
struct Minion {
	int dieSize;
	int bonuses[4];
	int penalties[4];
	int defends[2];
};

// Create a new Minion, without allocating memory to it.
void Minion_init(Minion* self, int dieSize){
	self->dieSize=dieSize;
	int i;
	for(i=0; i<4; i++){
		self->bonuses[i]=0;
		self->penalties[i]=0;
		if(i<3){
			self->defends[i]=0;
		}
	}
}

//Create a new Minion, and allocate memory to it. 
Minion* Minion_create(int dieSize){
	Minion* result = (Minion*) malloc(sizeof(Minion));
	Minion_init(result, dieSize);
	return result;
}

//Destroy the Minion, but don't deallocate it's memory.
void Minion_reset(Minion* minion){
}

//Destroy the Minion, and deallocate it's memory.
void Minion_destroy(Minion* self){
	if(self) {
		Minion_reset(self);
		free(self);
	}
}

//Returns the die size of the minion.
int Minion_dieSize(Minion* self){
	return self->dieSize;
}

//Returns the list of bonuses on the minion
int* Minion_bonuses(Minion* self){
	return self->bonuses;
}

//Returns the list of penalties on the minion
int* Minion_penalties(Minion* self){
	return self->penalties;
}

//Returns the list of defends on the minion
int* Minion_defends(Minion* self){
	return self->defends;
}

int Minion_roll_die(Minion* self){
	printf("This Minion has the following bonuses:\n");
	printf("%d +1's, %d +2's, %d +3's, %d +4's\n",self->bonuses[0],self->bonuses[1],self->bonuses[2],self->bonuses[3]);
	int bonussize[4]={1,2,3,4};
	int bonusused[4]={0,0,0,0};
	for(int i=0; i<4; i++){
		printf("How many +%d bonuses would you like to use? Type a non-negative integer:\n",bonussize[i]);
		scanf("%d", &bonusused[i]);
		while(bonusused[i]<0 || bonusused[i]>self->bonuses[0]){
			printf("Invalid number of bonuses used. How many +%d bonuses would you like to use? Type a non-negative integer:\n",bonussize[i]);
			scanf("%d", &bonusused[i]);
		}
	}
	printf("You will be using: ");
	for(int i=0; i<3; i++){
		printf("%d +%d's,", bonusused[i],bonussize[i]);
	}
	printf("%d +%d's\n", bonusused[3],bonussize[3]);
	return 1;
}