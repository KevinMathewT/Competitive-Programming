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

ll recur(vector<ll> v, ll bit){
	if(bit == -1) return 0;
	ll match = (1LL << bit);
	// cout << match << "\n";
	ll flag = 1, flag2 = 1;
	for(ll i=0;i<v.size();i++)
		if((v[i] & match) != 0) flag = 0;
		else flag2 = 0;

	if(flag == 1 || flag2 == 1) return recur(v, bit - 1);

	vector<ll> s1(0), s2(0);
	for(ll i=0;i<v.size();i++)
		if((v[i] & match) == 0)
			s1.push_back(v[i]);
		else s2.push_back(v[i]);

	// cout << v << ' ' << s1 << ' ' << s2 << "\n";
	return match + min(recur(s1, bit - 1), recur(s2, bit - 1));
}

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++) cin >> a[i];
	vector<ll> send(n, 0);
	for(ll i=0;i<n;i++) send[i] = a[i];

	cout << recur(send, 32) << "\n";
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