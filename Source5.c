#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 256 //����� ������

void input(char path[]) //������� ������� ������ ����� � ���� f
{
	FILE* f = fopen(path, "w"); //��������� ���� �� ������
	if (!f) //��������� �������� �� ����
	{
		printf("Can not open file f for writing.\n"); //���� �� ���������, ����� ������� ���������
		exit(4); //��������� ��������� � ����� 4
	}
	char str[SIZE]; //��������� ������
	gets(str, SIZE); //������ ������
	while (strcmp(str, "EOF") != 0) //������������ ������ � ����, ���� ������������ �� ������ "EOF"
	{
		fputs(str, f); //���������� ������ � ����
		fprintf(f, "%s", "\n"); //������ ������� ������
		gets(str, SIZE); // ��������� ����� ������
	}
	fclose(f);
}


void task(char from[], char to[])
{
	FILE* f = fopen(from, "r"); //��������� ���� f ������ �� ������
	FILE* g = fopen(to, "w"); //��������� g �� ������

	if (!f)
	{ // ���������, ��� ��� ���������, ���� ��� -
		printf("Can not open the file f.\n"); // �� ������� ���������
		exit(1); // � ��������� ���������
	}

	if (!g)
	{ // ���������, ��� ��� ���������, ���� ��� -
		printf("Can not open the file g.\n"); // �� ������� ���������
		exit(2); // � ��������� ���������
	}

	int r = -1; //���������� �� ����� �� ������������ ��������
	while (!feof(f)) // ���� �� ����� �����
	{
		char str[SIZE] = ""; // ��������� ������
		fgets(str, SIZE, f); // ���������� � ��� ������ �� ����� f
		int ind; //������ ������� ��������� '+'
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

void PrintFile(char path[]) // ������� ������ ����� g �� �����
{
	FILE* file = fopen(path, "r"); // ��������� ���� �� ������
	if (!file) // ���� �� ���������
	{
		printf("Can not open file G for reading.\n"); //������� ���������
		exit(3); // ��������� ���������
	}
	while (!feof(file)) { // ���� �� ����� �����
		char str[SIZE] = ""; // ��������� ������ ������
		fgets(str, SIZE, file); // ���������� ������� �� ����� � str
		printf("%s", str); // �������� str
	}
	fclose(file); // ��������� �����
}

main()
{
	printf("LAB WORK #9\nSpesivtsevaPolina\n");
	const char from[] = "C:\\Users\\������\\Desktop\\f.txt";
	const char to[] = "C:\\Users\\������\\Desktop\\g.txt";
	input(from); // ������ � ����
	task(from, to); // ������� �������� ������
	PrintFile(to); // ����� ����� g �� �����
	return 0;
}
