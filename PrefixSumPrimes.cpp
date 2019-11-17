#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Shubham Kumar
// Birla Institute of Technology, Mesra

ll n, a[200010];

bool isPrime(ll x){
	if(x == 1 || x == 0)
		return false;
	ll c = 0;
	for(ll i=2;i*i<=x;i++)
		if(x % i == 0)
			c++;

	if(c == 0)
		return true;
	return false;
}

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	sort(a, a + n);
	ll p = n;

	if(*min_element(a, a + n) != 1 || *max_element(a, a + n) != 2){
		for(ll i=0;i<n;i++)
			cout << a[i] << " ";
		cout << "\n";
		return;
	}

	for(ll i=1;i<(n+1)/2;i++)
		swap(a[i], a[n-i]);
	swap(a[0], a[1]);
	for(ll i=0;i<n;i++)
		cout << a[i] << " ";
	cout << "\n";
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