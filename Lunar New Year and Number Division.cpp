#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[300010];

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	sort(a, a+n);

	ll sum = 0;

	for(ll i=0;i<n/2;i++){
		sum += pow(a[i] + a[n-i-1], 2);
	}

	if(n % 2 == 1){
		sum += pow(a[n/2], 2);
	}

	cout << sum << "\n";
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