#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp_header.h"

int colturi[500], c, nr, x;

void task1 (bmp_infoheader *bitmapInfoHeader, unsigned char *bitmapImage, 
		int padding, int b, int g, int r, FILE *outPtr)
//se executa taskul 1
{
	int i, j, k;
	for (i = 0; i < bitmapInfoHeader->height; i++) {
		for (j = 0; j < bitmapInfoHeader->width * 3; j+=3) {	
			k = i * (bitmapInfoHeader->width * 3 + padding) + j;
			if ((bitmapImage[k] != 255)
			  ||(bitmapImage[k + 1] != 255)
			  ||(bitmapImage[k + 2] != 255)) {
				bitmapImage[k] = b;
				bitmapImage[k + 1] = g;
				bitmapImage[k + 2] = r;	
			}
		}
	} //schimbam culoarea pentru task1
}

void recunoaste(int colt, unsigned char *bitmapImage, 
	bmp_infoheader *bitmapInfoHeader, int padding, FILE *outPtr2)
{	
	int latime;
	latime = bitmapInfoHeader->width * 3 + padding;
	if  (( 255              == bitmapImage[colt - latime + 3])
	&&  ( 255              == bitmapImage[colt - latime + 6])
	&&  ( 255              == bitmapImage[colt - latime + 9])
	&&  ( 255              == bitmapImage[colt - latime * 3 + 3])
	&&  ( 255              == bitmapImage[colt - latime * 3 + 6])
	&&  ( 255              == bitmapImage[colt - latime * 3 + 9]))
{
/////////////////////////////////////////////////////////////verificam daca e 0
	if ((bitmapImage[colt] == bitmapImage[colt + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt + 12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime + 12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2])
	&&  ( 255              == bitmapImage[colt - latime * 2 + 3])
	&&  ( 255              == bitmapImage[colt - latime * 2 + 6])
	&&  ( 255              == bitmapImage[colt - latime * 2 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 3 +12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 12])) {
		fprintf(outPtr2, "0");
		colturi[c++] = colt; //memoram inceputul de cifra
		x = 0;
		return;	
	}
/////////////////////////////////////////////////////////////verificam daca e 1
	if (( 255              == bitmapImage[colt + 3])
	&&  ( 255              == bitmapImage[colt + 6])
	&&  ( 255              == bitmapImage[colt + 9])
	&&  ( 255              != bitmapImage[colt + 12])
	&&  ( 255              == bitmapImage[colt + 15])
	&&  ( 255              == bitmapImage[colt - latime])
	&&  ( 255              == bitmapImage[colt - latime + 3])
	&&  ( 255              == bitmapImage[colt - latime + 6])
	&&  ( 255              == bitmapImage[colt - latime + 9])
	&&  ( 255              != bitmapImage[colt - latime + 12])
	&&  ( 255              == bitmapImage[colt - latime + 15])
	&&  ( 255              == bitmapImage[colt - latime * 2])
	&&  ( 255              == bitmapImage[colt - latime * 2 + 3])
	&&  ( 255              == bitmapImage[colt - latime * 2 + 6])
	&&  ( 255              == bitmapImage[colt - latime * 2 + 9])
	&&  ( 255              != bitmapImage[colt - latime * 2 + 12])
	&&  ( 255              == bitmapImage[colt - latime * 2 + 15])
	&&  ( 255              == bitmapImage[colt - latime * 3])
	&&  ( 255              == bitmapImage[colt - latime * 3 + 3])
	&&  ( 255              == bitmapImage[colt - latime * 3 + 6])
	&&  ( 255              == bitmapImage[colt - latime * 3 + 9])
	&&  ( 255              != bitmapImage[colt - latime * 3 +12])
	&&  ( 255              == bitmapImage[colt - latime * 3 +15])
	&&  ( 255              == bitmapImage[colt - latime * 4])
	&&  ( 255              == bitmapImage[colt - latime * 4 + 3])
	&&  ( 255              == bitmapImage[colt - latime * 4 + 6])
	&&  ( 255              == bitmapImage[colt - latime * 4 + 9])
	&&  ( 255              != bitmapImage[colt - latime * 4 + 12])
	&&  ( 255              == bitmapImage[colt - latime * 4 + 15])) {
		fprintf(outPtr2, "1");
		colturi[c++] = colt;
		x = 1;
		return;	
	}
/////////////////////////////////////////////////////////////verificam daca e 2
	if ((bitmapImage[colt] == bitmapImage[colt + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt + 12])
	&&  ( 255              == bitmapImage[colt - latime])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime + 12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 3])
	&&  ( 255              == bitmapImage[colt - latime * 3 +12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 12])) {
		fprintf(outPtr2, "2");
		colturi[c++] = colt;
		x = 2;
		return;	
	}
