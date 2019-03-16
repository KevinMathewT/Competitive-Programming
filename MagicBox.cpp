#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ld v[3], co[3], a[6];

ld getAngle(ld x, ld y, ld z, ld c1, ld c2, ld c3, ld v1, ld v2, ld v3){
	// cout << x << " " << y << " " << z << "\n";
	// cout << c1 << " " << c2 << " " << c3 << "\n";
	

	x = x - c1;
	y = y - c2;
	z = z - c3;

	// cout << x << " " << y << " " << z << "\n";

	ld cos = (x * v1 + y * v2 + z * v3) / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)) * sqrt(pow(v1, 2) + pow(v2, 2) + pow(v3, 2)));

	// cout << cos << "\/n\n";
	return cos;
}

void te(){
	for(ll i=0;i<3;i++)
		cin >> v[i];
	for(ll i=0;i<3;i++)
		cin >> co[i];
	for(ll i=0;i<6;i++)
		cin >> a[i];

	ld ans = 0;
	ld ans1 = (getAngle(v[0], v[1], v[2], co[0]/2, 0, co[2]/2, 0, -1, 0));
	ld ans2 = (getAngle(v[0], v[1], v[2], co[0]/2, co[1], co[2]/2, 0, 1, 0));
	ld ans3 = (getAngle(v[0], v[1], v[2], co[0]/2, co[1]/2, 0, 0, 0, -1));
	ld ans4 = (getAngle(v[0], v[1], v[2], co[0]/2, co[1]/2, co[2], 0, 0, 1));
	ld ans5 = (getAngle(v[0], v[1], v[2], 0, co[1]/2, co[2]/2, -1, 0, 0));
	ld ans6 = (getAngle(v[0], v[1], v[2], co[0], co[1]/2, co[2]/2, 1, 0, 0));
	

	if(ans1 > 0 && ans1 <=1)
		ans += a[0];
	if(ans2 > 0 && ans2 <=1)
		ans += a[1];
	if(ans3 > 0 && ans3 <=1)
		ans += a[2];
	if(ans4 > 0 && ans4 <=1)
		ans += a[3];
	if(ans5 > 0 && ans5 <=1)
		ans += a[4];
	if(ans6 > 0 && ans6 <=1)
		ans += a[5];

	// cout << getAngle(v[0], v[1], v[2], co[0]/2, 0, co[2]/2, 0, -1, 0) << "\n";

	cout << ans << "\n";
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