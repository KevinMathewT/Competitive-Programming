#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll k, n;
unordered_map<ll, ll> um;

void te(){
	um.clear();
	cin >> k >> n;
	ll c = 0;
	ll t = k;
	while(t > 0){
		if(um[t % 10] != 1){
			c++;
			um[t % 10] = 1;
		}

		t /= 10;
	}

	if(c == 3)
		cout << 27 << "\n";
	if(c == 2)
		cout << 8 << "\n";
	if(c == 1)
		cout << 1 << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}