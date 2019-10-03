//PROJECT ALGORITMA DAN PEMROGRAMAN SEMESTER 2
//Syafaldi Rizkika  (123180127)
//Fauziyah Ahmad I (123180097)

#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
FILE *f_input;
FILE *f_output;

typedef struct{
	char barang[20];
	int banyak,harga;
	int total;
}data;

data belanja,x[100],sortingan[100],tampung,split1[100],split2[100];
char bulan[20];
char ulg;
int i,j,c=0;
int jml_data;
int bnyk_barang;
char namafile[20];
int split;

void import_c();
void input();
void output();
void output_sort();
void input_sort();
void seq_search();
void bin_search(char namafile[]);
void bubble_sort();
void selection_sort();
void insertion_sort();
void shell_sort();
void merge_sort(data x[],int first, int last);
void s_merge(data x[],int low,int mid,int high);
void quick_sort(int first, int last);
void merging();
void splitting();

int main(){
int menu;
	do{
	system("cls");
 
	cout << "===============DATA BELANJA BULANAN===============" << endl;
	cout << "1.Input Data" << endl;
	cout << "2.Output Data" << endl;
	cout << "3.Searching" << endl;
	cout << "4.Transaksi" << endl;
	cout << "5.Exit" << endl;
	cout << "\nPilih Menu	: "; cin >> menu;
	system("cls");
	
	switch(menu){
		case 1 :
		input();
		break;

		case 2 :
		output();
		break;

		case 3 :
	
		cout << "===============MENU SEARCHING===============" << endl;
		cout << "1.Sequential search(Search berdasarkan nama barang)" << endl;
		cout << "2.Binary search(Search berdasarkan total harga barang)" << endl;
		cout << "\nPilih Menu	: ";cin >> menu;
		system("cls");
		
		switch(menu){
			case 1:
			import_c();
			seq_search();
			
			break;

			case 2:
			cout << "===============BINARY SEARCH===============" << endl;
			cout << "1.Bubble sort" << endl;
			cout << "2.Selection sort" << endl;
			cout << "3.Insertion sort" << endl;
			cout << "4.Shell sort" << endl;
			cout << "5.Merge sort" << endl;
			cout << "6.Quick sort" << endl;
			cout << "\nPilih Menu	: "; cin >> menu; cin.ignore();
			system("cls");

			switch(menu){
				case 1:
				import_c();
				bubble_sort();
				cout << "\n================HASIL SORTING===============" << endl;
				output_sort();
				cout << "\n================SIMPAN HASIL SORTING===============" << endl;
				input_sort();
				bin_search(namafile);
				break;

				case 2:
				import_c();
				selection_sort();
				cout << "\n================HASIL SORTING===============" << endl;
				output_sort();
				cout << "\n================SIMPAN HASIL SORTING===============" << endl;
				input_sort();
				bin_search(namafile);
				break;

				case 3:
				import_c();
				insertion_sort();
				cout << "\n================HASIL SORTING===============" << endl;
				output_sort();
				cout << "\n================SIMPAN HASIL SORTING===============" << endl;
				input_sort();
				bin_search(namafile);
				break;

				case 4:
				import_c();
				shell_sort();
				cout << "\n================HASIL SORTING===============" << endl;
				output_sort();
				cout << "\n================SIMPAN HASIL SORTING===============" << endl;
				input_sort();
				bin_search(namafile);
				break;

				case 5:
				import_c();
				merge_sort(x,0,c-1);
				cout << "\n================HASIL SORTING===============" << endl;
				output_sort();
				cout << "\n================SIMPAN HASIL SORTING===============" << endl;
				input_sort();
				bin_search(namafile);
				break;

				case 6:
				import_c();
				int first,last;
				first = 0;
				last = c;
				quick_sort(first,last-1);
				cout << "\n================HASIL SORTING===============" << endl;
				output_sort();
				cout << "\n================SIMPAN HASIL SORTING===============" << endl;
				input_sort();
				bin_search(namafile);
				break;
			}}
		break;

		case 4 :
		cout << "===============TRANSAKSI===============" << endl;
		cout << "1.Merging" << endl;
		cout << "2.Splitting" << endl;
		cout << "\nPilih Menu : "; cin >> menu;cin.ignore();
		system("cls");
		
		switch(menu){
			case 1:
			merging();
			break;
			
			case 2:
			splitting();
			break;
		}
		break;
		
		case 5:
		return(0);
	}
	cout<<"\nKembali ke Menu Utama? (y/n)	: "; cin>>ulg; 
	cout<<endl;
	}while(ulg == 'y' || ulg =='Y');
	
}

