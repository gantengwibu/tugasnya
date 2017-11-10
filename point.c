#include "point.h"
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

//NIM 13516012
//Nama Wildan Dicky Alnatara
//Tanggal 31/08/2017	
//Topik praktikum :modularitas c
//Deskripsi modularitas c
POINT MakePOINT (float x, float y)
/* Membentuk sebuah point dari x dan y dengan x sebagai absis dan
y sebagai ordinat */
{ /* KAMUS */
POINT P;
/* ALGORITMA */
Absis(P) = x;
Ordinat(P) = y;
return P;
}

void BacaPOINT (POINT * P)
/* Membentuk P dari x dan y yang dibaca dari keyboard */
{ /* KAMUS */
	float x, y;
	/* ALGORITMA */
	scanf("%f", &x);
	scanf("%f", &y);
	*P = MakePOINT(x,y);
}

void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dg format "(X,Y)" */
{ /* ALGORITMA */
printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2){
	/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
	return (Absis(P1)==Absis(P2))&&(Ordinat(P1)==Ordinat(P2));
	
	
}


boolean NEQ (POINT P1, POINT P2){
	/* Mengirimkan true jika P1 tidak sama dengan P2 */
	return (Absis(P1)!=Absis(P2))||(Ordinat(P1)!=Ordinat(P2));
}


/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
/* Menghasilkan true jika P adalah titik origin */
 return (Absis(P)==0) && (Ordinat(P)==0);
}
boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */
	return Ordinat(P)==0;
}
boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak pada sumbu Y */
	return Absis(P)==0;
}
int Kuadran (POINT P){
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */

/*              dan P tidak terletak di salah satu sumbu */


	if((Absis(P)>0)&&(Ordinat(P)>0)){
		return 1;
	} else if((Absis(P)<0)&&(Ordinat(P)>0)){
		return 2;
	} else if((Absis(P)<0)&&(Ordinat(P)<0)){
		return 3;
	} else {
		return 4;
	}
}


/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P){
	Absis(P)+=1;
	
	return P;
/* Mengirim salinan P dengan absis ditambah satu */    }          
POINT NextY (POINT P){
	Ordinat(P)+=1;
	return P;
/* Mengirim salinan P dengan ordinat ditambah satu */}
POINT PlusDelta (POINT P, float deltaX, float deltaY){
	POINT temp = P;
	
	Absis(temp)+=deltaX;
	Ordinat(temp)+=deltaY;
	
	return temp;
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */}
POINT MirrorOf (POINT P, boolean SbX){
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
	if (SbX==true){
		Ordinat(P)*=-1;
		return P;
	} else{
		Absis(P)*=-1;
		return P;
	}
}
float Jarak0 (POINT P){
/* Menghitung jarak P ke (0,0) */
	return sqrt((Absis(P)*Absis(P))+(Ordinat(P)*Ordinat(P)));
}
float Panjang (POINT P1, POINT P2){
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
//panjang jarak antar titik P1 dan P2
	float selisihx=Absis(P1)-Absis(P2) ,selisihy=Ordinat(P1)-Ordinat(P2);
	return sqrt((selisihx*selisihx)+(selisihy*selisihy));
	
}

void Geser (POINT *P, float deltaX, float deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */

	
	*P=PlusDelta(*P,deltaX,deltaY);
}
void GeserKeSbX (POINT *P){
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
	POINT temp = *P;
	Ordinat(temp)=0;
	*P=temp;
}
void GeserKeSbY (POINT *P){
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
	POINT temp = *P;
	Absis(temp)=0;
	*P=temp;
}
void Mirror (POINT *P, boolean SbX){
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
	*P =  MirrorOf(*P,SbX);
	
}
void Putar (POINT *P, float Sudut){
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
POINT a;
float konversirad= PI*(Sudut/180);
Absis(a)=(Absis(*P)*cos(konversirad))-(Ordinat(*P)*(-1)*sin(konversirad));
Ordinat(a)=(Absis(*P)*(-1)*sin(konversirad))-(Ordinat(*P)*cos(konversirad));
*P = a;
}



