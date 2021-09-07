#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

struct data{
    int nik, telp;
    char nama[30],ttl[20], email[30];
}dat[15];

struct node{
    char hist[100];
    struct node *next;
};

int jum=0, tot=0,temp, oy, temu, x;
char temps[100];
struct node* head = NULL;

void Posisi();
void Kotak1();
void Login();
void Loading();
void Ulang_Login();
void Kotak2();
void Tampilan_Tetap();
void Mencari();

void append(struct node** head_ref, char histo[]){

    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node *last = *head_ref;

    strcpy(new_node->hist, histo);
    new_node->next = NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
}


void printlist(struct node *node){
    while(node != NULL){
        printf("%s \n", node->hist);
        node = node->next;
    }
}
void tambah(){

    Posisi(6,25);
    printf("=== Tambah Data Tamu Hotel ====");
    Posisi(6,27);
    printf("Masukkan Jumlah Data Pengunjung Yang Akan Dimasukkan (max = 15): "); scanf("%d", &jum);

        for(int i = 0 ; i < jum ; i++){
            system("cls");
            Tampilan_Tetap();
            Posisi(6,25);
            printf("=== Tambah Data ====");
            Posisi(6,27);
            printf("Masukkan Jumlah Data Pengunjung Yang Akan Dimasukkan (max = 15): %d", jum);
            Posisi(6,29);
            printf("Data ke %d", i+1);
            Posisi(6,31);
            printf("Tanggal     : ");
            Posisi(6,32);
            printf("Nama        :    ");
            Posisi(6,33);
            printf("Nomor Kamar : ");
            Posisi(6,34);
            printf("Telepon     : ");
            Posisi(6,35);
            printf("Harga       : ");
            Posisi(20,31);
            scanf(" %[^\n]%*c", &dat[i+tot].ttl);
            Posisi(20,32);
            scanf(" %[^\n]%*c", &dat[i+tot].nama);
            Posisi(20,33);
            scanf("%d", &dat[i+tot].nik);
            Posisi(20,34);
            scanf("%d", &dat[i+tot].telp);
            Posisi(20,35);
            scanf(" %[^\n]%*c", &dat[i+tot].email);
        }

    snprintf(temps, sizeof(temps), "  ADMIN menambahkan %d data", jum);
    append(&head, temps);
    tot += jum;
    Posisi(9,38);
    printf("*Notifikasi*");
    Posisi(6,39);
    printf("%d Data Tamu Berhasil Ditambahkan", tot);
    Posisi(6,41);
    printf("Tekan Enter Untuk Kembali ke Menu"); getch();
}

void lihat(){
    for(int i = 0 ; i < tot ; i++){
            if(i==0 || i%3==0){
                system("cls");
                Tampilan_Tetap();
                Posisi(6,25);
                printf("===== Daftar Data Tamu Hotel =====\n\n");
                Posisi(6,27);
                printf("Data ke %d", i+1);
                Posisi(6,29);
                printf("Tanggal     : %s", dat[i].ttl);
                Posisi(6,30);
                printf("Nama        : %s", dat[i].nama);
                Posisi(6,31);
                printf("Nomor Kamar : %d", dat[i].nik);
                Posisi(6,32);
                printf("Telepon     : %d", dat[i].telp);
                Posisi(6,33);
                printf("Harga       : %s", dat[i].email);
            }else if(i==1 || i==4 || i==7 || i==10 || i==13){
                Posisi(6,35);
                printf("Data ke %d", i+1);
                Posisi(6,37);
                printf("Tanggal     : %s", dat[i].ttl);
                Posisi(6,38);
                printf("Nama        : %s", dat[i].nama);
                Posisi(6,39);
                printf("Nomor Kamar : %d", dat[i].nik);
                Posisi(6,40);
                printf("Telepon     : %d", dat[i].telp);
                Posisi(6,41);
                printf("Harga       : %s", dat[i].email);
            }else{
                Posisi(6,43);
                printf("Data ke %d", i+1);
                Posisi(6,45);
                printf("Tanggal     : %s", dat[i].ttl);
                Posisi(6,46);
                printf("Nama        : %s", dat[i].nama);
                Posisi(6,47);
                printf("Nomor Kamar : %d", dat[i].nik);
                Posisi(6,48);
                printf("Telepon     : %d", dat[i].telp);
                Posisi(6,49);
                printf("Harga       : %s", dat[i].email);
                Posisi(6,51);
                getch();
            }
        }

    Posisi(6,51);
    printf("Tekan Enter Untuk Kembali ke Menu"); getch();
}

