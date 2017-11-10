#include "point.h"
#include "listlinierunit.h"
#include "boolean.h"

#ifndef adtunit_H
#define adtunit_H
typedef struct {
	char jenis; // '0' Kalau kosong
	int maxHealth ;
	int health;
	int attack;
	int maxMovePoint;
	int movePoint;
	int tipeSerangan; // Melee = 1, Ranged = 0
	int price;
	boolean attackChance;
	POINT lokasi;
	
	boolean isSelected;
} unit;


/* Selektor UNit */
#define jenisUnit(P) P.jenis
#define maxH(P) P.maxHealth
#define Health(P) P.health
#define Attack(P) P.attack
#define maxMove(P) P.maxMovePoint
#define moveP(P) P.movePoint
#define AtkType(P) P.tipeSerangan
#define atkchance(P) P.attackChance
#define loacation(P) P.lokasi
#define harga(P) P.price
#define selected(P) P.isSelected

#endif