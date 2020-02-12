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
template<class T> ostream& operator<<(ostream &os, multiset<T> S){
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
template<class L, class R> ostream& operator<<(ostream &os, unordered_map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// LinkedIn - https://www.linkedin.com/in/KevinMathewT/
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew

const ll N = 10, M = 1e9 + 7;
ll m, n, V[N][N], flag;
char A[N][N];

void dfs(ll x, ll y, string s){
	if(x < 0 || x >= m || y < 0 || y >= n || V[x][y] == 1) return;
	V[x][y] = 1;
	if(A[x][y] == '#' && flag == 1){
		flag = 0;
		cout << s << "\n";
		return;
	}
	if(A[x][y] != 'I' && A[x][y] != 'E' && A[x][y] != 'H' && A[x][y] != 'O' && A[x][y] != 'V' && A[x][y] != 'A' && A[x][y] != '@') return;
	dfs(x, y - 1, s + "left ");
	dfs(x, y + 1, s + "right ");
	dfs(x - 1, y, s + "forth ");
}

void solve(){
	cin >> m >> n;
	for(ll i=0;i<m;i++)
		for(ll j=0;j<n;j++)
			cin >> A[i][j], V[i][j] = 0;

	flag = 1;
	ll x, y;
	for(ll i=0;i<m;i++) for(ll j=0;j<n;j++) if(A[i][j] == '@'){ x = i, y = j; break; }
	V[x][y] = 0;

	dfs(x, y, "");
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}