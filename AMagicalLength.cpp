#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n;
pair<ld, ld> P[100010];
ld mn;

ld dist(pair<ld, ld> a, pair<ld, ld> b){
	return sqrt(pow(a.F - b.F, 2) + pow(a.S - b.S, 2));
}

ld triple(pair<ld, ld> a, pair<ld, ld> b, pair<ld, ld> c){
	return (dist(a, b) + dist(b, c) + dist(c, a));
}

ld rec(ll l, ll r){
	if((l + 2) == r)
		return triple(P[l], P[l + 1], P[l + 2]);
	if((l + 3) == r){
		ld mn1 = DBL_MAX;
		mn1 = min(mn1, triple(P[l], P[l+1], P[l+2]));
		mn1 = min(mn1, triple(P[l+1], P[l+2], P[l+3]));
		mn1 = min(mn1, triple(P[l], P[l+2], P[l+3]));
		mn1 = min(mn1, triple(P[l], P[l+1], P[l+3]));
		return mn1;
	}

	ll mid = (l + r) / 2;
	ld mn1 = rec(l, mid);
	ld mn2 = min(mn1, rec(mid + 1, r));

	ll a, b;
	for(ll i=mid;i>=l;i--)
		if(abs(P[i].F - P[mid].F) > (mn2 / 2)){
			a = i + 1;
			break;
		}

	for(ll i=mid;i<=r;i++)
		if(abs(P[i].F - P[mid].F) > (mn2 / 2)){
			b = i - 1;
			break;
		}

	vector<pair<ld, ld> > R;
	for(ll i=l;i<=r;i++)
		R.push_back({P[i].S, P[i].F});

	sort(R.begin(), R.end());

	for(ll i=0;i<R.size();i++)
		for(ll j=i+1;j<R.size();j++){
			if(abs(R[i].F - R[j].F) > (mn2))
				break;
			for(ll k=j+1;j<R.size();j++){
				if(abs(R[j].F - R[k].F) > (mn2))
					break;
				mn2 = min(mn2, triple({R[i].S, R[i].F}, {R[j].S, R[j].F}, {R[k].S, R[k].F}));
			}
		}

	return mn2;
}

void solve(ll t){
	mn = DBL_MAX;
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> P[i].F >> P[i].S;

	sort(P, P + n);

	cout << fixed << setprecision(10);
	cout << "Case " << t << ": " << rec(0, n-1) << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	for(ll i=0;i<T;i++)
		solve(i + 1);

	return 0;
}