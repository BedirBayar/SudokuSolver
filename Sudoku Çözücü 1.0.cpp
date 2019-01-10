#include <iostream>
#include "stdafx.h"

using namespace std;

class point{
	public:
		int value;
		int line;
		int column;
		int square;
		int prob[9] = {0};
		int probindex;
	
};  // de�er, sat�r, s�tun, kare ve ihtimal listesi olan bir s�n�f

class point sudoku[81]; // point tipinde 81 elemanl� bir dizi (sudokunun kendisi)


void getline(int index){  //her bir eleman�n bulundu�u sat�r� bulan fonksiyon
sudoku[index].line = (index/9)+1;
}

void getcolumn(int index){ // s�tunu bulan fonksiyon
sudoku[index].column = (index%9)+1;
}

void getsquare(int index){ //kareyi bulan fonksiyon
	
	 if(sudoku[index].line<4 && sudoku[index].column<4) sudoku[index].square=1;
else if(sudoku[index].line<4 && sudoku[index].column>=4 && sudoku[index].column<7) sudoku[index].square=2;
else if(sudoku[index].line<4 && sudoku[index].column>=7) sudoku[index].square=3;
else if(sudoku[index].line>=4 && sudoku[index].line<7 && sudoku[index].column<4) sudoku[index].square=4;
else if(sudoku[index].line>=4 && sudoku[index].line<7 && sudoku[index].column>=4 && sudoku[index].column<7) sudoku[index].square=5;
else if(sudoku[index].line>=4 && sudoku[index].line<7 && sudoku[index].column>=7) sudoku[index].square=6;
else if(sudoku[index].line>=7 && sudoku[index].column<4) sudoku[index].square=7;
else if(sudoku[index].line>=7 && sudoku[index].column>=4 && sudoku[index].column<7) sudoku[index].square=8;
else sudoku[index].square=9;

}

void control(int index){ //s�f�ra e�it elemanlar�n yerine gelebilecek say�lar� kontrol eden fonksiyon.
	int ln= sudoku[index].line;
	int clm=sudoku[index].column;
	int sqr=sudoku[index].square;


		for(int j=1;j<=9;j++){
			int flag = 0; //her rakam i�in s�f�rlanan bir flag
			
			for(int i=0;i<81;i++){
				
				//if(i==index) flag++;
					 if(sudoku[i].line==ln && sudoku[i].value==j) continue;
				else if(sudoku[i].column==clm && sudoku[i].value==j) continue;
				else if(sudoku[i].square==sqr && sudoku[i].value==j) continue;
				else flag++; //kontrol edilen rakam ayn� sat�r s�tun veya karede yoksa flag artar. flag eksiksiz artarsa temizdir
					}			
				if(flag==81) sudoku[index].prob[j-1]=j; // temiz ��kanlar� ihtimal listesine atama
				
				}
}

int main(){
	int array[81]={0};
    int d=0,c;
    cout<<"\t\t\t SUDOKU COZUCU 1.0"<<endl<<endl;
	cout<<"81 tane rakami tek tek giriniz : "<<endl<<endl;
	cout<<"UYARI : eger bir rakami yanlis girerseniz, bir sonraki rakami girmeyiniz"<<endl;
	cout<<"bunun yerine yanlis olan rakamin sirasini eksi olarak giriniz (ornegin 41. rakam yanlissa 42'ye -41 yazin)"<<endl;
	cout<<"bu sekilde tekrar o rakama geri donebilirsiniz ";
	cout<<endl<<endl;
	
	for(d=0;d<81;d++){
		cout<<d+1<<" -> ";
		cin>>c;
		if(c<0){
			d=(-2-c);
		}
		else {
		array[d]=c;
		}
	}
	
	
	for(int i=0;i<81;i++){
		sudoku[i].value = array[i]; //dizinin elemanlar�n� nesnelere atama
	}
	for(int i=0;i<81;i++){ //sat�r ve s�tunu bulup atamas� i�in fonksiyonlar� �al��t�r�yoruz
		getline(i);
		getcolumn(i);
	}
	
	for(int i=0;i<81;i++) getsquare(i); // kare fonksiyonu daha sonra �al��mal� ��nk� di�er fonksiyonlar�n sonucuna ba�l�.
	
	
	cout<<endl;
	
	for(int i=0;i<81;i++){  //sudokunun ilk halini yazd�r�r.
		cout<<sudoku[i].value<<"  ";
		if((sudoku[i].column)%3==0) cout<<"  ";
		if((i+1)%9==0){
		if((sudoku[i].line)%3==0) cout<<endl;
		 cout<<endl;
	} 
} 
	
	int i=0,j=0;
	int rakam=0, kare=0; 
	
	int zero=0;
	int sayac1=0, index1=0;
	
	int sayac2=0, index2=0;
	
	int index3=0;  //tek tek b�t�n ihtimallerin say�s�n� bulma ve 1 olanlar� yazd�rma
	int kontrolcu=0;
	
	for(i=0;i<81;i++){
		if(sudoku[i].value==0) zero++; //de�eri s�f�r olan elemanlar�n say�s�
	}

	
	
		for(i=0;i<81;i++){
			if(sudoku[i].value==0) {
				for(int a=0;a<=8;a++) sudoku[i].prob[a]=0;
				sudoku[i].probindex=0;
			control(i);	
				// s�f�r olanlar� kontrol fonksiyonuna g�nderir
						}
					}//d�ng� bitti�inde b�t�n kareler i�in ihtimaller yaz�lm�� olur.
					
	for(i=0;i<81;i++){
		for(j=0;j<9;j++){
			if(sudoku[i].prob[j]!=0){
				sudoku[i].probindex++;
			}
		}
		
			
		}
		cout<<endl;
	
	int k,l,m,inf=0;
	
	while(zero>0 && inf<100000){
		for(i=0;i<81;i++){
				for(j=0;j<9;j++){
					if(sudoku[i].probindex==1 && sudoku[i].prob[j]!=0) {
					sudoku[i].value=sudoku[i].prob[j]; 
					zero--;
					
						for(k=0;k<81;k++){
							if(sudoku[k].value==0){
							for(int a=0;a<=8;a++) sudoku[k].prob[a]=0;
							sudoku[k].probindex=0;
							control(k);		// s�f�r olanlar� kontrol fonksiyonuna g�nderir
						}}
						for(l=0;l<81;l++){
							for(m=0;m<9;m++){
								if(sudoku[l].prob[m]!=0){
								sudoku[l].probindex++;
								}
							}
						}
					}	
				}	
			}
	inf++;	
	}
	if(inf>99999){
		cout<<"\tBASARISIZ!! COK ZOR!!";
	}
	
	else{
	cout<<endl<<"  BASARILI!!"<<endl<<endl<<endl;
	
	for(int i=0;i<81;i++){  //sudokunun son halini yazd�r�r.
		cout<<sudoku[i].value<<"  ";
		if((sudoku[i].column)%3==0) cout<<"  ";
		if((i+1)%9==0){
			cout<<"  ";
		if((sudoku[i].line)%3==0) cout<<endl;
		 cout<<endl;
	} 
} 
}
	
	return 0;
}




