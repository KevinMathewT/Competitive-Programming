#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, k, a[10010];
vector<ll> rem, diff;

void solve(){
	cin >> n >> k;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	ll c = 0;

	for(ll i=1;i<n-1 && c < k;i++){
		if(a[i-1] <= a[i] && a[i] <= a[i+1]){
			a[i] = LLONG_MAX;
			c++;
		}
	}

	for(ll i=0;i<n;i++)
		if(a[i] != LLONG_MAX)
			rem.push_back(a[i]);

	n = rem.size();

	for(ll i=0;i<n-1;i++)
		diff.push_back(abs(rem[i] - rem[i+1]));

	sort(diff.begin(), diff.end());

	for(ll i=0;i<(k-c);i++){
		
	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}