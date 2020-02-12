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

const ll N = 1010, M = 1e9 + 7;
ll n, x[N], y[N];
vector<pair<pair<ll, ll>, pair<ll, ll> > > V;

ll dikkat(ll a, ll b){
	if(V[a].F.S > V[b].F.S || V[a].S.F > V[b].S.F) return 1;
	return 0;
}

void solve(){
	cin >> n;
	V.clear();
	for(ll i=0;i<n;i++){
		cin >> x[i] >> y[i];
		V.push_back({{x[i] + y[i], x[i]}, {y[i], i + 1}});
	}
	sort(V.begin(), V.end());

	for(ll i=1;i<n;i++){
		if(dikkat(i - 1, i)){
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";

	ll cx = 0, cy = 0;
	string s = "";
	for(ll i=0;i<n;i++){
		for(ll j=0;j<V[i].F.S - cx;j++) s.push_back('R');
		for(ll j=0;j<V[i].S.F - cy;j++) s.push_back('U');
		cx = V[i].F.S, cy = V[i].S.F;
	}

	cout << s << "\n";
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