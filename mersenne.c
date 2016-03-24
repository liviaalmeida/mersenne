#include <stdio.h>
#include <math.h>

int prime (long long int n)
{
	long long int num, resto;
	num = 2;
	while (num<=sqrt(n))
	{
		resto = n%num;
		if (resto==0)
		{
			return 0;
		}
		num++;
	}
	return 1;
}

long long int expn (int a, long long int e, long long int n)
{
	long long int p = 1;
	while (e)
	{
		if (e%2==1)
		{
			p = (a*p)%n;
			e = (e-1)/2;
		}
		else
		{
			e = e/2;
		}
		a = (a*a)%n;
	}
	return p;
}

long long int mersenne (long long int p)
{
	long long int q;
	long long int r = 1;
	long double max = powf(2,((float)p/2)-1)/(2*p);
	while (r<=max)
	{
		q = 1 + 2*r*p;
		if (expn(2,p,q)==1)
		{
			return q;
		}
		r++;
	}
	return 0;
}

int main (int argc, char **argv)
{
	long long int p;
	long long int controle;
	controle = atoll(argv[1]);
	for (p=2; p<controle; p++)
	{
		if (prime(p)==1)
		{
			if (mersenne(p)!=0)
			{
				printf("M(%lld) -> smallest prime factor: %lld\n",p,mersenne(p));
			}
			else
			{
				printf("M(%lld) -> prime\n",p);
			}
		}
	}
	return 0;
}
