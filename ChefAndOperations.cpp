#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n;
	cin >> n;
	ll a[n], b[n];
	for(ll i=0;i<n;i++)
		cin >> a[i];
	for(ll i=0;i<n;i++)
		cin >> b[i];

	for(ll i=0;i<n;i++)
		if(a[i] > b[i]){
			cout << "NIE\n";
			return;
		}

	if(n == 1 || n == 2){
		cout << "NIE\n";
		return;
	}
	// if(n == 2){
	// 	if(b[1]-a[1] != 2*(b[0]-a[0]))
	// 		cout << "NIE\n";
	// 	else
	// 		cout << "TAK\n";
	// }
	
	ll o;
	for(ll i=0;i<=n-3;i++){
		if(a[i] > b[i]){
			cout << "NIE\n";
			return;
		}			
		if(b[i] == a[i])
			continue;
		o = b[i] - a[i];
		a[i] += o;
		a[i+1] += 2*o;
		a[i+2] += 3*o;
	}

	// for(ll i=0;i<n;i++)
	// 	cout << a[i] << " ";
	// cout << "\n";

	if(a[n-3] != b[n-3] || a[n-2] != b[n-2] || a[n-1] != b[n-1])
		cout << "NIE\n";
	else
		cout << "TAK\n";
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