void input_sort(){
	cout<<"Nama Baru : "; 
				cin >> namafile; cout << endl;
				strcat(namafile,".txt");
				f_input = fopen(namafile,"w");
				for (i=0;i<c;i++){
					x[i].barang;
					x[i].banyak;
					x[i].harga;
					x[i].total;
        			fwrite(&x[i],sizeof(x[i]),1,f_input);
    			}
    				fclose(f_input);
}
void output_sort(){
for(i=0; i<c; i++){
				cout << "Nama barang	: " << x[i].barang << endl;
				cout << "Jumlah		: " << x[i].banyak << endl;
				cout << "Harga		: " << x[i].harga << endl;
				cout << "Harga total	: " << x[i].total << endl;
				cout << endl;
				}	
}
void import_c(){
				c=0;
				cout << "Bulan yang ingin di buka : "; cin >> bulan;
				strcat(bulan,".txt");
				if ((f_output = fopen(bulan,"rb")) == NULL){
        			cout<<"FILE TIDAK DAPAT DIBUKA \n";
        			exit(1);
				}
    			while (fread(&belanja,sizeof(belanja),1,f_output)){
        		x[c] = belanja;
        		c++;
    			}
				fclose(f_output);
}

void input(){
	cout << "================INPUT DATA===============" << endl;
	cout << "Banyaknya bulan yang ingin di input	: ";cin >> jml_data;
	for(j=0;j<jml_data;j++){
		cout <<	"\nBulan			: "; cin >> bulan;
		strcat(bulan,".txt");
		f_input=fopen(bulan,"w");
		cout << "Banyaknya barang	: ";cin >> bnyk_barang;
		for(i=0;i<bnyk_barang;i++){
			cout << "\nNama barang	: ";cin >> belanja.barang;
			cout << "Jumlah		: ";cin >> belanja.banyak;
			cout << "Harga		: ";cin >> belanja.harga;
			belanja.total=belanja.banyak*belanja.harga;
			cout << "Harga Total	: "<<belanja.total << endl;
			cout << endl;
			fwrite(&belanja,sizeof(belanja),1,f_input);
		}
		fclose(f_input);
	}
}

void output(){
	cout << "================OUTPUT DATA===============" << endl;
	cout << "Bulan/File yang ingin di output : "; cin >> bulan; cout << endl;
	strcat(bulan,".txt");
	if ((f_output = fopen(bulan,"rb")) == NULL){
        cout<<"FILE TIDAK DAPAT DIBUKA \n";
	}
	while(fread(&belanja,sizeof(belanja),1,f_output)){
		cout << "Nama barang	: " << belanja.barang << endl;
		cout << "Jumlah		: " << belanja.banyak << endl;
		cout << "Harga		: " << belanja.harga << endl;
		cout << "Harga total	: " << belanja.total << endl;
		cout << endl;
	}
	fclose(f_output);
}

void insertion_sort(){
	cout << "\n================INSERTION SORT===============" << endl;
	cout<<"\nSORTING DARI HARGA TERENDAH\n";
    int a,b;

	for(a=0; a<c; a++)
	{
		tampung = x[a];
		b=a-1;

		while((tampung.total < x[b].total)&&(b>=0))
		{
			swap(x[b],x[b+1]);
		}
	}

}

