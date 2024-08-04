#include<bits/stdc++.h>
#define int long long

using namespace std;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n,m; cin>>n>>m;
    int a[n+1];
    int ans=0;
    map<int,int> mp; mp[0]=1;
    int sum=0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        sum+=a[i];
        ans+=mp[sum%m];
        mp[sum%m]++;
    }

    cout<<ans;

    return 0;
}
