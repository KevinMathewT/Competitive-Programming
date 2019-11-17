#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[200010];
unordered_map<ll, ll> um;

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll mx = -1, ans;

	for(ll i=0;i<n;i++){
		um[a[i]]++;
		if(um[a[i]] > mx){
			mx = um[a[i]];
			ans = a[i];
		}
	}

	ll pos = 0;

	for(ll i=0;i<n;i++)
		if(a[i] == ans){
			pos = i;
			break;
		}

	// cout << mx << " " << ans << " " << pos << "\n";

	cout << n - mx << "\n";

	for(ll i=pos-1;i>=0;i--){
		if(a[i] == ans)
			continue;
		if(a[i] > a[i+1]){
			cout << 2 << " ";
			cout << i + 1 << " ";
			cout << i + 2 << " ";
			cout << "\n";
			a[i] = a[i+1];
		}
		else{
			cout << 1 << " ";
			cout << i + 1 << " ";
			cout << i + 2 << " ";
			cout << "\n";
			a[i] = a[i+1];
		}
	}

	for(ll i=pos;i<n-1;i++){
		// cout << a[i+1] << " " << a[i] << "\n";
		if(a[i+1] == ans)
			continue;
		if(a[i+1] > a[i]){
			// cout << "---\n";
			cout << 2 << " ";
			cout << i + 2 << " ";
			cout << i + 1 << " ";
			cout << "\n";
			a[i+1] = a[i];
		}
		else{
			cout << 1 << " ";
			cout << i + 2 << " ";
			cout << i + 1 << " ";
			cout << "\n";
			a[i+1] = a[i];
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

	te();

	return 0;
}