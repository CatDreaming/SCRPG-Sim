#include <stdio.h>
#include <string.h>

typedef struct Minion Minion;

// Create a new Minion, without allocating memory to it.
void Minion_init(Minion* self, int dieSize);

//Create a new Minion, and allocate memory to it. 
Minion* Minion_create(int dieSize);

//Destroy the Minion, but don't deallocate it's memory.
void Minion_reset(Minion* minion);

//Destroy the Minion, and deallocate it's memory.
void Minion_destroy(Minion* self);

int Minion_dieSize(Minion* self);

int* Minion_bonuses(Minion* self);

int* Minion_penalties(Minion* self);

int* Minion_defends(Minion* self);

int Minion_roll_die(Minion* self);