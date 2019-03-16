#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[100010], segTree[5000010], b[100010];

void update(ll i, ll l, ll r, ll a2, ll x){
	// cout << l << " " << r << " *****\n";
	// cout << i << "\n";
	if(l == r){
		segTree[i] += a2;
		return;
	}

	ll mid = (l + r) / 2;
	if(x <= mid)
		update(2*i, l, mid, a2, x);
	else
		update(2*i + 1, mid + 1, r, a2, x);

	segTree[i] = segTree[2*i] + segTree[2*i + 1];
}

ll query(ll i, ll l, ll r, ll a2, ll b){
	if(r < l || r < a2 || l > b)
		return 0;
	if(l >= a2 && r <= b)
		return segTree[i];
	ll mid = (l + r) / 2;
	ll a1 = query(2*i, l, mid, a2, b);
	ll b1 = query(2*i + 1, mid + 1, r, a2, b);

	return a1 + b1;
}

ll query(ll x){
	return(query(1, 0, 1000010, 0, x));
}

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	for(ll i=0;i<4000010;i++)
		segTree[i] = 0;

	for(ll i=n-1;i>=0;i--){
		// cout << a[i] << " ";
		update(1, 0, 1000010, a[i], a[i]);
		// cout << "\n";
		// for(ll i=0;i<=40;i++)
		// 	cout << i << " " << segTree[i] << "\n";
		// cout << "\n";
		b[i] = abs((query(1000001) - query(a[i])) - (query(a[i]-1) - query(0)));
	}

	// for(ll i=0;i<n;i++)
	// 	cout << b[i] << " ";
	// cout << "\n";
	for(ll i=0;i<n;i++)
		b[i] = (b[i] % 60);

	ll ans = 0;
	for(ll i=0;i<n;i++){
		if(b[i] == 0)
			ans += 2;
		else if(b[i] == 1)
			ans += 1;
		else{
			ll x = 2, y = 1, z;
			for(ll j=2;j<=100;j++){
				z = (x + y);
				if(j == b[i]){
					ans += z % 10;
					break;
				}
				x = y;
				y = z;
			}
		}
	}

	cout << ans << "\n";
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