/////////////////////////////////////////////////////////////verificam daca e 3
	if ((bitmapImage[colt] == bitmapImage[colt + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt + 12])
	&&  ( 255              == bitmapImage[colt - latime])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime + 12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 12])
	&&  ( 255              == bitmapImage[colt - latime * 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 3 +12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 12])) {
		fprintf(outPtr2, "3");
		colturi[c++] = colt;
		x = 3;
		return;	
	}
/////////////////////////////////////////////////////////////verificam daca e 4
	if (( 255              == bitmapImage[colt + 3])
	&&  ( 255              == bitmapImage[colt + 6])
	&&  ( 255              == bitmapImage[colt + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt + 12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime + 12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 12])
	&&  ( 255              == bitmapImage[colt - latime * 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 3 +12])
	&&  ( 255              == bitmapImage[colt - latime * 4])
	&&  ( 255              == bitmapImage[colt - latime * 4 + 3])
	&&  ( 255              == bitmapImage[colt - latime * 4 + 6])
	&&  ( 255              == bitmapImage[colt - latime * 4 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 12])) {
		fprintf(outPtr2, "4");
		colturi[c++] = colt;
		x = 4;
		return;	
	}
/////////////////////////////////////////////////////////////verificam daca e 5
	if ((bitmapImage[colt] == bitmapImage[colt + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt + 12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime])
	&&  ( 255              == bitmapImage[colt - latime + 12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 12])
	&&  ( 255              == bitmapImage[colt - latime * 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 3 +12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 12])) {
		fprintf(outPtr2, "5");
		colturi[c++] = colt;
		x = 5;
		return;	
	}
/////////////////////////////////////////////////////////////verificam daca e 6
	if ((bitmapImage[colt] == bitmapImage[colt + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt + 12])
	&&  ( 255              == bitmapImage[colt + 15])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime])
	&&  ( 255              == bitmapImage[colt - latime + 12])
	&&  ( 255              == bitmapImage[colt - latime + 15])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 12])
	&&  ( 255              == bitmapImage[colt - latime * 2 + 15])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 3 + 12])
	&&  ( 255              == bitmapImage[colt - latime * 3 + 15])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 12])
	&&  ( 255              == bitmapImage[colt - latime * 4 + 15])) {
		fprintf(outPtr2, "6");
		colturi[c++] = colt;
		x = 6;
		return;	
	}
/////////////////////////////////////////////////////////////verificam daca e 7
	if ((bitmapImage[colt] == bitmapImage[colt + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt + 12])
	&&  ( 255              == bitmapImage[colt - latime])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime + 12])
	&&  ( 255              == bitmapImage[colt - latime * 2])
	&&  ( 255              == bitmapImage[colt - latime * 2 + 3])
	&&  ( 255              == bitmapImage[colt - latime * 2 + 6])
	&&  ( 255              == bitmapImage[colt - latime * 2 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 12])
	&&  ( 255              == bitmapImage[colt - latime * 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 3 +12])
	&&  ( 255              == bitmapImage[colt - latime * 4])
	&&  ( 255              == bitmapImage[colt - latime * 4 + 3])
	&&  ( 255              == bitmapImage[colt - latime * 4 + 6])
	&&  ( 255              == bitmapImage[colt - latime * 4 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 12])) {
		fprintf(outPtr2, "7");
		colturi[c++] = colt;
		x = 7;
		return;	
	}
/////////////////////////////////////////////////////////////verificam daca e 8
	if ((bitmapImage[colt] == bitmapImage[colt + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt + 12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime + 12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 3 +12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 12])) {
		fprintf(outPtr2, "8");
		colturi[c++] = colt;
		x = 8;
		return;	
	}
/////////////////////////////////////////////////////////////verificam daca e 9
	if ((bitmapImage[colt] == bitmapImage[colt + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt + 12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime + 12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 2 + 12])
	&&  ( 255              == bitmapImage[colt - latime * 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 3 +12])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 3])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 6])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 9])
	&&  (bitmapImage[colt] == bitmapImage[colt - latime * 4 + 12])) {
		fprintf(outPtr2, "9");
		colturi[c++] = colt;
		x = 9;
		return;	
	}
}
}

