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

ll n, k, a[500010], pre[500010], L[500010];
vector<ll> LIS;

void solve(){
	LIS.clear();
	cin >> n >> k;
	for(ll i=0;i<n;i++) cin >> a[i];

	pre[0] = a[0];
	for(ll i=1;i<n;i++)
		pre[i] = a[i] + pre[i - 1];

	// for(ll i=0;i<n;i++)
	// 	cout << pre[i] << " ";
	// cout << "\n";

	if(pre[0] > 0){
		L[0] = 1;
		LIS.push_back(pre[0]);
	}
	else
		L[0] = 0;

	for(ll i=1;i<n;i++){
		if(pre[i] < 1){
			L[i] = 0;
			continue;
		}
		auto it = lower_bound(LIS.begin(), LIS.end(), pre[i]);
		if(it == LIS.end()){
			LIS.push_back(pre[i]);
			L[i] = LIS.size();
			continue;
		}

		L[i] = it - LIS.begin() + 1;
		*it = pre[i];
	}

	if(L[n - 1] < k){
		cout << "NO\n";
		return;
	}

	cout << "YES\n";

	vector<ll> pos(0, 0);
	ll ctot = LLONG_MAX, cl = L[n - 1] + 1;

	for(ll i=n-1;i>=0 && k>0;i--){
		if(pre[i] < ctot && L[i] == cl - 1){
			pos.push_back(i);
			ctot = pre[i];
			cl = L[i];
			k--;
		}
	}

	// cout << pos << "\n";

	ll l = -1;
	for(ll i=pos.size() - 1;i>=0;i--){
		cout << pos[i] - l << " ";
		l = pos[i];
	}
	cout << "\n";
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