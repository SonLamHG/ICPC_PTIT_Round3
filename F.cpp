#include<bits/stdc++.h>
#define ll long long


using namespace std;
ll a,b, M;

ll mul(ll a,ll b){
	if(b==0) return 0;
	ll t = mul(a, b/2) % M;
	if(b&1){
		return ((t + t) % M + a) % M;
	} else return (t+t)% M;
}

struct Matrix{
    ll m[3][3]= {};
    friend Matrix operator * (Matrix a, Matrix b){
    	Matrix c;
    	for(int i = 1; i<= 2;i++){
    		for(int j =1;j<=2;j++){
    			c.m[i][j] = 0;
    			for(int k = 1;k<= 2;k++){
    				c.m[i][j] = c.m[i][j] + mul(a.m[i][k] , b.m[k][j]);
    				c.m[i][j] %= M;
				}
			}
		}
		return c;
	}
};


Matrix _pow(Matrix a, ll k){
	if(k==1) return a;
	Matrix t = _pow(a, k/2);
	if(k&1) return a*t*t;
	else return t*t;
}

ll F(ll x){
	if(x < 2) return x;
	Matrix t;
	t.m[1][1] = 0;
	t.m[1][2] = t.m[2][1] =t.m[2][2] = 1;
	Matrix ans = _pow(t,x-1);
	return (ans.m[2][2] ) % M;
}
void solve(){
	cin>>a>>b>>M;
	ll x = __gcd(a,b);
	cout<<F(x);
	
}
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
	int t; cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
    return 0;
}
