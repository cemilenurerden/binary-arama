#include <stdio.h>

void secimSiralamasi(int dizi[], int boyut) {  // secmeli s�ralama alg fonksiyonu tan�mlad�m dizi ve degiskeni parametre olarak tan�mlad�m
    for (int i = 0; i < boyut - 1; i++) {  // Dizi �zerindeki her bir eleman� s�ralamak i�in bir d�ng� ba�latt�m
        int kucuk_indeks = i; //Minimum de�erin indeksini tutar bu degisken
        for (int j = i + 1; j < boyut; j++) { //Minimum de�eri bulmak i�in bir i� d�ng� ba�latt�m. �� d�ng�, d�� d�ng�n�n bir sonraki eleman�ndan ba�lar.
            if (dizi[j] < dizi[kucuk_indeks]) {  // E�er i� d�ng�n�n mevcut eleman�, minimum elemandan daha k���kse:
                int gecici = dizi[j];  // Ge�ici bir de�i�kene j indeksindeki eleman atan�r.
                dizi[j] = dizi[kucuk_indeks];  //j indeksindeki eleman, minimum eleman�n de�eriyle de�i�tirilir.
                dizi[kucuk_indeks] = gecici;  //  Minimum eleman�n de�eri, ge�ici de�i�kendeki de�erle de�i�tirilir. Bu �ekilde minimum eleman do�ru konuma yerle�tirilir.
            }
        }
    }
}

int ikiliArama(int dizi[], int boyut, int aranan_eleman) {  //fonksiyon tan�mlad�m
    int dusuk = 0;  // arama aral�g�n�n en dusuk indeksi bu degiskenle baslat�lacak
    int yuksek = boyut - 1;  // Arama aral���n�n en y�ksek indeksi bu degiskenle baslat�lacak

    while (dusuk <= yuksek) {   // Arama aral��� ge�erli oldu�u s�rece bir d�ng� ba�lat�l�r.
        int orta = dusuk + (yuksek - dusuk) / 2;

        if (dizi[orta] == aranan_eleman) {  //eger ortadaki eleman aranan elemana esiitse
            return orta;  // Aranan eleman�n indeksini d�nd�r�r
        }
        else if (dizi[orta] < aranan_eleman) // E�er ortadaki eleman hedef de�erden k���kse
            {
                dusuk=orta +1;  //Arama aral���n� sa� tarafa kayd�r�r. Bu �ekilde sa� tarafta arama yap�l�r.
        }
        else {
            yuksek = orta- 1;  //degilse arama aral���n� sol tarafa kayd�r�r sol tarafta arama yap�l�r.
        }
    }

    return -1;  // Aranan eleman dizide bulunamad�
}

int main() {
    int dizi[] = {4, 8, 3, 84, 47, 76, 9, 24, 68};  //dizi elemanlar�n� dizi adl� degiskene atad�m
    int boyut = sizeof(dizi) / sizeof(dizi[0]);  //dizinin bellek boyutu hesaplan�r ve bu de�er, bir eleman�n bellek boyutuna b�l�nerek dizinin eleman say�s� elde edilir.

   secimSiralamasi(dizi, boyut); //secmeli s�ralama algoritmas� kullan�larak dizi adl� dizimiz s�ralan�r. secimSiralamasi fonksiyonu �a�r�l�r ve dizi ile boyutu fonksiyona aktar�l�r.

    int aranan;
    printf("Aranacak eleman� girin: ");
    scanf("%d", &aranan);

    int sonuc = ikiliArama(dizi, boyut, aranan);  //onksiyonu �a�r�l�r ve dizi, boyut ve aranan eleman fonksiyona aktar�l�r.bu da sonuc adl� degiskene atan�r

    if (sonuc == -1) {
        printf("Aranan eleman dizide bulunamad�.\n");
    } else {
        printf("Aranan eleman dizinin %d. indeksinde bulunuyor.\n", sonuc);
    }

    return 0;
}