void urut(){

  for (int i = 0 ; i < tot - 1; i++){
    for (int j = 0 ; j < tot - i - 1; j++){
      if (dat[j].nik > dat[j+1].nik){
        temp = dat[j].nik;
        dat[j].nik = dat[j+1].nik;
        dat[j+1].nik = temp;

        strcpy(temps, dat[j].nama);
        strcpy(dat[j].nama, dat[j+1].nama);
        strcpy(dat[j+1].nama, temps);

        temp = dat[j].telp;
        dat[j].telp = dat[j+1].telp;
        dat[j+1].telp = temp;

        strcpy(temps, dat[j].ttl);
        strcpy(dat[j].ttl, dat[j+1].ttl);
        strcpy(dat[j+1].ttl, temps);

        strcpy(temps, dat[j].email);
        strcpy(dat[j].email, dat[j+1].email);
        strcpy(dat[j+1].email, temps);
      }
    }
  }

  for(int i = 0 ; i < tot ; i++){
            if(i==0 || i%3==0){
                system("cls");
                Tampilan_Tetap();
                Posisi(6,25);
                printf("===== Pengurutan Data Tamu Hotel Berdasarkan Nomor Kamar =====\n\n");
                Posisi(6,27);
                printf("Data ke %d", i+1);
                Posisi(6,29);
                printf("Tanggal     : %s", dat[i].ttl);
                Posisi(6,30);
                printf("Nama        : %s", dat[i].nama);
                Posisi(6,31);
                printf("Nomor Kamar : %d", dat[i].nik);
                Posisi(6,32);
                printf("Telepon     : %d", dat[i].telp);
                Posisi(6,33);
                printf("Harga       : %s", dat[i].email);
            }else if(i==1 || i==4 || i==7 || i==10 || i==13){
                Posisi(6,35);
                printf("Data ke %d", i+1);
                Posisi(6,37);
                printf("Tanggal     : %s", dat[i].ttl);
                Posisi(6,38);
                printf("Nama        : %s", dat[i].nama);
                Posisi(6,39);
                printf("Nomor Kamar : %d", dat[i].nik);
                Posisi(6,40);
                printf("Telepon     : %d", dat[i].telp);
                Posisi(6,41);
                printf("Harga       : %s", dat[i].email);
            }else{
                Posisi(6,43);
                printf("Data ke %d", i+1);
                Posisi(6,45);
                printf("Tanggal     : %s", dat[i].ttl);
                Posisi(6,46);
                printf("Nama        : %s", dat[i].nama);
                Posisi(6,47);
                printf("Nomor Kamar : %d", dat[i].nik);
                Posisi(6,48);
                printf("Telepon     : %d", dat[i].telp);
                Posisi(6,49);
                printf("Harga       : %s", dat[i].email);
                Posisi(6,51);getch();
            }
        }

    Posisi(6,29);
    strcpy(temps, "  ADMIN mengurutkan data penduduk");
    append(&head, temps);

    Posisi(6,51);
    printf("Tekan Enter Untuk Kembali ke Menu"); getch();
}

