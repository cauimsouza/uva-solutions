#include <cstdio>
#include <vector>

int main()
{
	using namespace std;
	vector<int> coef;
	int x;
	while(scanf("%d", &x) != EOF)
	{
		coef.clear();
		coef.push_back(x);
		char c;
		while((c = getchar()) != '\n')
		{
			scanf("%d", &x);
			coef.push_back(x);
		}

		bool first = true;
		do
		{
			scanf("%d%c", &x, &c);
			int soma = coef[0];
			for(int i = 1; i < (int) coef.size(); i++)
			{
				soma *= x;
				soma += coef[i];
			}

			if(!first)
				printf(" ");
			printf("%d", soma);
			first = false;
		}while(c != '\n');
		printf("\n");
	}
}