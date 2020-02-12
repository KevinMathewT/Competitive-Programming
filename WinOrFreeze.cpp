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
ll q;
unordered_map<ll, ll> dp;

ll game(ll x){
	if(x == 1) return dp[x] = 1;
	if(dp.find(x) != dp.end()) return dp[x];

	vector<ll> poss(0);
	for(ll i=2;i*i<=x;i++)
		if(x % i == 0) poss.push_back(1 - game(i)), poss.push_back(1 - game(x / i));

	if(poss.size() == 0) return dp[x] = 1;
	ll w = 0;
	for(ll i=0;i<poss.size();i++) w |= poss[i];

	return dp[x] = w;
}

void solve(){
	cin >> q;

	game(q);

	if(game(q) == 0) cout << "2\n";
	else{
		cout << "1\n";
		for(ll i=2;i*i<=q;i++){
			if(q % i == 0) {
				if(dp[i] == 0) {
					cout << i << "\n";
					return;
				}
				if(dp[q / i] == 0) {
					cout << q / i << "\n";
					return;
				}
			}
		}
		cout << "0\n";
	}
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