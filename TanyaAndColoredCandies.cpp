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

const ll N = 60, M = 1e9 + 7;
ll n, s, k, r[N], c[N];
vector<pair<ll, pair<ll, ll> > > V;
vector<pair<ll, ll> > A[N];

void DP(ll p){
	if(p != n - 1) DP(p + 1);

	A[p].clear();
	A[p].push_back({V.F, 0});

	for(ll i=p + 1, i<n;i++)
		if(V[i].S.F != V[p].S.F){
			for(auto it : A[i])
				
		}
}

void solve(){
	cin >> n >> s >> k;
	for(ll i=0;i<n;i++) cin >> r[i];
	for(ll i=0;i<n;i++){
		A[i].clear();
		char ch; cin >> ch;
		if(ch == 'R') c[i] = 0;
		if(ch == 'G') c[i] = 1;
		if(ch == 'B') c[i] = 2;
	}

	for(ll i=0;i<n;i++) V.push_back({ r[i], {c[i], i + 1} });
	sort(V.begin(), V.end());
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}