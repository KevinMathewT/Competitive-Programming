#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

ld mid, l, r, precision;

ld getVal(ld x){
	return (pow(x, 3) - (5 * x) + 1);
}

void te(){
	cin >> l >> r;
	if((getVal(l) * getVal(r) >= 0.0)){
		cout << "No roots found.\n";
		return;
	}

	cin >> precision;
	cout << fixed << setprecision(10);

	while(abs(r-l) > (pow(10, -precision))){
		mid = (l + r) / 2;
		ld ans = getVal(mid);

		if(ans > 0)
			l = mid;
		else
			r = mid;
	}

	cout << mid << "\n";
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