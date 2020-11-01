# Matrix-Multiplication-Sequence

https://www.acmicpc.net/problem/11049

# 구현 방법

이차원 배열에 값을 저장해가며 최종값을 도출해낸다.
```
 i)   이차원 배열 M을 생성한다. 배열 M의 (i,j)에는 i번째 행렬부터 j번째 행렬까지 곱셈을 완료했을 때 최소 곱셈 연산 횟수를 저장한다.
  
 ii)  M[i,j]의 값을 구하는 식은 다음과 같다.
      M[i,j] = min( M[i,k] + M[k+1,j] + d(i-1)*d(k)*d(j) ) 
      * 항상 i < j / i <= k <= j-1 / i번째 행렬이 있을 때 이 행렬의 크기는 d(i-1)*d(i)로 나타난다.
      
 iii) 대각선 방향으로 값을 저장해나가며 최종값은 M[1,N]에 저장이 된다.
 
 ex) 6                              |      0  30  64 132 226 348
     5 2                            |          0  24  72 156 268
     2 3                            |              0  72 198 366
     3 4                            |                  0 168 392
     4 6                            |                      0 336
     6 7                            |                          0
     7 8                            |
    과 같은 입력이 들어올 경우            위와 같은 값이 배열에 저장되게 되고
     
     => 최소값은 348이 되게 된다.
```

# 구현 코드
```c
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
```
