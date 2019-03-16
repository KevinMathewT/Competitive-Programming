#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll q;

void te(){
	cin >> q;
	while(q--){
		ll n, a, b;
		cin >> n >> a >> b;

		if(n == 1){
			cout << a << "\n";
			continue;
		}

		if(2*a <= b){
			cout << n * a << "\n";
		}
		else{
			cout << ((n / 2) * b + (n % 2) * a) << "\n";
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