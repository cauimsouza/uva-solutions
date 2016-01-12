#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class SegmentTree{
	vi st, A;
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }
public:
	void build(int p, int L, int R){
		if(L == R){ 
			st[p] = A[L]; return;}
		build(left(p), L, (L+R)/2);
		build(right(p), (L+R)/2 + 1, R);
		st[p] = st[left(p)] + st[right(p)];
	}
	int rsq(int p, int L, int R, int i, int j){
		if(i > R || j < L) return 0;
		if(L >= i && R <= j) return st[p];

		int p1 = rsq(left(p), L, (L+R)/2, i, j);
		int p2 = rsq(right(p), (L+R)/2 + 1, R, i, j);
		return p1 + p2;
	}
	void updateKey(int p, int L, int R, int i, int oldKey, int newKey){
		st[p] += newKey - oldKey;
		int q = (L+R)/2;
		if(L == R) return;
		else if(i > q) updateKey(right(p), q+1, R, i, oldKey, newKey);
		else	updateKey(left(p), L, q, i, oldKey, newKey);
	}
	int rsq(int a, int b){
		return rsq(1, 0, n - 1, a, b); }
	void updateKey(int k, int key){
		updateKey(1, 0, n - 1, k, A[k], key);
		A[k] = key; }
	SegmentTree(const vi& _A){
		n = (int)_A.size(); A = _A;
		st.assign(4 * n, 0);
		build(1, 0, n - 1);
	}	
};

int main()
{
	int pots; // number of potiometers
	int count = 0;
	while(scanf("%d", &pots), pots){
		if(count) printf("\n");

		vi potiometers(pots);
		for (int i = 0; i < pots; ++i)
		{
			scanf("%d", &potiometers[i]);
		}

		SegmentTree st(potiometers);

		printf("Case %d:\n", ++count);
		char c;
		while(scanf(" %c", &c), c != 'E'){
			int a, b;
			scanf("%d %d", &a, &b);
			if(c == 'S')
				st.updateKey(a - 1, b);
			else
				printf("%d\n", st.rsq(a - 1, b - 1));
		}
		scanf("ND");
	}
	return 0;
}