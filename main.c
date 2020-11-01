#include<stdio.h>
#include<limits.h>
int M[501][501], n, d[501], i, j, k, min, minv, x, y;
int main()
{
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf( "%d %d", &x, &y);
		d[i] = x;
		d[i + 1] = y;
	}
	
    for (i = 1; i <= n; i++)
	{
		M[i][i] = 0;
	}

	for (i = 1; i <= n - 1; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			min = INT_MAX;
			for (k = 0; k < i; k++)
			{
				minv = M[j][j + k] + M[j + k + 1][j + i] + d[j - 1] * d[j + k] * d[j + i];
				if (minv < min)
				{
					M[j][j + i] = minv;
					min = minv;
				}
			}
		}
	}
	printf("%d\n", M[1][n]);
	return 0;
}