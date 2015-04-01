
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
	long long int Max = 1000, *ms, *K, T, i, z, n = 0, j;
	int q = 3, w = 7;

	if (scanf_s("%lld", &T) != 1)
	{
		//return 0;
	}

	ms = (long long int*)malloc(Max * sizeof(long long int));
	K = (long long int*)malloc(T * sizeof(long long int));

	for (j = 1; j <= T; j++)
	{
		if (scanf_s("%lld", &K[j]) != 1)
		{
			//return 0;
		}
	}

	for (i = 1, z = 1; i < Max; i++, z++)
	{
		if (i == q)
		{
			i++;
			q += 10;
		}

		if (i == w)
		{
			i++;
			w += 10;
		}

		ms[z] = i;
		n++;
	}

	for (z = 1, j = 1; z < n, j <= T; z++, j++)
	{
		if (z = K[j])
		{
			printf("%lld\n", ms[z]);
		}
	}
	_getch();
	return 0;
}
