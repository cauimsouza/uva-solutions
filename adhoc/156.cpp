#include <bits/stdc++.h>
using namespace std;

#define REC(i, a, b)	for(int i = int(a); i <= int(b); i++)

char LC(char c){
	if(c >= 'a' && c <= 'z')	return c;
	else	return c - 'A' + 'a';
}

int main(int argc, char const *argv[])
{
	map<string, string> dic; // ordenado e lower-case, palavra original
	set<string> jafoi;
	string entrada;
	int i;
	
	while(true){
		cin >> entrada;
		if(entrada == "#")	break;

		string lower = entrada;
		for (i = 0; lower[i] != '\0'; ++i)
		{
			lower[i] = LC(lower[i]);

		}
		
		sort(lower.begin(), lower.begin() + i);
		
		if(dic.find(lower) != dic.end()){
			dic.erase(lower);
		}
		else if(jafoi.find(lower) == jafoi.end()){
			dic[lower] = entrada;
			jafoi.insert(lower);
		}
	}
	
	set<string> res;
	for(map<string,string>::iterator it = dic.begin(); it != dic.end(); it++){
		res.insert(it->second);
	}
	
	for(set<string>::iterator it = res.begin(); it != res.end(); it++)
		cout << *it << endl;

	return 0;
}

