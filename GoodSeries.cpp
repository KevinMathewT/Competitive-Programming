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

const ll N = 100010, M = 1e9 + 7;
ll n, a[N];

ll check(ll x, ll y){
	ll ret = 1;
	vector<ll> b, c;
	b.push_back(a[x]);
	b.push_back(a[y]);

	ll diff = a[y] - a[x];
	ll find = a[y] + diff;

	for(ll i=0;i<n;i++){
		if(i == x || i == y) continue;
		if(a[i] == find) find += diff, b.push_back(a[i]);
		else c.push_back(a[i]);
	}

	if(c.size() == 0) return 1;
	if(c.size() == 1 || c.size() == 2) return 1;

	ll d = c[1] - c[0];

	set<pair<ll, ll> > s;
	unordered_map<ll, ll> m;

	for(ll i=1;i<c.size();i++){
		ll df = c[i] - c[i-1];
		if(m.find(df) == m.end()){
			s.insert({df, 1});
			m[df] = 1;
		}
		else{
			s.erase(s.lower_bound({df, m[df]}));
			m[df]++;
			s.insert({df, m[df]});
		}
	}

	set<ll> c1;
	for(ll i=0;i<c.size();i++) c1.insert(c[i]);

	ll pos = b.size() - 1;

	// cout << b << " " << c << "\n";

	// cout << s << "\n";

	while(s.size() > 1 && pos >= 0){
		if(b[pos] >= c.back()) break;
		if(b[pos] <= c[0]) break;

		ll x = *c1.lower_bound(b[pos]);
		if(x == b[pos]) break;

		ll y = *((--c1.lower_bound(b[pos])));
		if(y == b[pos]) break;

		c1.insert(b[pos]);

		ll df = abs(x - y);

		s.erase(s.lower_bound({df, m[df]}));
		m[df]--;
		if(m[df] != 0)
			s.insert({df, m[df]});

		df = abs(b[pos] - y);

		if(m.find(df) == m.end()){
			s.insert({df, 1});
			m[df] = 1;
		}
		else{
			s.erase(s.lower_bound({df, m[df]}));
			m[df]++;
			s.insert({df, m[df]});
		}

		df = abs(x - b[pos]);

		if(m.find(df) == m.end()){
			s.insert({df, 1});
			m[df] = 1;
		}
		else{
			s.erase(s.lower_bound({df, m[df]}));
			m[df]++;
			s.insert({df, m[df]});
		}

		break;
		pos--;
	}

	return s.size() == 1;
}

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++) cin >> a[i];

	sort(a, a + n);

	if(n == 2 || n == 3 || n == 4){
		cout << "Yes\n";
		return;
	}

	if(check(0, 1) || check(0, 2) || check(1, 2)) cout << "Yes\n";
	else cout << "No\n";
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