void task2 (bmp_infoheader *bitmapInfoHeader, unsigned char *bitmapImage, 
		int padding, char *task2name, int b)
{	
	int i, j, colt, latime;
	FILE *outPtr2;
	outPtr2 = fopen (task2name, "w");
	latime = bitmapInfoHeader->width * 3 + padding;
	for (j = 0; j < bitmapInfoHeader->width * 3; j+=3) {
		for (i = bitmapInfoHeader->height - 1; i >= 0; i--) {	
			colt = i * latime + j;
			if (bitmapImage[i * latime + j] != 255) {
	//se verifica daca pixelul nu are sus si in stanga alti pixeli vecini
				if (((i == bitmapInfoHeader->height - 1) 
					&& (j == 0))
				|| ((j == 0) 
					&& (bitmapImage[colt + latime] == 255)
					&& (i != bitmapInfoHeader->height - 1))
				|| ((i == bitmapInfoHeader->height - 1)
					&& (bitmapImage[colt - 1] == 255)
					&& (j != 0))
				|| ((bitmapImage[colt - 3] == 255)
					&& (bitmapImage[colt + latime] == 255) 
					&& (j != 0)
					&& (i != bitmapInfoHeader->height- 1)))
				{	
					//printf("%d %d\n", i, j);
					recunoaste(colt, bitmapImage, 
					bitmapInfoHeader, padding, outPtr2);
				}
			} else {
	//se verifica daca pixelul poate fi colt stanga-sus pentru cifra 1
				if ((bitmapImage[colt] == 255)
				&& (j < bitmapInfoHeader->width * 3 - 4)
				&& (bitmapImage[colt + 3] == 255)
				&& (bitmapImage[colt + 6] == 255)
				&& (bitmapImage[colt + 9] == 255)
				&& (bitmapImage[colt + 12] == b)) {
					recunoaste(colt, bitmapImage,
					bitmapInfoHeader, padding, outPtr2);
				}
			}
		}
	}
	fclose (outPtr2);
}

void scriere (unsigned char *bitmapImage, 
		bmp_infoheader *bitmapInfoHeader, int padding, FILE *outPtr)
//se scrie in bmp-ul de output
{
	int i;
	for (i = 0; i < bitmapInfoHeader->biSizeImage + 
		padding * bitmapInfoHeader->height; i++)
	{
		fwrite (&bitmapImage[i], sizeof(unsigned char), 1, outPtr);	
	}	//scriem matricea de pixeli in fisierul de output
}

void mutare (int pos1, int pos2, unsigned char *bitmapImage, int latime)
//se suprascrie cifra care incepe la pos2 peste cea care incepe la pos1
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 15; j++)
		{
			bitmapImage[pos1 - i * latime + j] = 
				bitmapImage[pos2 - i * latime + j];
		}	
	}
}

void stergere (int pos1, unsigned char *bitmapImage, int latime)
//se sterge cifra care incepe la pos1
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 15; j++)
		{
			bitmapImage[pos1 - i * latime + j] = 255;
		}	
	}
}

void task3 (bmp_infoheader *bitmapInfoHeader, unsigned char *bitmapImage, 
		int padding, FILE *outPtr3, int *desters)
{
	int d;
	FILE *dumpfile;
	dumpfile = fopen ("dump.txt", "w");
	//se creeaza pentru a citi outputul functiei "recunoaste"
	int i, j, k, latime, gasit;
	latime = bitmapInfoHeader->width * 3 + padding;
	d = c;
	i=0;
	while (i < d)
	{
		recunoaste(colturi[i], bitmapImage, bitmapInfoHeader, 
				padding, dumpfile);
		//se verifica ce cifra este memorata la pozitia colturi[i]
		gasit = 0;
		for (j = 0; j < nr; j++){
			if (desters[j] == x) 
			{
				gasit = 1;			
			}
		}
		//se verifica daca cifra trebuie stearsa
		if (gasit == 1)
		{	
			for (k = i; k < d - 1; k++)
			{
				mutare(colturi[k], colturi[k+1], 
					bitmapImage, latime);
			}
	//se muta cu o pozitie la stanga toate cifrele de dupa cea de sters
			stergere (colturi[d-1], bitmapImage, latime);
			//se sterge ultima cifra curenta
			d--;
		} else {
			i++;		
		}
	}
	scriere (bitmapImage, bitmapInfoHeader, padding, outPtr3);
	//se scrie BMP-ul final pt task3
	fclose (dumpfile);
}

