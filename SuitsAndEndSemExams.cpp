#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n, k;
	cin >> n >> k;
	ll a[n];

	for(ll i=0;i<n;i++)
		cin >> a[i];

	if(n == 0){
		cout << -1 << "\n";
		return;
	}

	ll low = 1, high = *max_element(a, a + n) + 100, curr = -1;

	while(low <= high){
		ll tot = 0, mid = (low + high) / 2;
		for(ll i=0;i<n;i++)
			tot += a[i] / mid;
		cout << mid << " " << tot << "\n";
		if(tot >= k){
			curr = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	cout << curr << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}