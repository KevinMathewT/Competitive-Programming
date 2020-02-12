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

const ll N = 1, M = 1e9 + 7;
ll xf, yf, ax, ay, bx, by, xs, ys, t, s;
ll x[1000], y[1000], vis[1000];
unordered_map<ll, unordered_map<ll, ll> > dp[100];
vector<pair<ll, ll> > G[1000];

ll getW(ll x1, ll y1, ll x2, ll y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

void createGraph(){
	for(ll i=0;i<s;i++)
		for(ll j=i + 1;j<s;j++)
			G[i].push_back({getW(x[i], y[i], x[j], y[j]), j}), G[j].push_back({getW(x[i], y[i], x[j], y[j]), i});
}

ll getClosest(){
	ll mn = getW(x[0], y[0], x[1], y[1]), ind = 1;
	for(ll i=1;i<s;i++)
		if(getW(x[0], y[0], x[i], y[i]) <= mn) ind = i;

	return ind;
}

ll getAns(){
	ll st = 0;
	ll cl = getClosest();
	ll t1 = cl;

	ll v = 0, c = 0, ta = 0;

	for(ll i=cl;i>=1;i--){
		ta += getW(x[c], y[c], x[i], y[i]);
		if(ta > t) return v;
		v++;
		c = i;
	}

	for(ll i=t1 + 1;i<s;i++){
		ta += getW(x[c], y[c], x[i], y[i]);
		if(ta > t) return v;
		v++;
		c = i;
	}
}

void solve(){
	cin >> xf >> yf >> ax >> ay >> bx >> by >> xs >> ys >> t;

	x[0] = xs;
	y[0] = ys;
	x[1] = xf;
	y[1] = yf;

	s = 2;
	while(true){
		x[s] = x[s-1] * ax + bx;
		y[s] = y[s-1] * ay + by;

		if(x[s] >= (LLONG_MAX / ax) || y[s] >= (LLONG_MAX / ay)) break;		
		s++;
	}

	s++;

	cout << getAns() << "\n";
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