void cari(){
    Posisi(45,13);
    printf("==Pencarian Data Tamu Hotel==");
    Posisi(45,15);
    printf("Masukkan Nomor Kamar : "); scanf("%d", &oy);
    temu = 0;
    Mencari();
    for( x = 0; x <= tot; x++){
        if(oy == dat[x].nik){
            temu = 1;
            break;
        }
    }
    if(temu == 1 ){
        Posisi(6,25);
        printf("~ Data itemukan ~");
        Posisi(6,27);
        printf("Tanggal     : %s", dat[x].ttl);
        Posisi(6,28);
        printf("Nama        : %s", dat[x].nama);
        Posisi(6,29);
        printf("Nomor Kamar : %d", dat[x].nik);
        Posisi(6,30);
        printf("Telepon     : %d", dat[x].telp);
        Posisi(6,31);
        printf("Harga       : %s", dat[x].email);
    }
    else{
        Posisi(6,28);
        printf("~ Data Tidak Ditemukan ~");
    }

    snprintf(temps, sizeof(temps), "  ADMIN mencari data dari Nomor Kamar : %d", oy);
    append(&head, temps);
    Posisi(6,33);
    printf("Tekan Enter Untuk Kembali ke Menu"); getch();
}
void hapus(){
    char jawab, ayam[30];

    Posisi(45,13);
    printf("=== Hapus Data Tamu Hotel ===");
    Posisi(45,15);
    printf("Masukkan Nomor Kamar : "); scanf("%d", &oy);
    Mencari();
    temu = 0;
    for( x = 0; x <= tot; x++){
        if(oy == dat[x].nik){
            temu = 1;
            break;
        }
    }
    if(temu == 1 ){
        Posisi(6,25);
        printf("Data Tamu Hotel Berikut akan Dihapus :");
        Posisi(6,27);
        printf("Tanggal     : %s", dat[x].ttl);
        Posisi(6,28);
        printf("Nama        : %s", dat[x].nama);
        Posisi(6,29);
        printf("Nomor Kamar : %d", dat[x].nik);
        Posisi(6,30);
        printf("Telepon     : %d", dat[x].telp);
        Posisi(6,31);
        printf("Harga       : %s", dat[x].email);

        snprintf(temps, sizeof(temps), "  ADMIN menghapus data penduduk NIK : %d", dat[x].nik);
        append(&head, temps);

        for(int i = 0; i < tot; i++){
            strcpy(dat[x+i].nama, dat[x+1+i].nama);
            dat[x+i].nik = dat[x+1+i].nik;
            dat[x+i].telp = dat[x+1+i].telp;
            strcpy(dat[x+i].ttl, dat[x+1+i].ttl);
            strcpy(dat[x+i].email, dat[x+1+i].email);
            }
        tot -= 1;
    }
    else{
            Posisi(6,28);
            printf("~ Data Tidak Ditemukan ~");
    }

    Posisi(6,33);
    printf("Tekan Enter Untuk Kembali ke Menu"); getch();
}

