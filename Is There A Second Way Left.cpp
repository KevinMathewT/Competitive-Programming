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

struct DSU{
	ll n;
	vector<ll> p, rank;

	DSU(ll _n){
		n = _n;
		p = vector<ll>(n + 1, 0);
		rank = vector<ll>(n + 1, 1);
		for(ll i=1;i<=n;i++) p[i] = i;
	}

	ll find_set(ll x){
		if(x == p[x]) return x;
		return p[x] = find_set(p[x]);
	}

	ll same_set(ll x, ll y){
		return find_set(x) == find_set(y);
	}

	void union_sets(ll x, ll y){
		x = find_set(x);
		y = find_set(y);

		if(x != y){
			if(rank[x] > rank[y]) p[y] = x, rank[x] += rank[y];
			else p[x] = y, rank[y] += rank[x];
		}
	}
};

const ll N = 110, M = 1e9 + 7;
ll n, m, flag, p[N][32];
vector<pair<ll, pair<ll, ll> > > E, MST, nMST;
vector<ll> T[N];

void markParent(ll u, ll pa){
	p[u][0] = pa;
	for(ll v : T[u]) if(v != pa) markParent(v, u);
}

void getSecond(){
	for(auto it : MST){
		T[it.S.F].push_back(it.S.S);
		T[it.S.S].push_back(it.S.F);
	}

	markParent(1, -1);

	
}

void segMST() {
	MST.clear();
	nMST.clear();
	DSU U(n);

	for(auto it : E)
		if(U.same_set(it.S.F, it.S.S)) nMST.push_back(it);
		else U.union_sets(it.S.F, it.S.S), MST.push_back(it);

	for(ll i=2;i<=n;i++)
		if(!U.same_set(i, i - 1)) flag = 1;
}

void solve(ll te){
	flag = 0;
	cin >> n >> m;
	E.clear();
	for(ll i=0;i<m;i++){
		ll u, v, w;
		cin >> u >> v >> w;

		E.push_back({w, {u, v}});
	}

	sort(E.begin(), E.end());
	// cout << E << "\n";

	segMST();

	if(flag == 1) cout << "Case #" << te << " :  No way\n";
	else if(nMST.size() == 0) cout << "Case #" << te << " :  No second way\n";
	else cout << "Case #" << te << " : " << getSecond() << "\n";
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	for(ll i=1;i<=T;i++)
		solve(i);

	return 0;
}