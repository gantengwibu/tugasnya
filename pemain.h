#include "point.h"
#include "listlinierunit.h"
#include "boolean.h"

#ifndef pemain_H
#define pemain_H

typedef struct{
	//char nomorPlayer;// 1 atau 2
	char warna; //bisa R bisa B, R untuk  merah , b untuk biru. 
	int income;
	int upkeep;
	
	unitList listUnit;
	//List Village;   <<<Bingung ini tipe datanya apa

} pemain;



#endif