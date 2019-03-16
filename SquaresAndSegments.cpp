#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;

void te(){
	cin >> n;
	ll a, b;
	a = b = floor(sqrt(n));

	if(a * b >= n){
		cout << (a + b) << "\n";
		return;
	}

	b++;

	if(a * b >= n){
		cout << (a + b) << "\n";
		return;
	}

	a++;
	
	if(a * b >= n){
		cout << (a + b) << "\n";
		return;
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