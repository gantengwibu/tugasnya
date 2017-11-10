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
boolean IsEmpty (unitList L){
/* Mengirim true jika list kosong */
	return First(L)==Nil;
	//timelimit();
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (unitList *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
	First(*L) = Nil;
	//timelimit();
}
/****************** Manajemen Memori ******************/
unitaddress Alokasi (unitinfotype X){
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
void Dealokasi (unitaddress *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian unitaddress P */
//timelimit();
free(*P);


}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (unitList *L, unitinfotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
//timelimit();	
unitaddress p = Alokasi(X);
	if (p!=Nil){
		Next(p) = First(*L);
		First(*L) = p;
	}
}
void InsVLast (unitList *L, unitinfotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
//timelimit();
	unitaddress masukan = Alokasi(X);
	if (masukan!=Nil){

		if(IsEmpty(*L)){
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
void DelVFirst (unitList *L, unitinfotype *X){
/* I.S. unitList L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
	unitaddress p = First(*L);
	*X = Info(p);
	First(*L) = Next(p);
	Next(p) = Nil;
	Dealokasi(&p);


}
void DelVLast (unitList *L, unitinfotype *X){
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
	Dealokasi(&p);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (unitList *L, unitaddress P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-unitaddress P sebagai elemen pertama */
//timelimit();	
Next(P) = First(*L);
	First(*L) = P;
}
void InsertAfter (unitList *L, unitaddress P, unitaddress Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
//timelimit();
	Next(P) = Next(Prec);
	Next(Prec) = P;


}

void InsertLast (unitList *L, unitaddress P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
//timelimit();	
if (IsEmpty(*L)){
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
void DelFirst (unitList *L, unitaddress *P){
/* I.S. unitList tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
//timelimit();
	unitaddress a = First(*L);

	*P = a;
	First(*L) = Next (a);


}

void DelLast (unitList *L, unitaddress *P){
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
void DelAfter (unitList *L, unitaddress *Pdel, unitaddress Prec){
/* I.S. unitList tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
//timelimit();
	*Pdel = Next(Prec);
	Next(Prec) = Next(Next(Prec));
	Next(*Pdel) =  Nil;
} 
/****************** PROSES SEMUA ELEMEN LIST ******************/

int NbElmt (unitList L){
	//timelimit();
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
	unitaddress p = First(L);
	if (IsEmpty(L)){
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
void Konkat1 (unitList *L1, unitList *L2, unitList *L3){
	//timelimit();
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
	CreateEmpty(L3);
	if(IsEmpty(*L1)){
		First(*L3)=First(*L2);
	} else{

		First(*L3) = First(*L1);
		unitaddress p = First(*L1);

		while(Next(p)!=Nil){
			p=Next(p);

		}
		Next(p) = First(*L2);


	}

	CreateEmpty(L1);
	CreateEmpty(L2);
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




boolean FSearch (unitList L, unitaddress P){
	
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
void DelAll (unitList *L){
/* Delete semua elemen list dan alamat elemen di-dealokasi */
	unitaddress p =First(*L);
	First(*L)=Nil;
	while(p!=Nil){
		Dealokasi(&p);
		p=Next(p);
	}

}
void InversList (unitList *L){
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
	if (!IsEmpty(*L)){
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
unitList FInversList (unitList L){
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
	if(!IsEmpty(L)){
		unitaddress p =First(L);
		unitaddress allocf = Alokasi(Info(p));
		unitList baru ;
		First(baru) = allocf;
		
		if (allocf!=Nil){
			p = Next(p);
			boolean gagal = false;
			while((p!=Nil)&& (gagal ==false)){
				unitaddress temp = Alokasi(Info(p));
				if (temp==Nil){
					gagal =true;
				} else{
					InsertFirst(&baru,temp);
					}
				p=Next(p);	
			}
			
			if (gagal){
				DelAll(&baru);
			}
			
			return baru;
		} else{
			return baru;
		}
	}


}
void CopyList (unitList *L1, unitList *L2){
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
	First(*L2) = First(*L1);

}
unitList FCopyList (unitList L){
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
	if(!IsEmpty(L)){
		unitaddress p =First(L);
		unitaddress allocf = Alokasi(Info(p));
		unitList baru ;
		First(baru) = allocf;
		
		if (allocf!=Nil){
			p = Next(p);
			boolean gagal = false;
			while((p!=Nil)&& (gagal ==false)){
				unitaddress temp = Alokasi(Info(p));
				if (temp==Nil){
					gagal =true;
				} else{
					InsertLast(&baru,temp);
					}
				p=Next(p);	
			}
			
			if (gagal){
				DelAll(&baru);
			}
			
			return baru;
		} else{
			return baru;
		}
	}

}

void CpAlokList (unitList Lin, unitList *Lout){
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */

	*Lout = FCopyList(Lin);
}
void Konkat (unitList L1, unitList L2, unitList * L3){
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
	CreateEmpty(&b1);
	CreateEmpty(&b2);
	
	b1=FCopyList(L1);
	b2=FCopyList(L2);
	Konkat1(&b1,&b2,L3);

}


void PecahList (unitList *L1, unitList *L2, unitList L){
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
		CreateEmpty(L1);
		CreateEmpty(L2);
	
	if (IsEmpty(L)){
		CreateEmpty(L1);
		CreateEmpty(L2);
	} else{
			int jumlah= NbElmt(L);
			
			int j1 = jumlah /2;			
			unitaddress p = First(L);
			if (j1 == 0 ){
				CreateEmpty(L1);
			} else{
				int i=1;
				for(i=1;i<=j1;i++){
					unitaddress temp = Alokasi(Info(p));
					
					InsertLast(L1,temp);
					p=Next(p);
				}
			}
			int i;
			for(i=j1+1;i<=jumlah;i++){
				unitaddress temp = Alokasi(Info(p));
					
				InsertLast(L2,temp);
				p=Next(p);
			}
			
			
			
		}
	
}
