#include <stdio.h>

void secimSiralamasi(int dizi[], int boyut) {  // secmeli sýralama alg fonksiyonu tanýmladým dizi ve degiskeni parametre olarak tanýmladým
    for (int i = 0; i < boyut - 1; i++) {  // Dizi üzerindeki her bir elemaný sýralamak için bir döngü baþlattým
        int kucuk_indeks = i; //Minimum deðerin indeksini tutar bu degisken
        for (int j = i + 1; j < boyut; j++) { //Minimum deðeri bulmak için bir iç döngü baþlattým. Ýç döngü, dýþ döngünün bir sonraki elemanýndan baþlar.
            if (dizi[j] < dizi[kucuk_indeks]) {  // Eðer iç döngünün mevcut elemaný, minimum elemandan daha küçükse:
                int gecici = dizi[j];  // Geçici bir deðiþkene j indeksindeki eleman atanýr.
                dizi[j] = dizi[kucuk_indeks];  //j indeksindeki eleman, minimum elemanýn deðeriyle deðiþtirilir.
                dizi[kucuk_indeks] = gecici;  //  Minimum elemanýn deðeri, geçici deðiþkendeki deðerle deðiþtirilir. Bu þekilde minimum eleman doðru konuma yerleþtirilir.
            }
        }
    }
}

int ikiliArama(int dizi[], int boyut, int aranan_eleman) {  //fonksiyon tanýmladým
    int dusuk = 0;  // arama aralýgýnýn en dusuk indeksi bu degiskenle baslatýlacak
    int yuksek = boyut - 1;  // Arama aralýðýnýn en yüksek indeksi bu degiskenle baslatýlacak

    while (dusuk <= yuksek) {   // Arama aralýðý geçerli olduðu sürece bir döngü baþlatýlýr.
        int orta = dusuk + (yuksek - dusuk) / 2;

        if (dizi[orta] == aranan_eleman) {  //eger ortadaki eleman aranan elemana esiitse
            return orta;  // Aranan elemanýn indeksini döndürür
        }
        else if (dizi[orta] < aranan_eleman) // Eðer ortadaki eleman hedef deðerden küçükse
            {
                dusuk=orta +1;  //Arama aralýðýný sað tarafa kaydýrýr. Bu þekilde sað tarafta arama yapýlýr.
        }
        else {
            yuksek = orta- 1;  //degilse arama aralýðýný sol tarafa kaydýrýr sol tarafta arama yapýlýr.
        }
    }

    return -1;  // Aranan eleman dizide bulunamadý
}

int main() {
    int dizi[] = {4, 8, 3, 84, 47, 76, 9, 24, 68};  //dizi elemanlarýný dizi adlý degiskene atadým
    int boyut = sizeof(dizi) / sizeof(dizi[0]);  //dizinin bellek boyutu hesaplanýr ve bu deðer, bir elemanýn bellek boyutuna bölünerek dizinin eleman sayýsý elde edilir.

   secimSiralamasi(dizi, boyut); //secmeli sýralama algoritmasý kullanýlarak dizi adlý dizimiz sýralanýr. secimSiralamasi fonksiyonu çaðrýlýr ve dizi ile boyutu fonksiyona aktarýlýr.

    int aranan;
    printf("Aranacak elemaný girin: ");
    scanf("%d", &aranan);

    int sonuc = ikiliArama(dizi, boyut, aranan);  //onksiyonu çaðrýlýr ve dizi, boyut ve aranan eleman fonksiyona aktarýlýr.bu da sonuc adlý degiskene atanýr

    if (sonuc == -1) {
        printf("Aranan eleman dizide bulunamadý.\n");
    } else {
        printf("Aranan eleman dizinin %d. indeksinde bulunuyor.\n", sonuc);
    }

    return 0;
}
