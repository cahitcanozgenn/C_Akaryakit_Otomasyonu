#include <stdio.h>
#include <conio.h>
#include <windows.h>
//Cahit Can ÷ZGEN | Software Developer
void clrscr() { system("CLS"); }
void gotoxy(short x, short y)
{

	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


FILE* yakitdos, * GecDos;
struct KayTipi 
{
	int TcNo;
	char adi[15];
	char syd[15];
	char yakittur[15];
	char yakitmiktari[15];
	int tutar;
} 
akaryakit;
void dosyaacyaz() { yakitdos = fopen("istasyon.dat", "a"); }
void dosyaacoku() { yakitdos = fopen("istasyon.dat", "r"); }
void geciciac() { GecDos = fopen("gecici.dat", "w"); }
void dosyayayaz() { fprintf(yakitdos, "\n%d %s %s %s %s %d", akaryakit.TcNo, akaryakit.adi, akaryakit.syd, akaryakit.yakittur, akaryakit.yakitmiktari, akaryakit.tutar); }
void dosyadanoku() { fscanf(yakitdos, "%d %s %s %s %s %d", &akaryakit.TcNo, &akaryakit.adi, &akaryakit.syd, &akaryakit.yakittur, &akaryakit.yakitmiktari, &akaryakit.tutar); }
void geciciyaz() { fprintf(GecDos, "\n%d %s %s %s %s %d", akaryakit.TcNo, akaryakit.adi, akaryakit.syd, akaryakit.yakittur, akaryakit.yakitmiktari, akaryakit.tutar); }
void PBaslik()
{	clrscr();
	gotoxy(1, 1); printf("Cahit Can OZGEN");
	gotoxy(18, 1); printf("Akaryakit Otomasyonu");
}
void Pmenu()
{
	PBaslik();
	gotoxy(11, 5); printf("---MENU---");
	gotoxy(11, 6); printf("1. Kayit Yaz");
	gotoxy(11, 7); printf("2. Kayit Ara");
	gotoxy(11, 8); printf("3. Kayit Duzelt");
	gotoxy(11, 9); printf("4. Kayit Listele");
	gotoxy(11, 10); printf("0. CIKIS");
	gotoxy(11, 14); printf("Bir Secenek Giriniz: ");
}
void BilEkr()
{
	PBaslik();
	gotoxy(5, 4); printf("---Yakit Bilgileri---");
	gotoxy(5, 5); printf("Tc...........:");
	gotoxy(5, 6); printf("Ad...........:");
	gotoxy(5, 7); printf("Soyad........:");
	gotoxy(5, 8); printf("Yakit Turu...:");
	gotoxy(5, 9); printf("Yakit Miktari:");
	gotoxy(5, 10); printf("Tutari.......:");
}
void BilGos()
{
	gotoxy(22, 5); printf("%d", akaryakit.TcNo);
	gotoxy(22, 6); printf("%s", akaryakit.adi);
	gotoxy(22, 7); printf("%s", akaryakit.syd);
	gotoxy(22, 8); printf("%s", akaryakit.yakittur);
	gotoxy(22, 9); printf("%s", akaryakit.yakitmiktari);
	gotoxy(22, 10); printf("%d", akaryakit.tutar);
}
void BilGir()
{
	BilEkr();
	gotoxy(11, 20); printf("Lutfen Bilgileri Giriniz...");
	gotoxy(20, 5); scanf("%d", &akaryakit.TcNo);
	gotoxy(20, 6); scanf("%s", &akaryakit.adi);
	gotoxy(20, 7); scanf("%s", &akaryakit.syd);
	gotoxy(20, 8); scanf("%s", &akaryakit.yakittur);
	gotoxy(20, 9); scanf("%s", &akaryakit.yakitmiktari);
	gotoxy(20, 10); scanf("%d", &akaryakit.tutar);
}
int main()
{
	int Anmr, sec, bul = 0;
Bsl:
	clrscr();
Menu:
	PBaslik();
	Pmenu();
Miste:
	gotoxy(33, 14); scanf("%d", &sec);
	if (sec == 0) goto Son;
	if (sec > 4) { gotoxy(11, 20); printf("Hatali Secim Yapildi, Tekrar Giriniz."); goto Miste; }
	if (sec == 1) goto DkYaz;
	if (sec == 2) goto DkOku;
	if (sec == 3) goto DkDuz;
	if (sec == 4) goto DkLst;
	goto Miste;
DkYaz:
	BilGir();
	gotoxy(44, 4); printf("---Girilenler---");
	BilGos();
	dosyaacyaz(); dosyayayaz(); fclose(yakitdos);
	gotoxy(11, 21); printf("Kayit YAZILDI.");
	gotoxy(11, 22); printf("Menu Åicin ENTER Tuslayiniz: "); getch();
DKYcik:
	goto Menu;
DkOku:
	PBaslik();
	gotoxy(11, 11); printf("Aranan Kisinin TC Numarasini Giriniz: ");
	scanf("%d", &Anmr);
	if (Anmr == 0) goto DKOcik;
	dosyaacoku();
	bul = 0;
	while (!feof(yakitdos))
	{
		dosyadanoku();
		if (Anmr == akaryakit.TcNo)
		{
			bul = 1;
			BilEkr(); gotoxy(5, 4); printf("---Okunan Bilgiler---");
			BilGos();
		}
	}
	fclose(yakitdos);
	if (bul == 0) { gotoxy(11, 20); printf("BULUNAMADI..."); }
	gotoxy(11, 22); printf("Menu icin ENTER Tuslayiniz:"); getch();
DKOcik:
	goto Menu;
DkDuz:
	PBaslik();
	gotoxy(11, 11); printf("DUZELTiLECEK Kisinin T.C NUMARASINI Giriniz: ");
	scanf("%d", &Anmr);
	if (Anmr == 0) goto DKDcik;
	dosyaacoku(); geciciac();
	bul = 0;
	while (!feof(yakitdos))
	{
		dosyadanoku();
		if (Anmr == akaryakit.TcNo)
		{
			bul = 1;
			BilEkr(); gotoxy(5, 4); printf("---Okunan Bilgiler---");
			BilGos();
			gotoxy(55, 4); printf("---Yenileri Giriniz---");
			BilGir();
			gotoxy(22, 19); printf("DUZELTiLDi.");
		}
		geciciyaz();
	}
	fclose(yakitdos);	 fclose(GecDos);
	remove("istasyon.dat");  rename("gecici.dat", "istasyon.dat");
	if (bul == 0) { gotoxy(11, 20); printf("BULUNAMADI..."); }
	gotoxy(11, 22); printf("MENU ›C›N ENTER TUSLAY›N›Z"); getch();
DKDcik:
	goto Menu;
DkLst:
	PBaslik();
	dosyaacoku();
	while (!feof(yakitdos))
	{
		dosyadanoku();
		BilEkr();
		gotoxy(5, 4); printf("OKUNAN B›LG›LER");
		BilGos();
		gotoxy(11, 20); printf("SONRAK› KAY›T ›C›N EMTER TUSLAY›N›Z"); getch();
	}
	fclose(yakitdos);
	gotoxy(11, 22); printf("MENU ›C›N ENTER TUSLAY›N›Z"); getch();
DKLcik:
	goto Menu;
Son:
	gotoxy(21, 21); printf("B›TT›");
	return 0;
}
