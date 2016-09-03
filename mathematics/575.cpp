#include <cstdio>
#include <cstring>

int main()
{
	char entrada[100];
	while(scanf("%s", entrada) != EOF)
	{
		if(!strcmp(entrada, "0"))
			break;
		long long ans = 0;
		int len = strlen(entrada);
		int sumcoef = 0;
		for(int i = 0; i < len; i++)
		{
			sumcoef += entrada[i] - '0';
			ans += (entrada[i] - '0') * (((long long) 1) << (len - i));
		}
		ans -= sumcoef;

		printf("%lld\n", ans);
	}
}