void shell_sort(){
	cout << "\n================SHELL  SORT===============" << endl;
	cout<<"\nSORTING DARI HARGA TERENDAH\n";
    for (i=c/2; i>0; i/=2) {
        for (int j=i;j<c;j++) {
            for (int l=j-i; l>=0; l-=i){
                if (x[i+l].total>=x[l].total){
                    break;
                }
                else {
                    tampung = x[l];
                    x[l] =x [l+i];
                    x [l+i]= tampung;
                }
            }
        }
    }
 }

void merge_sort(data x[],int first, int last){
	cout << "\n================MERGE SORT===============" << endl;
	cout<<"\nSORTING DARI HARGA TERENDAH\n";
    int mid,low,high;
    low = first; high = last;
    if(low<high)
    {
        mid = (low+high)/2;
        merge_sort(x,low,mid);
        merge_sort(x,mid+1,high);
        s_merge(x,low,mid,high);
    }
    
}

void s_merge(data x[],int low,int mid,int high)
{	
	

    int w,y,z,a;
    data temp[100];
    w=low;
    y=low;
    z=mid+1;
    while((w<=mid) && (z<=high))
    {
        if(x[w].total<=x[z].total){
            temp[y]=x[w];
            w++;
        }else{
            temp[y]=x[z]; z++;
        }
        y++;
    }

    if(w>mid){
        for(a=z;a<=high;a++){
            temp[y]=x[a]; y++;
        }
    }else{
        for(a=w;a<=mid;a++){
            temp[y]=x[a]; y++;
        }
    }

    for(a=low;a<=high;a++){
        x[a]=temp[a];
    }
}

void quick_sort(int first, int last)
{
	cout << "\n================QUICK SORT===============" << endl;
	cout<<"\nSORTING DARI HARGA TERENDAH\n";
    int low,high,ls;
    low = first;
    high = last;
    ls = x[(first+last)/2].total;
    do{
        while(x[low].total<ls) low++;
        while(x[high].total>ls) high--;
        if(low<=high)
        {
            tampung = x[low];
            x[low++] = x[high];
            x[high--] = tampung;
        }
    }while(low<=high);

    if(first<high) quick_sort(first,high);
    if(low<last) quick_sort(low,last);
}

void bin_search(char namafile[]){
	cout << "\n================BINARY SEARCH===============" << endl;
	f_output = fopen(namafile,"rb");
    int m=0;
    while(fread(&x[m],sizeof(x[m]),1,f_output)){
        sortingan[m]=x[m];
        m++;
    }
    fclose(f_output	);
	int nilai_cari;
    bool found;
    int i,j,k;
    i=0;
    j=m-1;
    k=0;
    found=false;
    cout<<"\n\nMasukkan Harga Total Yang Akan Dicari : "; cin>>nilai_cari;
    while ((!found) && (i<=j)){
        k = (i+j) / 2;
        if (sortingan[k].total == nilai_cari )
            found = true;
        else
        {
            if (nilai_cari < sortingan[k].total){
                j=k - 1;
            }
            else if (nilai_cari > sortingan [k].total){
                i=k+1;
            }
        }
    }
     if (found){
        cout<<"\nData di temukan pada data ke-"<<k+1<<"\n";
        cout << "Nama barang	: " << x[k].barang << endl;
		cout << "Jumlah		: " << x[k].banyak << endl;
		cout << "Harga		: " << x[k].harga << endl;
		cout << "Harga total	: " << x[k].total << endl;
		cout << endl;
    }
    else
		cout << "\nHarga total yang Anda cari tidak ditemukan\n\n";
}

