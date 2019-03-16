#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

// vector<ll> aOdd;
// vector<ll> aEven;
vector<ll> a;
// vector<ll> bOdd;
// vector<ll> bEven;
vector<ll> b;
string s;

void te(){
	cin >> s;
	for(ll i=0;i<s.size();i++){
		if(s[i] == 'a')
			a.push_back(i+1);
		// if(s[i] == 'a' && i%2 == 0)
		// 	aEven.push_back(i);
		// if(s[i] == 'a' && i%2 != 0)
		// 	aOdd.push_back(i);
		// if(s[i] == 'b' && i%2 == 0)
		// 	bEven.push_back(i);
		// if(s[i] == 'b' && i%2 != 0)
		// 	bOdd.push_back(i);
		if(s[i] == 'b')
			b.push_back(i+1);
	}

	ll aeven = 0, aodd = 0;
	ll aEven = 0, aOdd = 0;

	// cout << a.size() << " " << b.size() << "\n";

	for(ll i=0;i<a.size();i++){
		aodd++;
		if(a[i] % 2 == 0){
			aeven += aOdd;
			aodd += aEven;
			aEven++;
		}
		else{
			aeven += aEven;
			aodd += aOdd;
			aOdd++;
		}
		// cout << aodd << "\n";
	}

	ll beven = 0, bodd = 0;
	ll bEven = 0, bOdd = 0;

	for(ll i=0;i<b.size();i++){
		bodd++;
		if(b[i] % 2 == 0){
			beven += bOdd;
			bodd += bEven;
			bEven++;
		}
		else{
			beven += bEven;
			bodd += bOdd;
			bOdd++;
		}
		// cout << bodd << "-\n";
	}

	cout << (aeven + beven) << " " << (aodd + bodd) << "\n";
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