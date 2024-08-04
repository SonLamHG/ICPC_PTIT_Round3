#include<bits/stdc++.h>
#define int long long

using namespace std;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n; cin>>n;
    for(int i=0; i<=100; i++){
        if(n>=4*i && (n-4*i)%7==0){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";

    return 0;
}
