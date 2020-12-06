#include <stdio.h>
#include "options.h"
#include <stdlib.h>
#include <string.h>
void add(char* fname, char* lname, char* date, char* phone, char* tarif, struct s_dec** pnt) 
{
	struct s_dec* new_c;
	struct s_dec* curr_c;

	new_c = (struct s_dec*)malloc(sizeof(struct s_dec));
	curr_c = (struct s_dec*)malloc(sizeof(struct s_dec));
	strcpy_s(new_c->fname, length, fname);
	strcpy_s(new_c->lname, length, lname);
	strcpy_s(new_c->date, length, date);
	strcpy_s(new_c->phone, length, phone);
	strcpy_s(new_c->tarif, length, tarif);
	new_c->next = NULL;


	if (*pnt == NULL)
	{
		*pnt = new_c;
		return;
	}
	else if (strcmp(new_c->fname, (*pnt)->fname) < 0)
	{
		new_c->next = *pnt;
		*pnt = new_c;
		return;
	}
	new_c = *pnt;
	while (curr_c)
	{
		if (curr_c->next == NULL)
		{
			curr_c->next = new_c;
			return;
		}
		else if (strcmp(new_c->fname, curr_c->next->fname) < 0)
		{
			new_c->next = curr_c->next;
			curr_c->next = new_c;
			return;
		}
		curr_c = curr_c->next;
	}
}
void rem(char* date, struct s_dec** pnt)
{
	struct s_dec* curr_c;
	while (*pnt && strcmp((*pnt)->date, date) == 0)
	{
		struct s_dec* first_fix = (*pnt)->next;
		free(*pnt);
		*pnt = first_fix;
	}

	curr_c = *pnt;
	while (curr_c && curr_c->next)
	{
		if (strcmp(curr_c->next->date, date) == 0)
		{
			struct s_dec* next_fix = curr_c->next->next;
			free(curr_c->next);
			curr_c->next = next_fix;
		}
		curr_c = curr_c->next;
	}
}
