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

ll n, x, y, magic[1000010];
vector<pair<ll, ll> > v; 
set<ll> s;
unordered_map<ll, ll> c, rev;

void solve(){
	s.clear();
	c.clear();
	rev.clear();
	cin >> n;
	for(ll i=0;i<n;i++){
		ll l, r;
		cin >> l >> r;
		v.push_back({l, r});
		s.insert(l);
		s.insert(r);
		s.insert(r + 1);
	}
	cin >> x >> y;

	ll z = 0;
	for(auto i : s){
		c[i] = z;
		rev[z++] = i;
	}

	fill(magic, magic + 1000010, 0);

	for(ll i=0;i<v.size();i++){
		magic[c[v[i].F]]++;
		magic[c[v[i].S + 1]]--;
	}

	for(ll i=1;i<1000010;i++)
		magic[i] = magic[i] + magic[i-1];

	ll tot = 0;
	for(ll i=0;i<1000010;i++){
		if(magic[i] >= x && magic[i] <= y)
			tot += (rev[i+1] - rev[i]);
	}

	cout << tot << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}