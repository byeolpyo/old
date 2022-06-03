#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char imie[20];
    char nazwisko[20];
    char numer_telefonu[10];
} osoba;

osoba baza_danych[100];
int ilosc_rekordow = 0;

void dodaj_rekord() {
    system("clear");
    osoba dodana_osoba;
    
    printf("Podaj imie dodawanej osoby: ");
    scanf("%s", dodana_osoba.imie);

    printf("Podaj nazwisko dodawanej osoby: ");
    scanf("%s", dodana_osoba.nazwisko);
    
    printf("Podaj numer telefonu dodawanej osoby: ");
    scanf("%s", dodana_osoba.numer_telefonu);
    
    baza_danych[ilosc_rekordow] = dodana_osoba;
    ilosc_rekordow++;

    printf("Dodano rekord. ENTER...\n");
    
    getchar();
    getchar();
}

void wyswietl_rekordy() {
    system("clear");

    if(ilosc_rekordow == 0) {
	printf("Baza jest pusta\n");
	getchar();
	getchar();
	return;
    }
    
    int i;
    for(i = 0; i < ilosc_rekordow; i++) {
	printf("Osoba nr: %d\n", i+1);
	printf("Imie: %s\n", baza_danych[i].imie);
	printf("Nazwisko: %s\n", baza_danych[i].nazwisko);
	printf("Numer telefonu: %s\n", baza_danych[i].numer_telefonu);
	printf("\n");
    }

    printf("Nacisnij ENTER...\n");
    
    getchar();
    getchar();
    
}

void zapisz_do_pliku() {
    system("clear");
    FILE *plik;
    char nazwa_pliku[80];
    printf("Podaj nazwe pliku, do ktorego chcesz zapisac baze danych: ");
    scanf("%s", nazwa_pliku);
    
    if((plik = fopen(nazwa_pliku, "wb")) == NULL) {
	printf("Blad otwarcia pliku");
	return;
    }

    fwrite(baza_danych, sizeof(osoba) * ilosc_rekordow, 1, plik);
    printf("Zapisano baze danych do pliku %s\n", nazwa_pliku);

    fclose(plik);

    printf("Nacisnij ENTER...\n");
    
    getchar();
    getchar();
    
}

void odczytaj_z_pliku() {
    system("clear");
    FILE *plik;
    char nazwa_pliku[80];
    printf("Podaj nazwe pliku, z ktorego chcesz odczytac baze danych: ");
    scanf("%s", nazwa_pliku);
    
    if((plik = fopen(nazwa_pliku, "rb")) == NULL) {
	printf("Blad otwarcia pliku");
	return;
    }
    
    
    ilosc_rekordow = 0;
    while( fread(&baza_danych[ilosc_rekordow], sizeof(osoba), 1, plik) > 0) {
	ilosc_rekordow++;
    }
    
    printf("Odczytano baze danych do pliku %s\n", nazwa_pliku);

    fclose(plik);

    printf("Nacisnij ENTER...\n");

    getchar();
    getchar();
    
    
}




int main() {
    int wybor = 0;
    while(wybor != 5) {

	if(wybor == 1) {
	    dodaj_rekord();
	}
	if(wybor == 2) {
	    wyswietl_rekordy();
	}
	if(wybor == 3) {
	    zapisz_do_pliku();
	}
	if(wybor == 4) {
	    odczytaj_z_pliku();
	}

	system("clear");
	printf("Menu:\n");
	printf("1. Dodawanie rekordu do bazy\n");
	printf("2. Wyswietlanie zawartosci bazy na ekranie\n");
	printf("3. Zapis bazy do pliku\n");
	printf("4. Odczyt bazy z pliku\n");
	printf("5. Wyjscie z programu\n");
	printf("Wybierz opcje: ");


	fflush(stdin);
	scanf("%d", &wybor);
	
    }

    return 0;
    
}
