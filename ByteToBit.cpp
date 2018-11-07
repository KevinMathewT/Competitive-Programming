#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll pow(ll a, ll x){
	if(x == 0) return 1L;
	if(x == 1) return (ll)a;
	if(x % 2 == 0) return pow((ll) a * a, (ll) x / 2);
	else return (a * pow((ll) a * a, (ll) x / 2));
}

void te(){
	ll n;
	cin >> n;

	ll p = n / 26;
	ll rem = n % 26;

	if(rem == 0)
		cout <<  "0 0 " << (ll)pow(2, p) / 2 << "\n";		
	else if(rem <= 2 && rem > 0)
		cout << (ll)pow(2, p) << " 0 0\n";
	else if(rem > 2 && rem <= 10)
		cout <<  "0 " << (ll)pow(2, p) << " 0\n";
	else
		cout <<  "0 0 " << (ll)pow(2, p) << "\n";
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