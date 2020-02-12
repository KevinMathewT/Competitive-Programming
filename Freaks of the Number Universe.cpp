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

ll n, d[2000010], sieve[2000010], root;
vector<ll> tree[2000010];
unordered_map<ll, unordered_map<ll, ll> > m;

ll dfs(ll u, ll p, ll de){
	for(ll v : tree[u]){
		if(v == p) continue;
		
		if(sieve[d[v] - 1] != 1){
			cout << "NO\n";
			exit(0);
		}

		if(d[v] == 1)
			continue;
		if(m[de][d[v] - 1] == 1){
			cout << "NO\n";
			exit(0);
		}
		m[de][d[v] - 1] == 1;
	}

	ll pr = -1;
	for(ll v : tree[u]){
		ll pri = dfs(v, u, de + 1);
		if(pr != -1){
			if(pr != pri){
				cout << "NO\n";
				exit(0);
			}
		}

		pr = pri;
	}

	return pr + 1;
}

void solve(){
	root = n;
	d[n] = 0;
	cin >> n;
	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;
		u--; v--;
		d[u]++;
		d[v]++;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	for(ll i=0;i<n;i++)
		if(sieve[d[i]] == 1 && d[i] > d[root])
			root = i;

	for(ll i=0;i<)

	cout << root << "\n";

	ll prim = dfs(root, -1, 0);
	cout << "YES\n";
	cout << prim << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	fill(sieve, sieve + 2000010, 1);
	sieve[0] = 1;
	sieve[1] = 0;

	for(ll i=2;i*i<2000010;i++)
		if(sieve[i] == 1)
			for(ll j=i*i;j<2000010;j+=i)
				sieve[j] = 0;

	solve();

	return 0;
}