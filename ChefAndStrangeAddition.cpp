#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll a, b, c; 
	cin >> a >> b >> c;

	vector<ll> ba;
	vector<ll> bb;

	ll t = a;
	while(t > 0){
		ba.push_back(t % 2);
		t /= 2;
	}

	t = b;
	while(t > 0){
		bb.push_back(t % 2);
		t /= 2;
	}

	for(ll i=0;i<ba.size();i++)
		cout << ba[i] << "-";
	cout << "\n";

	for(ll i=0;i<bb.size();i++)
		cout << bb[i] << "-";
	cout << "\n";

	cout << a << " " << b << "\n";

	cout << max(ba.size(), ba.size())-min(ba.size(), ba.size()) << "--\n";

	for(ll i=0;i<max(ba.size(), ba.size())-min(ba.size(), ba.size());i++)
		if(ba.size() < bb.size())
			ba.push_back(0);
		else
			bb.push_back(0);

	ll zz = 0, oo = 0, zo = 0, oz = 0;
	ll sz = ba.size();

	for(ll i=0;i<sz;i++)
		cout << ba[i] << "-" << bb[i] << "\n";

	for(ll i=0;i<sz;i++){
		if(ba[i] == 0 && bb[i] == 0)
			zz++;
		else if(ba[i] == 0 && bb[i] == 1)
			zo++;	
		else if(ba[i] == 1 && bb[i] == 0)
			oz++;
		else
			oo++;
	}

	cout << oo << " " << oz << " " << zo << " " << zz << "\n"; 
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