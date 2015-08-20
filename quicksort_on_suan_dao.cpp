#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[1000010];
inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int partition(int *a,int p,int r)
{
	int x = a[r],i = p - 1;
	for (int j = p; j <= r - 1; j++)
		if (a[j] <= x)
		{
			i++;
			swap(a[i], a[j]);
		}
	swap(a[i + 1], a[r]);
	return i + 1;
}
void quicksort(int *a,int l,int r)
{
	if (l < r)
	{
		int q = partition(a,l,r);
		quicksort(a, l, q - 1);
		quicksort(a, q + 1, r);
	}
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	quicksort(a, 1, n);
	for (int i = 1; i <= n; i++)
		printf("%d ",a[i]);
	return 0;
}
