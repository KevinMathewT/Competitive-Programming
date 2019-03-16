#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;
ll a[10000+100];

ll Partition(ll l, ll r){
	ll q = l;

	for(ll j=l;j<r;j++){
		if(a[j] < a[r]){
			ll t = a[j];
			a[j] = a[q];
			a[q] = t;
			q++;
		}
	}

	ll t = a[r];
	a[r] = a[q];
	a[q] = t;

	return q;
}

void QuickSort(ll l, ll r){
	if(l < r){
		ll j = Partition(l, r);
		cout << j << "\n";
		QuickSort(l, j-1);
		QuickSort(j+1, r);
	}
}

void te(){
	cin >> n;

	for(ll i=0;i<n;i++)
		cin >> a[i];
	QuickSort(0, n-1);
	for(ll i=0;i<n;i++)
		cout << a[i] << " ";
	cout << "\n";
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