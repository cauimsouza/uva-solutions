#include <bits/stdc++.h>
using namespace std;

#define sc (L+R)/2
#define LIM 10000000
typedef vector<int> vi;

#define mid(L,R) (L+R)/2
#define LIM 10000000
typedef vector<int> vi;

class SegmentTree{
	vi st, A, lazy;
	int n;
	int left(int p) { return p << 1;}
	int right(int p) { return (p << 1) + 1;}
	
	void update(int p ,int L, int R, int i, int j, int key){
		if(lazy[p] == 1){
			st[p] = R - L + 1;
			if(L != R){
				lazy[left(p)] = 1;
				lazy[right(p)] = 1;
			}
			lazy[p] = 0;
		}
		else if(lazy[p] == 2){
			st[p] = 0;
			if(L != R){
				lazy[left(p)] = 2;
				lazy[right(p)] = 2;
			}
			lazy[p] = 0;
		}
		else if(lazy[p] == 3){
			st[p] = R - L + 1 - st[p];
			if(L != R){
				if(lazy[left(p)] == 1) lazy[left(p)] = 2;
				else if(lazy[left(p)] == 2) lazy[left(p)] = 1;
				else if(lazy[left(p)] == 3) lazy[left(p)] = 0;
				else lazy[left(p)] = 3;
				if(lazy[right(p)] == 1) lazy[right(p)] = 2;
				else if(lazy[right(p)] == 2) lazy[right(p)] = 1;
				else if(lazy[right(p)] == 3) lazy[right(p)] = 0;
				else lazy[right(p)] = 3;
			}
			lazy[p] = 0;
		}

		if(i > R || j < L) return;
		if(L >= i && R <= j){
			if(key == 1){
				st[p] = R - L + 1;
				if(L != R){
					lazy[left(p)] = 1;
					lazy[right(p)] = 1;
				}
			}
			else if(key == 2){
				st[p] = 0;
				if(L != R){
					lazy[left(p)] = 2;
					lazy[right(p)] = 2;
				}
			}
			else if(key == 3){
				st[p] = R - L + 1 - st[p];
				if(L != R){
					if(lazy[left(p)] == 1) lazy[left(p)] = 2;
					else if(lazy[left(p)] == 2) lazy[left(p)] = 1;
					else if(lazy[left(p)] == 3) lazy[left(p)] = 0;
					else lazy[left(p)] = 3;
					if(lazy[right(p)] == 1) lazy[right(p)] = 2;
					else if(lazy[right(p)] == 2) lazy[right(p)] = 1;
					else if(lazy[right(p)] == 3) lazy[right(p)] = 0;
					else lazy[right(p)] = 3;
				}
			}
			return;
		}
		update(left(p), L, mid(L,R), i, j, key);
		update(right(p), mid(L,R)+1, R, i, j, key);
		st[p] = st[left(p)] + st[right(p)];
	}
	void build(int p, int L, int R){
		if(L == R){
			st[p] = A[L];
			return;
		}
		build(left(p), L, mid(L,R));
		build(right(p), mid(L,R) + 1, R);
		st[p] = st[left(p)] + st[right(p)];
	}
	int rsq(int p, int L, int R, int i, int j){
		if(lazy[p] == 1){
			st[p] = R - L + 1;
			if(L != R){
				lazy[left(p)] = 1;
				lazy[right(p)] = 1;
			}
			lazy[p] = 0;
		}
		else if(lazy[p] == 2){
			st[p] = 0;
			if(L != R){
				lazy[left(p)] = 2;
				lazy[right(p)] = 2;
			}
			lazy[p] = 0;
		}
		else if(lazy[p] == 3){
			st[p] = R - L + 1 - st[p];
			if(L != R){
				if(lazy[left(p)] == 1) lazy[left(p)] = 2;
				else if(lazy[left(p)] == 2) lazy[left(p)] = 1;
				else if(lazy[left(p)] == 3) lazy[left(p)] = 0;
				else lazy[left(p)] = 3;
				if(lazy[right(p)] == 1) lazy[right(p)] = 2;
				else if(lazy[right(p)] == 2) lazy[right(p)] = 1;
				else if(lazy[right(p)] == 3) lazy[right(p)] = 0;
				else lazy[right(p)] = 3;
			}
			lazy[p] = 0;
		}
		if(i > R || j < L) return 0;
		if(L >= i && R <= j)	return st[p];

		int p1 = rsq(left(p), L, mid(L,R), i, j);
		int p2 = rsq(right(p), mid(L,R) + 1, R, i, j);
		return p1 + p2;
	}
public:
	int rsq(int a, int b){
		return rsq(1, 0, n - 1, a, b);
	}
	void update(int a, int b, int key){
		update(1, 0, n - 1, a, b, key);
	}
	SegmentTree(const vi& V){
		n = (int) V.size(); A = V;
		st.assign(4 * n, 0);
		lazy.assign(4 * n, 0);
		build(1, 0, n - 1);
	}	
};

int main(int argc, char const *argv[])
{
	
	int test_cases;
	scanf("%d", &test_cases);
	for (int k = 0; k < test_cases; ++k)
	{
		printf("Case %d:\n", k + 1);

		int m, t;
		vi V;
		V.reserve(LIM);
		scanf("%d", &m);
		char inp[60];
		for (int i = 0; i < m; ++i)
		{
			scanf("%d", &t);
			scanf("%s", inp);
			int len = strlen(inp);
			while(t--){
				for (int i = 0; i < len; ++i)
				{
					if(inp[i] == '1'){
						V.push_back(1);
					}
					else{
						V.push_back(0);
					}
				}
			}
		}
		
		SegmentTree bucks(V);

		int queries, count = 1;
		scanf("%d", &queries);
		char query;
		int a, b;
		for (int i = 0; i < queries; ++i)
		{
			scanf(" %c%d%d", &query, &a, &b);
			if(query == 'F'){
				bucks.update(a,b,1);
			}
			else if(query == 'E'){
				bucks.update(a, b, 2);
			}
			else if(query == 'I'){
				bucks.update(a, b, 3);
			}
			else{
				printf("Q%d: %d\n", count++, bucks.rsq(a, b));
			}
		}
	}

	return 0;
}
