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

const ll N = 200010, M = 1e9 + 7;
ll n, a[N];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++) cin >> a[i];

	set<pair<ll, pair<ll, ll> > > s1, s2, s3;
	ll co = 1;
	for(ll i=0;i<n;i++){
		ll j = i;
		while(a[i] == a[j] && j < n) j++;

		s1.insert({i - j, {i, j - 1}});
		s2.insert({i, {j - i, j - 1}});
		s3.insert({j - 1, {j - i, i}});

		i = j - 1;
	}

	ll ans = 0;

	cout << s1 << '\n';
	auto it = *s1.begin();
	cout << it << "\n";

	cout << s1 << "\n";
	cout << s2 << "\n";
	cout << s3 << "\n";

	while(s1.size() > 0){
		ans++;

		auto it = *s1.begin();
		ll len = -it.F;
		ll st = it.S.F;
		ll en = it.S.S;

		s1.erase(s1.find({-len, {st, en}}));
		s2.erase(s2.find({st, {len, en}}));
		s3.erase(s3.find({en, {len, st}}));

		auto pre1 = s2.lower_bound({en + 1, {0, 0}});
		auto it1;
		if(pre1 != s2.end())
			auto it1 = *s2.lower_bound({en + 1, {0, 0}});

		auto pre2 = s2.lower_bound({en + 1, {0, 0}});
		auto it2;
		if(pre2 != s3.end())
			auto it2 = *s3.lower_bound({en + 1, {0, 0}});

		if(pre1 != s2.end()){
			ll len1 = -it1.S.F;
			ll st1 = it1.F;
			ll en1 = it1.S.S;
		}
		else{
			len1 = 0;
			st1 = 0;
			en1 = 0;
		}

		ll len2 = -it2.S.F;
		ll st2 = it2.S.S;
		ll en2 = it2.F;

		if(a[st1] != a[st2]) continue;

		s1.erase(s1.find({-len1, {st1, en1}}));
		s2.erase(s2.find({st1, {len1, en1}}));
		s3.erase(s3.find({en1, {len1, st1}}));

		s1.erase(s1.find({-len1, {st1, en1}}));
		s2.erase(s2.find({st1, {len1, en1}}));
		s3.erase(s3.find({en1, {len1, st1}}));

		// Unite

		ll len3 = (len1 + len2);
		ll st3 = st2;
		ll en3 = en1;

		s1.insert({-len3, {st3, en3}});
		s2.insert({st3, {len3, en3}});
		s3.insert({en3, {len3, st3}});
	}

	cout << ans << "\n";
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