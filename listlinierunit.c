#include "boolean.h"
#include "listlinierunit.h"

#include <stdio.h>
#include <stdlib.h>

//#include "listlinier.c"
//NIM 13516012
//Nama Wildan Dicky Alnatara
//Tanggal 27/10/2017	
//Topik praktikum : unitList Linear
//Deskripsi ADT LIST LINEAR

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyUnit (unitList L){
/* Mengirim true jika list kosong */
	return First(L)==Nil;
	//timelimit();
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyUnit (unitList *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
	First(*L) = Nil;
	//timelimit();
}
/****************** Manajemen Memori ******************/
unitaddress AlokasiUnit (unitinfotype X){
/* Mengirimkan unitaddress hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka unitaddress tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
	unitaddress p = (unitElmtList * )malloc (sizeof(unitElmtList));
	//timelimit();
	if (p==Nil){

		return Nil;
	} else{
		Info(p) = X;
		Next(p) = Nil;
		return p;
	}

}
void DealokasiUnit (unitaddress *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian unitaddress P */
//timelimit();
free(*P);


}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstUnit (unitList *L, unitinfotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
//timelimit();	
unitaddress p = AlokasiUnit(X);
	if (p!=Nil){
		Next(p) = First(*L);
		First(*L) = p;
	}
}
void InsVLastUnit (unitList *L, unitinfotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
//timelimit();
	unitaddress masukan = AlokasiUnit(X);
	if (masukan!=Nil){

		if(IsEmptyUnit(*L)){
			Next(masukan) = First(*L);
			First(*L) = masukan;
		} else{
			unitaddress p =First(*L);

			while(Next(p)!=Nil){
				p=Next(p);

			}
			Next(p)= masukan;

		}
	


	}
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstUnit (unitList *L, unitinfotype *X){
/* I.S. unitList L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
	unitaddress p = First(*L);
	*X = Info(p);
	First(*L) = Next(p);
	Next(p) = Nil;
	DealokasiUnit(&p);


}
void DelVLastUnit (unitList *L, unitinfotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
//timelimit();
	unitaddress p = First(*L);
	unitaddress prec= Nil;
	
	while(Next(p)!=Nil){
		prec = p;
		p= Next(p);

	}
	*X = Info(p);
	if (prec==Nil){
		First(*L) = Nil;
	}  else{
		Next(prec) = Nil;

	}
	DealokasiUnit(&p);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstUnit (unitList *L, unitaddress P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-unitaddress P sebagai elemen pertama */
//timelimit();	
Next(P) = First(*L);
	First(*L) = P;
}
void InsertAfterUnit (unitList *L, unitaddress P, unitaddress Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
//timelimit();
	Next(P) = Next(Prec);
	Next(Prec) = P;


}

void InsertLastUnit (unitList *L, unitaddress P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
//timelimit();	
if (IsEmptyUnit(*L)){
		First(*L) = P;
	} else{
		unitaddress a = First(*L);
		while(Next(a)!=Nil){
			a = Next(a);
		}
		Next(a) = P;

	}

}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstUnit (unitList *L, unitaddress *P){
/* I.S. unitList tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
//timelimit();
	unitaddress a = First(*L);

	*P = a;
	First(*L) = Next (a);


}

void DelLastUnit (unitList *L, unitaddress *P){
/* I.S. unitList tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
	unitaddress last,prec;
//	timelimit();

	last = First(*L);
	prec = Nil;

	while(Next(last)!=Nil){
		prec  = last;
		last = Next(last);


	}
	*P = last;
	if (prec ==Nil){
		First(*L) = Nil;


	} else{
		Next(prec) = Nil;

	}

}
void DelAfterUnit (unitList *L, unitaddress *Pdel, unitaddress Prec){
/* I.S. unitList tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
//timelimit();
	*Pdel = Next(Prec);
	Next(Prec) = Next(Next(Prec));
	Next(*Pdel) =  Nil;
} 
/****************** PROSES SEMUA ELEMEN LIST ******************/

int NbElmtUnit (unitList L){
	//timelimit();
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
	unitaddress p = First(L);
	if (IsEmptyUnit(L)){
		return 0 ;

	} else{
		int counter =0;

		while (p!=Nil){
			counter++;
			p = Next(p);
		}
		return counter;
	}
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1Unit (unitList *L1, unitList *L2, unitList *L3){
	//timelimit();
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
	CreateEmptyUnit(L3);
	if(IsEmptyUnit(*L1)){
		First(*L3)=First(*L2);
	} else{

		First(*L3) = First(*L1);
		unitaddress p = First(*L1);

		while(Next(p)!=Nil){
			p=Next(p);

		}
		Next(p) = First(*L2);


	}

	CreateEmptyUnit(L1);
	CreateEmptyUnit(L2);
}



/*
void nyobainIsengProsedur(unitList *start)
{
    int swapped, i;
    unitaddress ptr1;
    unitaddress lptr = NULL;
 

    if (ptr1 == NULL)
	return;

do
{
	swapped = 0;
	ptr1 = start;

	while (Next(ptr1) != lptr)
	{
		if (Info(ptr1) > Info(Next(ptr1))
		{ 
			swap(ptr1, Next(ptr1));
			swapped = 1;
		}
		ptr1 =Next(ptr1);
	}
	lptr = ptr1;
}
while (swapped);
}


void swap(addres a, adress b)
{
int temp = Info(a);
Info(a) = Info(b);
Info(b) = temp;
}*/




boolean FSearchUnit (unitList L, unitaddress P){
	
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

	unitaddress p = First(L);
	boolean found=false;
	//timelimit();
	while ( (!found) &&(p!=Nil)){
		if (p==P){
			found = true;
		} else{
			p=Next(p);
		}
	}

	if (found){
		return true;
	} else{
		return false;
	}
}


/****************** PROSES TERHADAP LIST ******************/
void DelAllUnit (unitList *L){
/* Delete semua elemen list dan alamat elemen di-dealokasi */
	unitaddress p =First(*L);
	First(*L)=Nil;
	while(p!=Nil){
		DealokasiUnit(&p);
		p=Next(p);
	}

}
void InversListUnit (unitList *L){
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
	if (!IsEmptyUnit(*L)){
		unitaddress p =First(*L);
		if (Next(p)!=Nil){
			unitaddress prec = p;
			p=Next(p);
			Next(prec)=Nil;
			unitaddress temp = p;
			while(temp!=Nil){
				temp=Next(temp);
				Next(p) = prec;
				prec = p;
				p= temp;
			}
			
			First(*L) = prec;
		}
	}

}
unitList FInversListUnit (unitList L){
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. AlokasiUnit mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
	if(!IsEmptyUnit(L)){
		unitaddress p =First(L);
		unitaddress allocf = AlokasiUnit(Info(p));
		unitList baru ;
		First(baru) = allocf;
		
		if (allocf!=Nil){
			p = Next(p);
			boolean gagal = false;
			while((p!=Nil)&& (gagal ==false)){
				unitaddress temp = AlokasiUnit(Info(p));
				if (temp==Nil){
					gagal =true;
				} else{
					InsertFirstUnit(&baru,temp);
					}
				p=Next(p);	
			}
			
			if (gagal){
				DelAllUnit(&baru);
			}
			
			return baru;
		} else{
			return baru;
		}
	}


}
void CopyListUnit (unitList *L1, unitList *L2){
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
	First(*L2) = First(*L1);

}
unitList FCopyListUnit (unitList L){
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
	if(!IsEmptyUnit(L)){
		unitaddress p =First(L);
		unitaddress allocf = AlokasiUnit(Info(p));
		unitList baru ;
		First(baru) = allocf;
		
		if (allocf!=Nil){
			p = Next(p);
			boolean gagal = false;
			while((p!=Nil)&& (gagal ==false)){
				unitaddress temp = AlokasiUnit(Info(p));
				if (temp==Nil){
					gagal =true;
				} else{
					InsertLastUnit(&baru,temp);
					}
				p=Next(p);	
			}
			
			if (gagal){
				DelAllUnit(&baru);
			}
			
			return baru;
		} else{
			return baru;
		}
	}

}

void CpAlokListUnit (unitList Lin, unitList *Lout){
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */

	*Lout = FCopyListUnit(Lin);
}
void KonkatUnit (unitList L1, unitList L2, unitList * L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
	unitList b1,b2;
	CreateEmptyUnit(&b1);
	CreateEmptyUnit(&b2);
	
	b1=FCopyListUnit(L1);
	b2=FCopyListUnit(L2);
	Konkat1Unit(&b1,&b2,L3);

}


void PecahListUnit (unitList *L1, unitList *L2, unitList L){
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmtUnit(L) div 2 */
		CreateEmptyUnit(L1);
		CreateEmptyUnit(L2);
	
	if (IsEmptyUnit(L)){
		CreateEmptyUnit(L1);
		CreateEmptyUnit(L2);
	} else{
			int jumlah= NbElmtUnit(L);
			
			int j1 = jumlah /2;			
			unitaddress p = First(L);
			if (j1 == 0 ){
				CreateEmptyUnit(L1);
			} else{
				int i=1;
				for(i=1;i<=j1;i++){
					unitaddress temp = AlokasiUnit(Info(p));
					
					InsertLastUnit(L1,temp);
					p=Next(p);
				}
			}
			int i;
			for(i=j1+1;i<=jumlah;i++){
				unitaddress temp = AlokasiUnit(Info(p));
					
				InsertLastUnit(L2,temp);
				p=Next(p);
			}
			
			
			
		}
	
}
