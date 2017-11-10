#include <stdio.h>
#include "matriksPeta.h"
#include "pcolor.c"
//NIM 13516012
//Nama Wildan Dicky Alnatara
//Tanggal 13 09 2017
//Topik praktikum : matriks
//Deskripsi buat adt matriks

/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeNormalMATRIKS (int NB, int NK, MATRIKS * M){
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
	NBrsEff(*M)=NB;
	NKolEff(*M)=NK;
	int j,i;
	for (i = GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
		for(j = GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
			Elmt(*M,i,j).jenisPetak = 'N';
			Absis(Elmt(*M,i,j).p) = i;
			Ordinat (Elmt(*M,i,j).p) = j;
			infounitpetak (*M,i,j)= Nil;
		}
	}


}

void InitializeCastleTemple(MATRIKS *m){
//I.S Usahakan panggil fungsi ini sesudah memanggil fungsi makenormalmatriks untuk menginisiasi
//matriks mnya agara tidak bocor
//F.S sudah ada templenya serta castle mili player R dan B

	int kolompertama=GetFirstIdxKol(*m);
	int barisakhir=GetLastIdxBrs(*m);
	int kolomakhir=GetLastIdxKol(*m);
	int barispertama=GetFirstIdxBrs(*m);

	//Set Tower Red Player
	infoJPetak(*m,barisakhir-1,kolompertama+1) = 'T';
	infomilik(*m,barisakhir-1,kolompertama+1) = 'R';
	//Set Tower Blue Player
	infoJPetak(*m,barispertama+1,kolomakhir-1) = 'T';
	infomilik(*m,barispertama+1,kolomakhir-1) = 'B';
	//Set Red Castle
		//Bawah
		infoJPetak(*m,barisakhir,kolompertama+1) = 'C';
		infomilik(*m,barisakhir,kolompertama+1) = 'R';
		//Atas
		infoJPetak(*m,barisakhir-2,kolompertama+1) = 'C';
		infomilik(*m,barisakhir-2,kolompertama+1) = 'R';
		//Kiri
		infoJPetak(*m,barisakhir-1,kolompertama) = 'C';
		infomilik(*m,barisakhir-1,kolompertama) = 'R';		
		//Kanan
		infoJPetak(*m,barisakhir-1,kolompertama+2) = 'C';
		infomilik(*m,barisakhir-1,kolompertama+2) = 'R';	
	//Set Blue Castle
		//Bawah
		infoJPetak(*m,barispertama+2,kolomakhir-1) = 'C';
		infomilik(*m,barispertama+2,kolomakhir-1) = 'B';
		//Atas
		infoJPetak(*m,barispertama,kolomakhir-1) = 'C';
		infomilik(*m,barispertama,kolomakhir-1) = 'B';
		//Kiri
		infoJPetak(*m,barispertama+1,kolomakhir-2) = 'C';
		infomilik(*m,barispertama+1,kolomakhir-2) = 'B';	
		//Kanan
		infoJPetak(*m,barispertama+1,kolomakhir) = 'C';
		infomilik(*m,barispertama+1,kolomakhir) = 'B';		
}
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
	NBrsEff(*M)=NB;
	NKolEff(*M)=NK;
	int j,i;

	

}
/* *** Nampilin ke layar *** */

void printMatriks(MATRIKS m){
	int i,j;
	for(i =GetFirstIdxBrs(m);i<=GetLastIdxBrs(m);i++){
		//Membuat Garis lurus bintang;
		for(j=1;j<=(NBrsEff(m)*4)+1;j++){
			printf("*");
		}
		printf("\n");
		//****************************************************
		//Bagian menuliskan jenis petak
		for(j=GetFirstIdxBrs(m);j<=GetLastIdxKol(m);j++){
			if (Elmt(m,i,j).jenisPetak=='N'){
				printf("*   ");
			} else {
				printf("* ");
				if (infomilik(m,i,j)=='R'){
					print_red(infoJPetak(m,i,j));
				} else{
					print_blue(infoJPetak(m,i,j));
				}
				printf(" ");
			}
		}
		printf("*\n");
		//Sub baris kedua untuk menapilkan unit jika ada
		for(j=GetFirstIdxBrs(m);j<=GetLastIdxKol(m);j++){
			if (infounitpetak(m,i,j)==Nil){
				printf("*   ");
			} else{
				printf("* ");
				unitaddress p = infounitpetak(m,i,j);
				if (selected(UnitInfo(p))){
					print_green(jenisUnit(UnitInfo(p)));
				} else{
					if (infomilik(m,i,j)=='R'){
						print_red(jenisUnit(UnitInfo(p)));
					} else{
						print_blue(jenisUnit(UnitInfo(p)));
					}
				}

				printf(" ");
			}
		}
		printf("*\n");
		for(j=GetFirstIdxBrs(m);j<=GetLastIdxKol(m);j++){
			
				printf("*   ");
			
		}
		printf("*\n");
	}
	for(j=1;j<=(NBrsEff(m)*4)+1;j++){
		printf("*");
	}
	printf("\n");

}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

	return (i >= BrsMin && i <= BrsMax) && (j >= BrsMin && j <= BrsMax) ;
}
/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terkecil M */
	return BrsMin;

}
indeks GetFirstIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terkecil M */

	return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terbesar M */
	return NBrsEff(M)+BrsMin -1;


}
indeks GetLastIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terbesar M */
	return NKolEff(M)+KolMin -1;


}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
	return (i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M) )&&(j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M) );

}
ElType GetElmtDiagonal (MATRIKS M, indeks i){
/* Mengirimkan elemen M(i,i) */
	return Elmt(M,i,i);

}
/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
/* Melakukan assignment MHsl  MIn */
	indeks i,j;
	MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);
	for (i=GetFirstIdxBrs(MIn);i<=GetLastIdxBrs(MIn);i++){
		for (j=GetFirstIdxKol(MIn);j<=GetLastIdxKol(MIn);j++){
				Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
		}		
	}

}


                              





/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */


boolean EQSize (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

	return (NBrsEff(M1) == NBrsEff (M2)) &&  (NKolEff (M1) == NKolEff (M2)) ;

}
/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
/* Mengirimkan banyaknya elemen M */

	return NBrsEff(M)*NKolEff(M);
}
/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
	return NBrsEff(M) == NKolEff(M);
}

void Transpose (MATRIKS * M){
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
	MATRIKS temp;
	indeks i,j;
	MakeMATRIKS(NBrsEff(*M),NKolEff(*M),&temp);
		for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
			for(j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
				Elmt(temp,i,j)=Elmt(*M,j,i);			
			}
		}	

	*M= temp;
}









/*int main(){
	MATRIKS a;
	MakeNormalMATRIKS(8,8,&a);
	InitializeCastleTemple(&a);
	printMatriks(a);
}*/

