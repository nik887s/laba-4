#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	int array[10][12], i = 0, j = 0, choice = 0, min = 99999, itwas = 1;
	int x;
	printf("enter 1 to enter the array elements yourself\n");  //выбор пользователя
	printf("enter 2 to randomly enter array elements\n");
	while (scanf_s("%d", &x) != 1 || x < 1 || x>2 || getchar() != '\n')
	{
		printf("incorrect enter\n");
		rewind(stdin);
	}
	switch (x)
	{
	case 1:
		for (int i = 0; i < 10; i++)							//ввод пользователем
		{
			for (int j = 0; j < 12; j++)
			{
				printf("enter %d %d number of massive ", i + 1, j + 1);
				while (scanf_s("%4d", &array[i][j]) != 1 || getchar() != '\n')		//проверка на ввод
				{
					printf("error\n");
					rewind(stdin);
				}
			}
		}
		break;
	case 2:		
		srand(time(NULL));
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				array[i][j] = rand() % 3;
			}
		}
		break;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			printf("%4d", array[i][j]);
		}
		printf("\n");
	}
	int flag = 1;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 12; j++) // строка
		{
			if (min > array[i][j]) // поиск минимального в строке
			{
				min = array[i][j];
			}
		}
		for (int l = 0; l < 12; l++)
		{
			if (array[i][l] == min)
			{
				for (int b = 0; b < 10; b++)
				{
					if (min < array[b][l]) //если мин меньше какого-то элемента в столбце, то он не максимальный
					{
						flag = 0;
					}
				}
				if (flag == 1)
				{
					printf("stroka %d stolbec %d :%d\t\n", i + 1, l + 1, min);
					itwas = 0;
				}
			}
			flag = 1;
		}
		flag = 1;
		min = 99999;
	}
	flag = 1; min = 99999;
	printf("\n");
	for (j = 0; j < 12; j++)
	{
		for (i = 1; i < 10; i++)
		{
			if (min > array[i][j])
				min = array[i][j];
		}
		for (int l = 0; l < 10; l++)
		{
			if (array[l][j] == min)
			{
				for (int b = 0; b < 12; b++)
				{
					if (min < array[l][b])
					{
						flag = 0;

					}
				}
				if (flag == 1)
				{
					printf("stolbes %d stroca %d %d\n ", j + 1, l + 1, min);
					itwas = 0;
				}
			}
			flag = 1;
		}
		flag = 1;
		min = 9999999;
	}
	if (itwas == 1)
		printf("not founded");
	return 0;
}
/*1 2 3 1 4 5 6 7 8 9 9 9
  0 0 4 0 0 0 0 0 0 0 0 0
  0 0 4 0 0 0 0 0 0 0 0 0
  0 0 4 0 0 0 0 0 0 0 0 0
  0 0 4 0 0 0 0 0 0 0 0 0
  0 1 2 1 1 1 1 1 1 1 1 1
  0 0 4 0 0 0 0 0 0 0 0 0
  0 0 4 0 0 0 0 0 0 0 0 0
  0 0 4 0 0 0 0 0 0 0 0 0
  0 0 4 0 0 0 0 0 0 0 0 0
*/