void edit(){
    char stemp[30],ayam[30];
    int jaw=0;

    Posisi(45,13);
    printf("=== Ubah Data Tamu Hotel ===");
    Posisi(45,15);
    printf("Masukkan Nomor Kamar : "); scanf("%d", &oy);
    Mencari();
    temu = 0;
    for( x = 0; x <= tot; x++){
        if(oy == dat[x].nik){
            temu = 1;
            break;
        }
    }
    if(temu == 1 ){
            Posisi(6,25);
            printf("Data Tamu Hotel Berikut akan Diubah :");
            Posisi(6,27);
            printf("Tanggal     : %s", dat[x].ttl);
            Posisi(6,28);
            printf("Nama        : %s", dat[x].nama);
            Posisi(6,29);
            printf("Nomor Kamar : %d", dat[x].nik);
            Posisi(6,30);
            printf("Telepon     : %d", dat[x].telp);
            Posisi(6,31);
            printf("Harga       : %s", dat[x].email);

            do{
            Posisi(6,34);
            printf("Pilih Data yang akan diganti");
            Posisi(6,35);
            printf("1. Nama");
            Posisi(6,36);
            printf("2. Nomor Kamar");
            Posisi(6,37);
            printf("3. Telepon");
            Posisi(6,38);
            printf("4. Tanggal");
            Posisi(6,39);
            printf("5. Harga");
            Posisi(6,40);
            printf("6. Selesai / Batal");
            Posisi(6,41);
            printf("Pilihan : "); scanf("%d", &jaw);
            switch(jaw){
                case 1: Posisi(6,43); printf("Nama Baru : "); scanf(" %[^\n]%*c", &stemp);
                    strcpy(ayam, dat[x].nama);
                    strcpy(dat[x].nama, stemp);
                    snprintf(temps, sizeof(temps), "ADMIN mengubah nama penduduk NIK :%d dari %s menjadi %s", dat[x].nik, ayam, dat[x].nama);
                    append(&head, temps);
                    break;

                case 2: Posisi(6,43); printf("Nomor Kamar Baru : "); scanf("%d", &temp);
                    jaw = dat[x].nik;
                    dat[x].nik = temp;
                    snprintf(temps, sizeof(temps), "ADMIN mengubah NIK penduduk NIK :%d dari %d menjadi %d", dat[x].nik, jaw, dat[x].nik);
                    append(&head, temps);
                    break;

                case 3: Posisi(6,43); printf("Nomor Telepon Baru : "); scanf("%d", &temp);
                    jaw = dat[x].telp;
                    dat[x].telp = temp;
                    snprintf(temps, sizeof(temps), "ADMIN mengubah Telepon penduduk NIK :%d dari %d menjadi %d", dat[x].nik, jaw, dat[x].telp);
                    append(&head, temps);
                    break;

                case 4: Posisi(6,43); printf("Tanggal Baru : "); scanf(" %[^\n]%*c", &stemp);
                    strcpy(ayam, dat[x].ttl);
                    strcpy(dat[x].ttl, stemp);
                    snprintf(temps, sizeof(temps), "ADMIN mengubah nama penduduk NIK :%d dari %s menjadi %s", dat[x].nik, ayam, dat[x].ttl);
                    append(&head, temps);
                    break;

                case 5: Posisi(6,43); printf("Harga Baru : "); scanf(" %[^\n]%*c", &stemp);
                    strcpy(ayam, dat[x].ttl);
                    strcpy(dat[x].email, stemp);
                    snprintf(temps, sizeof(temps), "ADMIN mengubah nama penduduk NIK :%d dari %s menjadi %s", dat[x].nik, ayam, dat[x].email);
                    append(&head, temps);
                    break;

                case 6: break;

                default: Posisi(6,43); printf("Pilihan Tidak Tersedia"); break;
            }
            }while(jaw != 6);

    }
    else{
            Posisi(6,34);
            printf("~ Data Tidak Ditemukan ~");
    }
    Posisi(6,45);
    printf("Tekan Enter Untuk Kembali ke Menu"); getch();
}

void riwayat(){
    system("cls");
    printf("\n  ===== Riwayat Perubahan Data Tamu Hotel =====\n\n");
    printlist(head);
    printf("\n\n  Tekan Enter Untuk Kembali ke Menu"); getch();
}

void main(){
    int pil;

    Login();
    do{
    system("cls");
    Kotak2();
    Posisi(23,4);
    printf("==== Data Pengunjung Hotel HuHa ====");
    Posisi(6,9);
    printf("============ Menu Utama ============");
    Posisi(6,11);
    printf("1. Tambah Data Tamu Hotel");
    Posisi(6,12);
    printf("2. Lihat Data Tamu Hotel");
    Posisi(6,13);
    printf("3. Urutkan Data Tamu Hotel");
    Posisi(6,14);
    printf("4. Pencarian Data Tamu Hotel");
    Posisi(6,15);
    printf("5. Hapus Data Tamu Hotel");
    Posisi(6,16);
    printf("6. Ubah Data Tamu Hotel");
    Posisi(6,17);
    printf("7. Lihat Riwayat Perubahan");
    Posisi(6,18);
    printf("8. Exit");
    Posisi(6,19);
    printf("Masukkan Pilihan Anda : "); scanf("%d", &pil);

    switch(pil){
        case 1: tambah(); break;
        case 2: lihat(); break;
        case 3: urut(); break;
        case 4: cari(); break;
        case 5: hapus(); break;
        case 6: edit(); break;
        case 7: riwayat(); break;
        case 8: main(); break;
        default: Posisi(6,21); printf("Pilihan Tidak Tersedia"); getch();

    }
    }while(pil != 8);
}

