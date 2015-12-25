#include <bits/stdc++.h>
using namespace std;

#define REC(i, a, b)	for(int i = int(a); i <= int(b); i++)
#define sz(v)	int((v).size())

int main(int argc, char const *argv[])
{
	
	int n;
	int counterfeit;
	int even[20], up[20], down[20];
	bool TESTE[20], Dif;
	string first, sec, res;
	cin >> n;
	while(n--){
		REC(i, 0, 15){
			even[i] = up[i] = down[i] = 0;
			TESTE[i] = true;
		}
		Dif = false;

		for (int j = 0; j < 3; ++j)
		{
			cin >> first >> sec >> res;
			if(res == "even"){
				
				for (int i = 0; i < first.length(); ++i)
				{
					even[first[i] - 'A']++;
				}
				for (int i = 0; i < sec.length(); ++i)
				{
					even[sec[i] - 'A']++;
				}
			}
			else if(res == "up"){
				set<int> dif;
				for (int i = 0; i < first.length(); ++i)
				{
					down[first[i] - 'A']++;
					dif.insert(first[i] - 'A');
				}
				for (int i = 0; i < sec.length(); ++i)
				{
					up[sec[i] - 'A']++;
					dif.insert(sec[i] - 'A');
				}
				REC(i,0,11){
					if(TESTE[i] && dif.find(i) == dif.end())
						TESTE[i] = false;
				}
				dif.clear();
				Dif = true;	
			}
			else{
				set<int> dif;
				for (int i = 0; i < first.length(); ++i)
				{
					up[first[i] - 'A']++;
					dif.insert(first[i] - 'A');
				}
				for (int i = 0; i < sec.length(); ++i)
				{
					down[sec[i] - 'A']++;
					dif.insert(sec[i] - 'A');
				}
				REC(i,0,11){
					if(TESTE[i] && dif.find(i) == dif.end())
						TESTE[i] = false;
				}
				dif.clear();
				Dif = true;
			}
		}
		set<int> possiveis;
		for (int i = 0; i < 12; ++i)
		{
			possiveis.insert(i);
		}
		for (int i = 0; i < 12; ++i)
		{
			if(even[i])	possiveis.erase(i);
			if(up[i] && down[i])	possiveis.erase(i);
			if(Dif && !TESTE[i])	possiveis.erase(i);
		}
		
		counterfeit = *(possiveis.begin());
		
		if(up[counterfeit])
			printf("%c is the counterfeit coin and it is light.\n", 'A' + counterfeit);
		else
			printf("%c is the counterfeit coin and it is heavy.\n", 'A' + counterfeit);
	}

	return 0;
}
