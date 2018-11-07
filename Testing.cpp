#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll getToSingle(ll n){
	if(n < 10) return 0;
	ll c = 0;
	ll sum = 0;
	ll t = n;
	while(true){
		t = n;
		sum = 0;
		while(t > 0){
			sum += t % 10;
			t /= 10;
		}
		c++;
		n = sum;
		if(sum < 10) break;;
	}
	return c;
}

void te(){
	ll t = 0;
	for(ll i=1;i<=200;i++)
		t += (i*i) * ((ll)((200-i)/2) * 2 + 1);

	cout << t << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}