void seq_search(){

	char cari[20];
	bool found;
	int b;
	found = false;
	
	cout << "\n================SEQUENTIAL SEARCH===============" << endl;
	cout<<"Nama barang yang ingin dicari	: "; cin>>cari;

	for(b=0; b<c; b++)
	{
		if(strcmp(x[b].barang,cari)==0)
		{
			found = true;
			break;
		}
	}
	if(found){
			cout << "\n\nData ditemukan di data ke-" << b+1 << endl;
			cout << "\nNama barang	: " << x[b].barang << endl;
			cout << "Jumlah		: " << x[b].banyak << endl;
			cout << "Harga		: " << x[b].harga << endl;
			cout << "Harga total	: " << x[b].total << endl;
			cout << endl;
	
	}
	else
		cout<<"\n\nBarang yang Anda cari tidak ditemukan";
}

void bubble_sort()
{
	cout << "\n================BUBBLE SORT===============" << endl;
	cout<<"\nSORTING DARI HARGA TERENDAH\n";
	for(int a=0; a<c-1; a++)
		{
			for(int b=0; b<c-1-a; b++)
			{
				if(x[b].total > x[b+1].total)
				{
					swap(x[b],x[b+1]);
				}
			}
		}
}

void selection_sort()
{
	cout << "\n================SELECTION SORT===============" << endl;
	cout<<"\nSORTING DARI HARGA TERENDAH\n";
	int a,b;
    for(a=0; a<c; a++)
    {
        for (b=a+1; b<c; b++)
        {
            if(x[a].total > x[b].total)
            {
                swap(x[a],x[b]);
            }
        }
    }
}
void merging (){	
	import_c();
	cout << "\n================MERGING===============" << endl;
	cout << "\nFile berhasil dibuka, silakan input nama file baru untuk menyimpan hasil merging" << endl << endl;
	cout<<"Nama File Baru : ";
	cin >> namafile;
	strcat(namafile,".txt");
	f_input = fopen(namafile,"a");
	for (i=0;i<c;i++){
	x[i].barang;
	x[i].banyak;
	x[i].harga;
	x[i].total;
    fwrite(&x[i],sizeof(x[i]),1,f_input);
    }
    fclose(f_input);
    cout << "\nFile berhasil ditulis, silakan input nama file yang ingin digabungkan dengan file di atas" << endl << endl;
    import_c();
    cout << endl;
	f_input = fopen(namafile,"a");
	for (i=0;i<c;i++){
	x[i].barang;
	x[i].banyak;
	x[i].harga;
	x[i].total;
    fwrite(&x[i],sizeof(x[i]),1,f_input);
    }
    fclose(f_input);
    cout << "File berhasil di merging dan sudah disimpan dengan nama " << namafile <<  endl;

}

void splitting(){
	c=0;
	remove("split1.txt");
	remove("split2.txt");
	cout << "================SPLITTING===============" << endl;
	cout << "\nSPLITTING FILE BERDASARKAN HARGA BARANG"<<endl;
	cout << "\n\nFile yang ingin di splitting : ";cin >> bulan;
	strcat(bulan,".txt");
	f_output = fopen(bulan,"r");
    while (fread(&belanja,sizeof(belanja),1,f_output)){
    x[c] = belanja;
    c++;
    }
	fclose(f_output);
	cout << "Transaksi split dengan harga : ";
	cin >> split;
	for(i=0;i<c;i++){
		if(x[i].harga>split){
			f_input=fopen("split1.txt","a");
			x[i].barang;
					x[i].banyak;
					x[i].harga;
					x[i].total;
  			fwrite(&x[i],sizeof(x[i]),1,f_input);
  			fclose(f_input);
		}
		else{
			f_input=fopen("split2.txt","a");
			x[i].barang;
					x[i].banyak;
					x[i].harga;
					x[i].total;
  			fwrite(&x[i],sizeof(x[i]),1,f_input);
  			fclose(f_input);	
		}
	}
	cout << "File berhasil di splitting dan sudah disimpan dengan nama split1 dan split2" <<  endl;
	cout << "\n\nsplit1 : data barang yang harganya > " << split << endl;
	cout << "\nsplit2 : data barang yang harganya < "<< split << endl;;
	
}

