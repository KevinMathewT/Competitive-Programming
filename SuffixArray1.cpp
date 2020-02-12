#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    os << "]";
	return os;
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

#define MAXN 65536
#define MAXLG 17

char A[MAXN];

struct entry
{
	int nr[2];
	int p;
} L[MAXN];

int P[MAXLG][MAXN];
int N,i;
int stp, cnt;

int cmp(struct entry a, struct entry b)
{
	return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.


	gets(A);
	for(N=strlen(A), i = 0; i < N; i++)
		P[0][i] = A[i] - 'a';
	
	for(stp=1, cnt = 1; cnt < N; stp++, cnt *= 2)
	{
		for(i=0; i < N; i++)
		{
			L[i].nr[0] = P[stp- 1][i];
			L[i].nr[1] = i + cnt < N ? P[stp -1][i+ cnt] : -1;
			L[i].p = i;
	
			cout << L[i].nr[0] << " " << L[i].nr[1] << " " << L[i].p << "\n";
		}

		cout << "\\\\\\\\\\\\\\\\\\\\\n";
		sort(L, L+N, cmp);
		for(i=0; i < N; i++)
			P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1] ? P[stp][L[i-1].p] : i;
	}

	for(ll i=0;i<N;i++)
		cout << L[i].p << "\n";
	return 0;
}