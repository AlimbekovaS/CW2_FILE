#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;
unsigned short int z;
struct DATE
{
	int day;
	int month;
	int year;
};
void main()
{
	setlocale(LC_ALL, "ru");
	while (true)
	{
		cout << "\n����� �������?";
		cin >> z;
		if (z == 1)
		{
			FILE *pf;
			char s[80];

			int t;
			if ((pf = fopen("test", "w")) == NULL)
			{
				printf("Error\n");
				exit(1);
			}
			else
			{
			//������ � ����������
			printf("������� ������ � �����: ");
			fscanf(stdin, "%s %d", s, &t);

			//������ � ����
			fprintf(pf, "# %s. %d", s, t);

			fclose(pf);
			/*if (fclose(pf) == 0)
			{
				printf("good");
			}*/

			if ((pf = fopen("test", "r")) == NULL)

				exit(1);

			char name[80];
			int i = 0;
			//������ � �����
			fscanf(pf, "# %s. %d", name, &i);
			fprintf(stdout, "# %s. %d\n", name, i);
			}
		}
		if (z == 2)
		{
			FILE *file;
			char words[40];


			if ((file = fopen("file", "a+")) == NULL)
			{
				fprintf(stdout, "Error\n");
				exit(1);
			}
			else
			{
				//cout
				//printf
				puts("������� �����. ������� Enter");
				puts("� ������ ������ ��� ���������� ���������");
				cin.get();
				while (gets_s(words) != NULL
					&& words[0] != '\0')
				{
					fprintf(file, "%s", words);
				}
				puts("���������� �����: ");
				//������ ��������� �� ������ �����

				rewind(file);
				while (fscanf(file, "%s", words) == 1)
				{
					puts(words);
				}
				if (fclose(file) != 0)
					fprintf(stderr, "������ ��� �������� �����\n");
			}
		}
		if (z == 3)
		{
			FILE *file;

			//����� �� ������ ����� ������ � �����

			char buffer[10];
			char *input = NULL;
			size_t curLen = 0;

			int t = 0;

			while (fgets(buffer, sizeof(buffer), stdin) != 0)
			{
				size_t bufLen = strlen(buffer);
				char *extra =
					(char*)realloc(input, bufLen + curLen + 1);

				if (extra == NULL)
					break;

				input = extra;
				strcpy(input + curLen, buffer);
				curLen += bufLen;
				t++;
				if (t > 3)
					break;
			}

			printf("%s [%d]", input, (int)strlen(input));

			free(input);
		}
		if (z == 4)
		{
			FILE * file;
			double d = 12.23, newD;
			int i = 101, newI;
			long l = 123023L, newL;
			if ((file = fopen("fReadFile", "wb+")) == NULL)
			{
				printf("Error");
				exit(0);
			}
			else
			{
				fwrite(&d, sizeof(double), 1, file);
				fwrite(&i, sizeof(int), 1, file);
				fwrite(&l, sizeof(long), 1, file);
				//������� �� ������ �����
				rewind(file);
				fread(&newD, sizeof(double), 1, file);
				fread(&newI, sizeof(int), 1, file);
				fread(&newL, sizeof(long), 1, file);
			}
			printf("%lf - %ld - %d\n\n", newD, newL, newI);
			fclose(file);
		}
		if (z == 5)
		{
			//1.	��� ����, ���������� ��������� ����. ������ ���� - ��� �����, ����� � ���. ����� ����� ������ ����.
			srand(time(0));
			FILE * date;
			int ch, mes, god;
			if ((date = fopen("date", "w")) == NULL)
			{
				printf("error");
				exit(1);
			}
			else
			{
				for (int i = 0;i < 5;i++)
				{
					god = 1950 + rand() % 100;
					mes = 1 + rand() % 11;
					ch = 1 + rand() % 30;
					fprintf(date, "%2d.%2d.%4d\n", ch, mes, god);
				}
				fclose(date);

			}
			if ((date = fopen("date", "r")) != NULL)
			{
				DATE dates[5];
				for (int i = 0;i < 5;i++)
				{
					fscanf(date, "%2d.%2d.%4d", &dates[i].day, &dates[i].month, &dates[i].year);
				}
				fclose(date);
				for (int i = 0;i < 5;i++)
				{
					printf("%2d.%2d.%4d\n", dates[i].day, dates[i].month, dates[i].year);
				}
				int min_y = 5000;
				int ind_i = 0;
				for (int i = 0;i < 5;i++)
				{
					if (dates[i].year < min_y)
					{
						min_y = dates[i].year;
						ind_i = i;
					}
				}
				int b = 0;
				for (int i = 0;i < 10;i++)
				{
					if (i != ind_i)
					{
						if (dates[i].year == min_y)
							b = 1;
					}
				}
				if (b == 0)
				{
					printf("����� ����� ����: %2d.%2d.%4d\n", dates[ind_i].day, dates[ind_i].month, dates[ind_i].year);
				}
			}
		}
			if (z == 6)
			{
				//2.	��� ���������� ���� f. �������� � ���� g ���������� ����� f � �������� �������.
				FILE * f;
				FILE * g;
				int p[5];
				if ((f = fopen("f", "w")) == NULL)
				{
					printf("error");
					exit(1);
				}
				else
				{
					for (int i = 0;i < 5;i++)
					{
						printf("������� �����: ");
						fscanf(stdin, "%d", &p[i]);
						//������ � ����
						fprintf(f, "%d",p[i]);
						fclose(f);
					}
					if ((f = fopen("f", "w")) == NULL)
					{
						for (int i = 5;i > 0;i--)
						{
							fscanf(f, "%d", &p);
							fprintf(stdout, "%d\n", p);
							
						}
					}

				}

			}
		
	}

	system("pause");
}