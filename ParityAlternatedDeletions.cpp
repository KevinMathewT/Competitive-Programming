#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[2010];
vector<ll> even, odd;

void te(){
	cin >> n;
	ll sum2 = 0;
	for(ll i=0;i<n;i++){
		cin >> a[i];
		sum2 += a[i];
		if(a[i] % 2 == 0)
			even.push_back(a[i]);
		else
			odd.push_back(a[i]);
	}

	sort(even.begin(), even.end(), greater<ll>());
	sort(odd.begin(), odd.end(), greater<ll>());

	ll sum1 = 0;

	ll i;
	for(i=0;i<min(even.size(), odd.size());i++){
		sum1 += even[i] + odd[i];
	}

	if(even.size() > odd.size())
		sum1 += even[i];
	if(even.size() < odd.size())
		sum1 += odd[i];

	cout << sum2 - sum1 << "\n";
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