void citire ()
//se citeste inputul si se creeaza outputul
{
	char filename[50], task1name[50], task2name[50], task3name[50], 
		location[50];
	unsigned char buffer[128];
	int r, g, b, i=0, desters[50];
	
	FILE *input;
	input = fopen ("input.txt", "rb"); //deschid input bmp

	fscanf (input, "%s", filename);
	fscanf (input, "%d %d %d", &b, &g, &r);
		//citesc datele pentru task 1
	strcpy (task1name, filename);
	task1name[strlen (task1name) - 4] = '\0';
	strcat (task1name, "_task1.bmp");
		//creez fisierul de output pt task 1
	strcpy (task2name, filename);
	task2name[strlen (task2name) - 4] = '\0';
	strcat (task2name, "_task2.txt");
		//creez fisierul de output pt task 2
	strcpy(task3name, filename);
	task3name[strlen (task3name) - 4] = '\0';
	strcat (task3name, "_task3.bmp");
		//creez fisierul de output pt task 3
	
	while(fscanf(input, "%d", &desters[i]) == 1 && buffer[i] != EOF)
        {
		++i;
	} //citesc datele pentru task 3
	nr=i;

	int padding=0;
	unsigned char *bitmapImage;
	FILE *inPtr; //inputfile pointer
	FILE *outPtr; //outputfile pointer
	FILE *outPtr3; //output task3
   	bmp_fileheader bitmapFileHeader; //bitmap file header
	bmp_infoheader bitmapInfoHeader; //bitmap info header

	for (i = 0; i < 50; i++)
	{
		location[i]=0;
	}
	strcat (location, "input/captcha_files/");
	strcat (location, filename);
		//adaug calea relativa pentru input

	inPtr = fopen (location, "rb"); //deschid input bmp
	outPtr = fopen (task1name, "w"); //creez si deschid output bmp task 1
	outPtr3 = fopen (task3name, "w"); //creez si deschid output bmp task 3

	fread (&bitmapFileHeader, sizeof(bmp_fileheader), 1, inPtr);
	//citim fileheader
	fwrite (&bitmapFileHeader, sizeof(bmp_fileheader), 1, outPtr); 
	//scriem fileheader in output
	fwrite (&bitmapFileHeader, sizeof(bmp_fileheader), 1, outPtr3);
	
	fread (&bitmapInfoHeader, sizeof(bmp_infoheader), 1, inPtr);
	//citim infoheader
	fwrite (&bitmapInfoHeader, sizeof(bmp_infoheader), 1, outPtr);
	//scriem infoheader in output
	fwrite (&bitmapInfoHeader, sizeof(bmp_infoheader), 1, outPtr3);
	
	fseek (inPtr, bitmapFileHeader.imageDataOffset, SEEK_SET); 
	//sarim in locul unde incepe matricea de pixeli

	if (bitmapInfoHeader.width % 4 != 0)
	{
		padding = 4 - bitmapInfoHeader.width * 3 % 4;
	} //aflam paddingul

	bitmapImage = (unsigned char*) malloc 
	(bitmapInfoHeader.biSizeImage + padding * bitmapInfoHeader.height);
    	if (!bitmapImage)
    	{
       		free (bitmapImage);
        	fclose (inPtr);
		fclose (outPtr);
		fclose (outPtr3);
        	return;
    	} //alocam memorie pentru matricea de pixeli
	
	fread (bitmapImage, bitmapInfoHeader.biSizeImage + padding *
		bitmapInfoHeader.height, 1, inPtr);
	//citim matricea de pixeli cu tot cu padding	

	task1 (&bitmapInfoHeader, bitmapImage, padding, b, g, r, outPtr);
	scriere (bitmapImage, &bitmapInfoHeader, padding, outPtr);
	//s-a executat task1

	task2 (&bitmapInfoHeader, bitmapImage, padding, task2name, b);
	//s-a executat task2

	free (bitmapImage);
	//recitim matricea de pixeli pt task3
	fseek (inPtr, bitmapFileHeader.imageDataOffset, SEEK_SET);
	bitmapImage = (unsigned char*) malloc
	(bitmapInfoHeader.biSizeImage + padding * bitmapInfoHeader.height);
    	if (!bitmapImage)
    	{
       		free (bitmapImage);
        	fclose (inPtr);
		fclose (outPtr);
		fclose (outPtr3);
        	return;
    	}
	fread (bitmapImage, bitmapInfoHeader.biSizeImage + padding *
		bitmapInfoHeader.height, 1, inPtr);	

	task3 (&bitmapInfoHeader, bitmapImage, padding, outPtr3, desters);	

	fclose (inPtr);
	fclose (outPtr);
	fclose (outPtr3);
	free (bitmapImage);
}

int main ()
{	
	citire ();	
	return 0;
}
