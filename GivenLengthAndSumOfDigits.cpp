#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll m, s;
	cin >> m >> s;
	ll t = s;
	ll a[m];

	if(m == 1 && s == 0){
		cout << 0 << " " << 0 << "\n";
		return;
	}
	
	if(s < 1 || s > (9 * m)){
		cout << "-1 -1\n";
		return;
	}

	for(ll i=0;i<m;i++){
		if(s > 9){
			a[i] = 9;
			s -= 9;
		}
		else{
			a[i] = s;
			s -= s;
		}
	}

	if(a[m-1] == 0){
		for(ll i=m-2;i>=0;i--){
			if(a[i] > 0){
				a[i] -= 1;
				a[m-1] += 1;
				break;
			}
		}
	}

	for(ll i=m-1;i>=0;i--)
		cout << a[i] << "";
	cout << " "; 

	s = t;
	// cout << s << "\n";

	for(ll i=0;i<m;i++){
		if(s > 9){
			a[i] = 9;
			s -= 9;
		}
		else{
			a[i] = s;
			s -= s;
		}
	}

	string ans = "";

	for(ll i=0;i<m;i++)
		cout << a[i] << "";
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