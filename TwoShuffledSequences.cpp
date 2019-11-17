#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[200010], x[200010], y[200010];

void te(){
	cin >> n;
	ll pos1 = 0, pos2 = n/2-1;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	sort(a, a + n);

	ll count = 0;
	for(ll i=1;i<n;i++){
		if(a[i] == a[i-1])
			count++;
		if(count >= 2){
			cout << "NO\n";
			return;
		}
		if(a[i] != a[i-1])
			count = 0;
	}

	for(ll i=0;i<n;i++){
		if(i % 2 == 0)
			x[pos1++] = a[i];
		else
			y[pos2--] = a[i];
	}

	cout << "YES\n";
	cout << pos1 << "\n";
	for(ll i=0;i<pos1;i++)
		cout << x[i] << " ";
	cout << "\n";
	cout << (n) - pos1 << "\n";
	for(ll i=0;i<(n) - pos1;i++)
		cout << y[i] << " ";
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