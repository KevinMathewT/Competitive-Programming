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

string s, t;

void solve(){
	cin >> s >> t;

	if(s.size() < t.size()){
		reverse(s.begin(), s.end());
		ll d = t.size() - s.size();
		for(ll i=0;i<d;i++) s.push_back('0');
		reverse(s.begin(), s.end());
	}

	if(s.size() > t.size()){
		reverse(t.begin(), t.end());
		ll d = s.size() - t.size();
		for(ll i=0;i<d;i++) t.push_back('0');
		reverse(t.begin(), t.end());
	}

	ll p1 = s.size() - 1, p2 = t.size() - 1;

	ll ans = 0, c = 0;

	while(p1 >= 0 && p2 >= 0){
		if(s[p1] == '1' && t[p2] == '1'){
			c = 0;
			p1--;
			p2--;
			while(p1 >= 0 && p2 >= 0 && (s[p1] == '1' || t[p2] == '1') && !(s[p1] == '1' && t[p2] == '1')) p1-=1, p2-=1, c++;
			c++;
			ans = max(ans, c);
			continue;
		}

		p1--;
		p2--;
	}

	for(ll i=0;i<t.size();i++)
		if(t[i] == '1'){
			ans++;
			break;
		}

	cout << ans << "\n";
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