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
 
const ll N = 200010, M = 1e9 + 7;
ll n, in[N], out[N], mx, a, b, c;
vector<ll> T[N];
 
ll dp1(ll u, ll p){
	if(T[u].size() == 1 && u != 1) return in[u] = 1;
	in[u] = 1;
	for(ll v : T[u]) if(v != p) in[u] = max(in[u], 1 + dp1(v, u));
	return in[u];
}
 
ll dp2(ll u, ll p){
	vector<ll> paths(0);
	paths.push_back(out[u] - 1);
 
	for(ll v : T[u]) if(v != p) paths.push_back(in[v]);
	sort(paths.begin(), paths.end());
 
	if(paths.size() >= 3){
		ll curr = paths[paths.size() - 1] + paths[paths.size() - 2] + paths[paths.size() - 3] + 1;
		if(curr > mx){
			mx = curr;
			a = u;
		}
	}
 
	paths.clear();
	for(ll v : T[u]) if(v != p) paths.push_back(in[v]);
	paths.push_back(out[u] - 1);
	sort(paths.begin(), paths.end());
	ll mx1 = paths[paths.size() - 1];
	for(ll v : T[u]) if(v != p){
		if(in[v] == mx1) out[v] = 2 + paths[paths.size() - 2];
		else out[v] = 2 + mx1;
	}
 
	for(ll v : T[u]) if(v != p) dp2(v, u);
}
 
pair<ll, ll> dfs(ll u, ll p){
	if(u != a){
		vector<pair<ll, ll> > far(0);
		for(ll v : T[u]) if(v != p) far.push_back(dfs(v, u));
		if(far.size() == 0) return make_pair(1, u);
		else {
			sort(far.begin(), far.end());
			far[far.size() - 1].F++;
			return far.back();
		}
	}
 
	vector<pair<ll, ll> > far(0);
	for(ll v : T[u]) if(v != p) far.push_back(dfs(v, u));
		sort(far.begin(), far.end());
	for(ll i=far.size() - 1;i>=far.size() - 3;i--)
		cout << far[i].S << " ";
	cout << "\n";
	return make_pair(0, 0);
}
 
pair<ll, ll> dfs2(ll u, ll p){
	if(u != a){
		vector<pair<ll, ll> > far(0);
		for(ll v : T[u]) if(v != p) far.push_back(dfs2(v, u));
		if(far.size() == 0) return make_pair(1, u);
		else {
			sort(far.begin(), far.end());
			far[far.size() - 1].F++;
			return far.back();
		}
	}
 
	vector<pair<ll, ll> > far(0);
	for(ll v : T[u]) if(v != p) far.push_back(dfs2(v, u));
		sort(far.begin(), far.end());
	// cout << far << "\n";
	cout << u << " ";
	for(ll i=far.size() - 1;i>=far.size() - 2;i--)
		cout << far[i].S << " ";
	cout << "\n";
	return make_pair(0, 0);
}
 
void solve(){
	cin >> n;
	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;
 
		T[u].push_back(v);
		T[v].push_back(u);
	}
 
	mx = -1;
 
	dp1(1, -1);
	out[1] = 1;
	dp2(1, -1);
 
	// for(ll i=1;i<=n;i++) cout << in[i] << " ";
	// cout << "\n";
 
	// for(ll i=1;i<=n;i++) cout << out[i] << " ";
	// cout << "\n";
 
	if(mx == -1){
		cout << n - 1 << "\n";
		for(ll i=1;i<=n;i++)
			if(T[i].size() == 2){
				a = i;
				dfs2(i, -1);
				return;
			}
	}
 
	cout << mx - 1 << "\n";
	dfs(a, -1);
}
 
int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.
 
	// ll T;
	// cin >> T;
	// while(T--)
		solve();
 
	return 0;
}