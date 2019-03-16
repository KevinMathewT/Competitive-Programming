#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n, m;
	cin >> n >> m;
	ll hour = 0, min = 0;
	for(ll i=0;i<n;i++){
		string s1, s2;
		cin >> s1 >> s2;
		// cout << s1 << " " << s2 << "\n";
		ll h1 = stoi(s1.substr(0, 2));
		ll m1 = stoi(s1.substr(3, 2));
		ll h2 = stoi(s2.substr(0, 2));
		ll m2 = stoi(s2.substr(3, 2));

		if(m2 >= m1){
			hour += h2 - h1;
			min += m2 - m1;
		}

		else{
			hour += h2 - h1 - 1;
			min += m2 - m1 + 60;
		}
	}

	// cout << hour << " " << min << "\n";

	hour += min / 60;

	if(hour >= m)
		cout << "YES\n";
	else
		cout << "NO\n";
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