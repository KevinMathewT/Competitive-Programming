#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

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

ll n;
string s;
vector<ll> p;

void solve(){
	cin >> s;
	cin >> n;

	cin.ignore(256, '\n');
	p.clear();

	for(ll i=1;i<=s.size();i++)
		if(s[i-1] == '1')
			p.push_back(i);

	// cout << p << "\n";

	ll l = 2, r = LLONG_MAX, poss = -1;

	while(l <= r){
		ll mid = (l + r) / 2;

		ll t = 0;

		for(ll i=1;i<(1<<p.size());i++){
			ll tt = 1, par = 0; 
			for(ll j=0;j<p.size();j++)
				if((i & (1 << j)) != 0)
					par ^= 1, tt *= p[j];

			if(par)
				t += mid / tt;
			else
				t -= mid / tt;
		}

		if(t < n)
			l = mid + 1;
		else{
			poss = mid;
			r = mid - 1;
		}
	}

	cout << poss << "\n";
}

int main()
{
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