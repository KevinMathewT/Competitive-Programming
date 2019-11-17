#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[100010];
vector<ll> ranges;
const ll m = 1e9 + 7;

ll mod_pow(ll a, ll x){
	if(x == 0)
		return 1;
	if(x == 1)
		return a % m;

	if(x % 2 == 0)
		return mod_pow((a * a) % m, x / 2);
	else
		return (mod_pow((a * a) % m, x / 2) * a) % m;
}

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	a[n] = 100;

	if(a[0] != 1 && a[0] != -1){
		cout << 0 << "\n";
		return;
	}

	ll co = 0;
	for(ll i=0;i<n;i++)
		if(a[i] == -1)
			co++;

	if(co == 0){
		cout << 0 << "\n";
		return;
	}

	if(n != 1){
		for(ll i=0;i<n-1;i++)
			if(a[i] != -1 && a[i+1] != -1 && a[i+1] != 1 && a[i] != a[i+1]-1){
				cout << 0 << "\n";
				return;
			}
	}

	for(ll i=n-1;i>0;i--)
		if(a[i] != -1 && a[i] != 1)
			a[i-1] = a[i] - 1;

	if(a[0] == -1){
		a[0] = 1;
	}

	if(a[0] != 1 && a[0] != -1){
		cout << 0 << "\n";
		return;
	}


	// for(ll i=0;i<n;i++)
	// 	cout << a[i] << " ";
	// cout << "\n";

	ll ans = 1, curr = 0;

	for(ll i=0;i<=n-1;i++){
		if(a[i] == -1 && a[i-1] != -1)
			ranges.push_back(i);
		if(a[i] == -1 && a[i+1] != -1)
			ranges.push_back(i);
	}

	for(ll i=0;i<ranges.size();i+=2)
		ans = (ans * mod_pow(2, ranges[i+1]-ranges[i]+1)) % m;

	cout << ans << "\n";
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
	while(T--)
		te();

	return 0;
}