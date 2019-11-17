#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;
string s;
char a[110], b[110];

void te(ll test){
	cin >> s;
	n = s.size();

	for(ll i=0;i<n;i++){
		if(s[i] == '4'){
			a[i] = '3';
			b[i] = '1';
		}
		else{
			a[i] = s[i];
			b[i] = '0';
		}
	}

	cout << "Case #" << test << ": ";
	ll flag = 0;
	for(ll i=0;i<n;i++){
		if(flag == 0 && a[i] == '0')
			continue;
		cout << a[i];
		flag = 1;
	}
	cout << " ";
	flag = 0;
	for(ll i=0;i<n;i++){
		if(flag == 0 && b[i] == '0')
			continue;
		cout << b[i];
		flag = 1;
	}
	cout << "\n";
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
	for(ll i=0;i<T;i++)
		te(i);

	return 0;
}