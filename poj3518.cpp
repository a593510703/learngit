#include <stdio.h>
#include <string.h>
bool isp[10000010];
int prime[10010],size,n,ans,Min = 1299709,k;
int main()
{
	memset(isp,1,sizeof(isp));
	for (int i = 2; i <= 100000; i++)
	{
		if (isp[i])
		{
			prime[++size] = i;
			for (int k = 2; k <= 1299709/i; k++)
				isp[k * i] = false;
		}
	}
	k = 0;
	int kk;
	while(scanf("%d",&n),n)
	{
		if(isp[n])
		{
			printf("0\n");
			continue;
		}
		for (k = 1;; k++)
		{
			if(isp[n - k])
				break;
		}
		for (kk = 1;; kk++)
		{
			if(isp[n + kk])
				break;
		}
		printf("%d\n",kk + k);
	}
	return 0;
}
