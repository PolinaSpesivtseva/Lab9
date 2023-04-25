#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 256 //длина строки

void input(char path[]) //создаем фукнцию записи строк в файл f
{
	FILE* f = fopen(path, "w"); //открываем файл на запись
	if (!f) //провер€ем открылс€ ли файл
	{
		printf("Can not open file f for writing.\n"); //если не открылось, тогда выводим сообщение
		exit(4); //завершаем программу с кодом 4
	}
	char str[SIZE]; //объ€вл€ем строку
	gets(str, SIZE); //вводим строку
	while (strcmp(str, "EOF") != 0) //продолжаетс€ запись в файл, пока пользователь не введет "EOF"
	{
		fputs(str, f); //записываем строку в файл
		fprintf(f, "%s", "\n"); //делаем перенос строки
		gets(str, SIZE); // считываем новую строку
	}
	fclose(f);
}


void task(char from[], char to[])
{
	FILE* f = fopen(from, "r"); //открываем файл f только на чтение
	FILE* g = fopen(to, "w"); //открываем g на запись

	if (!f)
	{ // провер€ем, что все открылось, если нет -
		printf("Can not open the file f.\n"); // то выводим сообщение
		exit(1); // и завершаем программу
	}

	if (!g)
	{ // провер€ем, что все открылось, если нет -
		printf("Can not open the file g.\n"); // то выводим сообщение
		exit(2); // и завершаем программу
	}

	int r = -1; //рассто€ние от плюса до провер€емого элемента
	while (!feof(f)) // пока не конец файла
	{
		char str[SIZE] = ""; // объ€вл€ем строку
		fgets(str, SIZE, f); // записываем в нее строку из файла f
		int ind; //индекс первого вхождени€ '+'
		ind = -1;

		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == '+')
			{
				ind = i;
				break;
			}
		}

		if (ind != -1)
		{
			for (int i = 0; i < ind; i++)
			{
				if (isdigit(str[i]) != 0)
				{
					str[i] = '?';
				}

			}
		}

		fprintf(g, "%s", str);
	}
	fclose(f);
	fclose(g);
}

void PrintFile(char path[]) // функци€ вывода файла g на экран
{
	FILE* file = fopen(path, "r"); // открываем файл на чтение
	if (!file) // если не открылось
	{
		printf("Can not open file G for reading.\n"); //выводим сообщение
		exit(3); // завершаем программу
	}
	while (!feof(file)) { // пока не конец файла
		char str[SIZE] = ""; // объ€вл€ем пустую строку
		fgets(str, SIZE, file); // записываем строчку из файла в str
		printf("%s", str); // печатаем str
	}
	fclose(file); // закрываем поток
}

main()
{
	printf("LAB WORK #9\nSpesivtsevaPolina\n");
	const char from[] = "C:\\Users\\јзали€\\Desktop\\f.txt";
	const char to[] = "C:\\Users\\јзали€\\Desktop\\g.txt";
	input(from); // запись в файл
	task(from, to); // решение основной задачи
	PrintFile(to); // вывод файла g на экран
	return 0;
}
