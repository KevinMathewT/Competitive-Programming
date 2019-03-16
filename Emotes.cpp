#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, k;
ll a[200010], freq[200010];

void te(){
	cin >> n >> m >> k;

	for(ll i=0;i<n;i++){
		cin >> a[i];
		freq[i] = 0;
	}

	sort(a, a+n);
	
	ll max1 = a[n-1];
	ll max2 = a[n-2];
	ll hp = 0;

	hp += (m / (k + 1)) * max2;
	hp += (m - (m / (k + 1))) * max1;

	cout << hp;
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