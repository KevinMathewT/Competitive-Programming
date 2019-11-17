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

ll n, p;
vector<ll> v;

void solve(){
	cin >> n >> p;
	ll first;
	for(ll i=0;i<n;i++){
		if(i == p)
			cin >> first;
		else{
			ll a;
			cin >> a;
			v.push_back(a);
		}
	}

	sort(v.begin(), v.end());

	if(first > 300){
		cout << 0 << " " << 0 << "\n";
		return;
	}

	vector<ll> v1;
	v1.push_back(first);

	for(ll i=0;i<v.size();i++)
		v1.push_back(v[i]);

	for(ll i=1;i<n;i++)
		v1[i] = v1[i-1] + v1[i];

	for(ll i=0;i<n;i++){
		if(v1[i] > 300){
			ll ac, pt = 0;
			for(ll j=0;j<i;j++)
				pt += v1[j];
			ac = i;
			cout << ac << " " << pt << "\n";
			return;
		}
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}