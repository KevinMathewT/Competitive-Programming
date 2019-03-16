#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n;
	cin >> n;

	ll x = 0;
	cout << x << " ";
	ll c = 1;
	n += 2;

	while(n-=2){
		ll a, b;
		if(n == 1){
			cin >> a;
			cout << a << " ";
			break;
		}

		cin >> a >> b;

		cout << a << " " << a << " ";
	}
	// if(n == 0){
	// 	ll a, b;
	// 	cin >> a >> b;

	// 	cout << a << " " << a << " ";
	// }
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