#include<bits/stdc++.h>
#define int long long

using namespace std;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int N=1e6+1;
    vector<int> a(N,0);
    a[0]=1, a[1]=1;

    for(int i=2; i*i<=N; i++){
        if(a[i]==0)
        for(int j=i*i; j<=N; j+=i){
            a[j]=1;
        }
    }

    int ans=0;
    int n; cin>>n;
    for(int i=2; i<=n/2; i++){
        if(a[i]==0 && a[n-i]==0) {
            ans++;
        }
    }
    cout<<ans;

    return 0;
}
