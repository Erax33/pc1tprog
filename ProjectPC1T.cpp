#include <stdio.h>
#include "options.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>   

struct s_dec* first = NULL;

void add()
{
	char f_name[length];
	char l_name[length];
	char c_date[length];
	char c_phone[length];
	char c_tarif[length];
	char chs;

	printf("\nMeno : ");
	scanf_s("%s", f_name, length);
	while (getchar() != '\n');
	printf("\nPriezvisko : ");
	scanf_s("%s", l_name, length);
	while (getchar() != '\n');
	printf("\nDatum narodenia v tvare rrrr-mm-dd : ");
	scanf_s("%s", c_date, length);
	while (getchar() != '\n');
	printf("\nTelefon : ");
	scanf_s("%s", c_phone, length);
	while (getchar() != '\n');
	printf("Tarif: A: Basic\tB: Advanced\tC: Expert\tD: Data infinite\tE: Studdent");
	chs = tolower(getchar());
	while (getchar() != '\n');
	switch (chs)
	{
	case 'a':
		strcpy_s(c_tarif, "Basic");
		break;
	case 'b':
		strcpy_s(c_tarif, "Advanced");
		break;
	case 'c':
		strcpy_s(c_tarif, "Expert");
		break;
	case 'd':
		strcpy_s(c_tarif, "Data infinite");
		break;
	case 'e':
		strcpy_s(c_tarif, "Student");
		break;
	default:printf("sup");
	}
	add(f_name, l_name, c_date, c_phone, c_tarif, &first);
}

void rem()
{
	char c_date[length];

	printf("\nDatum narodenia v tvare rrrr-mm-dd : ");
	scanf_s("%s", c_date, length);
	while (getchar() != '\n');
	rem(c_date, &first);
}

void edit()
{
	rem();
	add();
}

void show()
{
	struct s_dec* curr_c = first;
	printf("\n\n");
	while (curr_c)
	{
		printf("%s %s %s %s %s \n", curr_c->fname, curr_c->lname, curr_c->date, curr_c->phone, curr_c->tarif);
		curr_c = curr_c->next;
	}
	getchar();
}
int main()
{
	char input;
	do {
		system("cls");
		printf("S: Zobrazit databazu\tA: Pridat zakaznika\tE: Upravit\tR: Odobrat zakaznika\tQ: Ukoncit program");
		input = tolower(getchar());
		while (getchar() != '\n');
		switch (input)
		{
		case 's':
			show();
			break;
		case 'a':
			add();
			break;
		case 'e':
			edit();
			break;
		case 'r':
			rem();
			break;
		}
	} while (input != 'q');
	return 0;
}
