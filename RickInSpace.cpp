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

const ll N = 10000000, M = 1e9 + 7;
vector<ll> is_prime(N+1, 1), primes(0);
ll n;

void solve(){
	cin >> n;
	vector<ll> f(0);

	for(ll i : primes) if(n % i == 0) f.push_back(i);

	ll tot = 0;

	for(ll i=0;i<(1 << f.size());i++){
		ll pr = 1;
		for(ll j=0;j<f.size();j++)
			if((1 << j) & i)
				pr *= f[j];

		
	}
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	is_prime[0] = is_prime[1] = 0;
	for (ll i = 2; i * i <= N; i++) {
	    if (is_prime[i]) {
	        for (ll j = i * i; j <= N; j += i)
	            is_prime[j] = false;
	    }
	}

	for(ll i = 2; i * i <= N; i++)
		if(is_prime[i] == 1) primes.push_back(i);

	ll T;
	cin >> T;
	while(T--)
		solve();


	return 0;
}