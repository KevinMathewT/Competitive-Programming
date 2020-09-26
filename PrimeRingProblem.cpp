#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second
#define fi(a, b) for(ll i=(a);i<=b;i++)
#define fj(a, b) for(ll j=(a);j<=b;j++)
#define fid(a, b) for(ll i=(a);i>=b;i--)
#define fjd(a, b) for(ll i=(a);i>=b;j--)

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

const ll N = 20, M = 100010;
ll n, p[M];

void recur(ll pos, ll mask, vector<ll> v){
	if(pos == n){
		if(p[v.back() + v[0]] != 1) return;
		for(ll i=0;i<v.size();i++) cout << v[i] << " ";
		cout << '\n';
		return;
	}
	if(pos == 0) {
		for(ll i=1;i<=1;i++) {
			v.push_back(i);
			recur(pos + 1, mask ^ (1LL << i), v);
			v.pop_back();
		}
		return;
	}

	// cout << pos << ' ' << mask << ' ' << v << "\n";
	for(ll i=1;i<=n;i++)
		if((mask & (1LL << i)) == 0){
			if(p[i + v[v.size() - 1]] == 1){
				v.push_back(i);
				recur(pos + 1, mask ^ (1LL << i), v);
				v.pop_back();
			}
		}
}

void solve(ll cs){
	cout << "Case " << cs << ":\n";
	recur(0, 0, vector<ll>(0));
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	for(ll i=0;i<M;i++) p[i] = 1;
	p[1] = 0;

	for(ll i=2;i*i<M;i++)
		if(p[i] == 1)
			for(ll j=i*i;j<M;j+=i)
				p[j] = 0;

	ll t = 0;
	while(cin >> n)
		solve(++t);

	return 0;
}