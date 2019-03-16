#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;
vector<ll> a;
ll um[2*1000010], biggest[2*1000010];

void te(){
	cin >> n;
	for(ll i=0;i<2*1000010;i++){
		biggest[i] = 0;
		um[i] = 0;
	}
	for(ll i=0;i<n;i++){
		ll b;
		cin >> b;
		biggest[b+1] = b;
		a.push_back(b);
	}

	biggest[0] = -1;
	for(ll i=1;i<2*1000010;i++)
		if(biggest[i] == 0)
			biggest[i] = biggest[i-1];

	sort(a.begin(), a.end());

	ll mx = 0;

	ll oper = 0;

	for(ll i=0;i<n;i++){
		oper = 0;
		if(um[a[i]] == 1)
			continue;
		for(ll j=a[i];j<=2*1000010;j+=a[i]){
	// 		// if(a[i] == 100)
	// 			// cout << j << "\n";
	// 		ll l = 0, r = a.size();
	// 		oper++;
			if(biggest[j] > a[i])
				mx = max(mx, biggest[j] % a[i]);
		}
		// cout << a[i] << " " << oper << "\n";
		um[a[i]] = 1;
	}

	// cout << oper << '\n';
	cout << mx << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}