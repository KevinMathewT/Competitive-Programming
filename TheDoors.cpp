#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[200010];

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll o = 0, z = 0;
	for(ll i=n-1;i>=0;i--){
		if(a[i] == 0)
			z = 1;
		if(a[i] == 1)
			o = 1;
		if(z == 1 && o == 1){
			cout << i + 1 << "\n";
			return;
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