void Posisi(int x, int y){
    COORD CRD;
    CRD.X=x;
    CRD.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}

void Kotak1(){
    Posisi(26, 6);
    printf("\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf\n");
    Posisi(26, 7);
    printf("\xb3                       \xb3");
    Posisi(26, 8);
    printf("\xb3                       \xb3");
    Posisi(26, 9);
    printf("\xb3                       \xb3");
    Posisi(26, 10);
    printf("\xb3                       \xb3");
    Posisi(26, 11);
    printf("\xb3                       \xb3");
    Posisi(26, 12);
    printf("\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
}

void Login(){
char id[8];
const int max = 7;
char pw[max+1];
char ch;
int posisi = 0;

    system("cls");
    system("COLOR C");
    Kotak1();
    Posisi(31, 8);
    printf(" ID    : ");
    Posisi(28, 10);
    printf(" Password : ");
    Posisi(40, 8);
    scanf("%s", &id);
    Posisi(40, 10);
    while(1){
        ch = getch();
        if(ch == 13){ //untuk enter
            break;
        }else if(ch == 8){ //untuk backspace
            if(posisi > 0){
                posisi--;
                pw[posisi] = '\0';
                printf("\b \b");
            }
        }else if(ch == 32){//untuk spasi
            continue;
        }else{
            if(posisi < max){
                pw[posisi] = ch;
                posisi++;
                printf("*");
            }else{
                break;
            }
        }
    }

    pw[posisi] = NULL;

    if(strlen(pw) == 0){
        Login();
    }else{
        if(strcmp(id, "admin") == 0){
            if(strcmp(pw, "4321") == 0){
                Loading();
                system("cls");
                Kotak1();
                Posisi(33,9);
                system("COLOR 7");
                printf("LOGIN SUKSES");
                Sleep(1300);
            }else{
                Loading();
                system("cls");
                Kotak1();
                Posisi(34,8);
                system("COLOR 7");
                printf("LOGIN GAGAL");
                Posisi(32,10);
                printf("PASSWORD SALAH !");
                Sleep(1300);
                Ulang_Login();
            }
        }else{
            Loading();
            system("cls");
            Kotak1();
            Posisi(33,8);
            system("COLOR 7");
            printf("LOGIN GAGAL");
            Posisi(29,10);
            printf("AKUN TIDAK TERDAFTAR");
            Sleep(1300);
            Ulang_Login();
        }
    }
}

void Loading(){
    system("cls");
    Kotak1();
    Posisi(35, 8);
    system("COLOR 6");
    printf("Loading\n");
    Sleep(500);
    Posisi(32, 10);
    system("COLOR E");
    printf("\xdb ");
    Sleep(500);
    system("COLOR 6");
    printf("\xdb ");
    Sleep(500);
    system("COLOR E");
    printf("\xdb ");
    Sleep(500);
    system("COLOR 6");
    printf("\xdb ");
    Sleep(500);
    system("COLOR E");
    printf("\xdb ");
    Sleep(500);
    system("COLOR 6");
    printf("\xdb ");
    Sleep(500);
    system("COLOR E");
    printf("\xdb ");
    Sleep(500);
    system("COLOR 6");
    printf("\xdb ");
}

void Ulang_Login(){
char id[8];
const int max = 7;
char pw[max+1];
char ch;
int posisi = 0;

    system("cls");
    system("COLOR C");
    Kotak1();
    Posisi(31, 8);
    printf(" ID    : ");
    Posisi(28, 10);
    printf(" Password : ");
    Posisi(40, 8);
    scanf("%s", &id);
    Posisi(40, 10);
    while(1){
        ch = getch();
        if(ch == 13){ //untuk enter
            break;
        }else if(ch == 8){ //untuk backspace
            if(posisi > 0){
                posisi--;
                pw[posisi] = '\0';
                printf("\b \b");
            }
        }else if(ch == 32){//untuk spasi
            continue;
        }else{
            if(posisi < max){
                pw[posisi] = ch;
                posisi++;
                printf("*");
            }else{
                break;
            }
        }
    }

    pw[posisi] = NULL;
    printf("\n");

    if(strlen(pw) == 0){
        Login();
    }else{
        if(strcmp(id, "admin") == 0){
            if(strcmp(pw, "4321") == 0){
                Loading();
                system("cls");
                Kotak1();
                Posisi(33,9);
                system("COLOR 7");
                printf("LOGIN SUKSES");
                Sleep(1300);
            }else{
                Loading();
                system("cls");
                Kotak1();
                Posisi(34,8);
                system("COLOR 7");
                printf("LOGIN GAGAL");
                Posisi(32,10);
                printf("PASSWORD SALAH !");
                Sleep(1300);
                Ulang_Login();
            }
        }else{
            Loading();
            system("cls");
            Kotak1();
            Posisi(33,8);
            system("COLOR 7");
            printf("LOGIN GAGAL");
            Posisi(29,10);
            printf("AKUN TIDAK TERDAFTAR");
            Sleep(1300);
            Ulang_Login();
        }
    }
}

void Kotak2(){
    printf("\n\n");
    printf("    ");
    for(int q=0; q<=71; q++){
        if(q==0){
            printf("\xc9");
        }else if(q==71){
            printf("\xbb");
        }else{
            printf("\xcd");
        }
    }printf("\n");

    for(int w=0; w<=50; w++){
        printf("    ");
        for(int q=0; q<37; q++){
            if(q==0){
                printf("\xba");
            }else if(w<=4 && q==36){
                printf("\xba");
            }else if(w>4 && w<20 && q==36){
                printf(" \xba");
            }else if(w==20 && q==36){
                printf("\xba");
            }else if(w==4 && q==20){
                printf("\xc2\xc4");
            }else if(w==4){
                printf("\xc4\xc4");
            }else if(w>=4 && w<20 && q==20){
                printf("\xb3");
            }else if(w==20 && q==20){
                printf("\xc1\xc4");
            }else if(w==20){
                printf("\xc4\xc4");
            }else if( w>20 && q==35){
                printf("  \xba");
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }

    printf("    ");
    for(int q=0; q<=71; q++){
        if(q==0){
            printf("\xc8");
        }else if(q==71){
            printf("\xbc");
        }else{
            printf("\xcd");
        }
    }
}

void Tampilan_Tetap(){
    Kotak2();
    Posisi(23,4);
    printf("==== Data Pengunjung Hotel HuHa ====");
    Posisi(6,9);
    printf("============ Menu Utama ============");
    Posisi(6,11);
    printf("1. Tambah Data Tamu Hotel");
    Posisi(6,12);
    printf("2. Lihat Data Tamu Hotel");
    Posisi(6,13);
    printf("3. Urutkan Data Tamu Hotel");
    Posisi(6,14);
    printf("4. Pencarian Data Tamu Hotel");
    Posisi(6,15);
    printf("5. Hapus Data Tamu Hotel");
    Posisi(6,16);
    printf("6. Ubah Data Tamu Hotel");
    Posisi(6,17);
    printf("7. Lihat Riwayat Perubahan");
    Posisi(6,18);
    printf("8. Exit");
    Posisi(6,19);
    printf("Masukkan Pilihan Anda : ");
}

void Mencari(){
    Posisi(53,19);
    printf("Mencari Data");
    Posisi(55,20);
    Sleep(500);
    printlist(".");
    Posisi(57,20);
    Sleep(500);
    printlist(".");
    Posisi(59,20);
    Sleep(500);
    printlist(".");
    Posisi(61,20);
    Sleep(500);
    printlist(".");
    Sleep(500);
}
