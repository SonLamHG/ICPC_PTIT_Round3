#include<bits/stdc++.h>
#define int long long

using namespace std;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n; cin>>n;
    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    __builtin_
    vector<int> mn(n+1,0), mx(n+1,0);
    int mxx=-1e10;
    for(int i=1; i<=n; i++){
        mxx=max(mxx,a[i]);
        if(mxx==a[i]) mx[i]=1;
    }

    int mnn=1e10;
    for(int i=n; i>0; i--){
        mnn=min(mnn,a[i]);
        if(mnn==a[i]) mn[i]=1;
    }

    vector<int> ans;
    for(int i=1; i<=n; i++){
        if(mn[i] && mx[i]) ans.push_back(a[i]);
    }

    cout<<ans.size()<<' ';
    int flag=0;
    for(int i:ans){
        cout<<i<<' ';
        flag++;
        if(flag==100) break;
    }

    return 0;
}
