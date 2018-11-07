#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll a[100], b[100], size, n, k;

void recur(ll i){
	if(i == 0) return;
	if(i == 1){
		ll t = b[0] - k;
		b[0] -= t;
		b[1] -= t;
	// for(ll i=0;i<size;i++)
	// 	cout << b[i] << "\t" ;
	// cout << "\n";
		return;
	}
	recur(i-2);
	ll t = min(b[i-2]-k, b[i]-b[i-1]);
	b[i-2] -= t; b[i] -= t;
	t = b[i-2] - k;
	b[i-2] -= t;
	b[i-1] -= t;
	t = b[i-1] - k;
	b[i-1] -= t;
	b[i] -= t;

	// for(ll i=0;i<size;i++)
	// 	cout << b[i] << "\t" ;
	// cout << "\n";
}

void te(){
	cin >> n >> k;

	for(ll i=0;i<n;i++)
		cin >> a[i];

	// for(ll i=0;i<n;i++)
	// 	cout << a[i] << " " ;
	// cout << "\n";

	sort(a, a+n);

	ll pos = 0;
	for(ll i=0;i<n;i++)
		if(a[i] > k){
			pos = i;
			break;
		}

	// cout << pos << "-\n";

	size = n-pos;
	for(ll i=0;i<size;i++)
		b[i] = a[pos+i];

	// cout << size << "\n";

	if(size == 0 || size == 1){
		cout << accumulate(a, a+n, 0) << "\n";
		return;
	}


	// for(ll i=0;i<size;i++)
	// 	cout << b[i] << "-" ;
	// cout << "\n";

	recur(size-2);
	ll t = b[size-2]-k;
	b[size-2] -= t;
	b[size-1] -= t;

	for(ll i=0;i<size;i++)
		a[pos+i] = b[i];

	// for(ll i=0;i<n;i++)
	// 	cout << a[i] << "\t" ;
	// cout << "\n";

	cout << accumulate(a, a+n, 0) << "\n";
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