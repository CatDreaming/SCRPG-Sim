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

int Minion_dieSize(Minion* self){
	return self->dieSize;
}

int* Minion_bonuses(Minion* self){
	return self->bonuses;
}

int* Minion_penalties(Minion* self){
	return self->penalties;
}

int* Minion_defends(Minion* self){
	return self->defends;
}