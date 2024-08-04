#include<bits/stdc++.h>
#define int long long

using namespace std;
const int maxn=1e5+1;
int n;
int a[maxn]; pair<int,int> st[4*maxn];
pair<int,int> mx(pair<int,int> a, pair<int,int> b){
    vector<int> v;
    v={a.first,a.second,b.first,b.second};
    sort(v.begin(),v.end());
    return {v[3],v[2]};
}
auto build (int id, int l, int r) {
    if (l == r) { st[id].first = a[l]; st[id].second=0;  return; }
    int mid = (l + r) / 2;
    build(2 *id, l, mid);
    build(2*id+1, mid+1, r);
    st[id] = mx(st[2*id], st[2*id+1]); // NOTE
};
void update(int id, int l, int r, int idx, int val){
    if(!(idx>=l && idx<=r)) return;
    if(l==r) {st[id].first=val; st[id].second=0; return;}
    int mid=(l+r)/2;
    update(2*id, l, mid, idx, val);
    update(2*id+1, mid+1, r, idx, val);
    st[id]=mx(st[2*id], st[2*id+1]);  // NOTE
}
pair<int,int> get(int id, int l, int r, int u, int v){
    if(l>v || r<u) return {0,0};   // NOTE
    if(l>=u && r<=v) return st[id];
    int mid=(l+r)/2;
    auto get1=get(2*id, l, mid, u, v);
    auto get2=get(2*id+1, mid+1, r, u, v);
    return mx(get1, get2);   // NOTE
}

pair<int,int> mn(pair<int,int> a, pair<int,int> b){
    vector<int> v;
    v={a.first,a.second,b.first,b.second};
    sort(v.begin(),v.end());
    return {v[0],v[1]};
}
auto buildr (int id, int l, int r) {
    if (l == r) { st[id].first = a[l]; st[id].second=n+1;  return; }
    int mid = (l + r) / 2;
    buildr(2 *id, l, mid);
    buildr(2*id+1, mid+1, r);
    st[id] = mn(st[2*id], st[2*id+1]); // NOTE
};
void updater(int id, int l, int r, int idx, int val){
    if(!(idx>=l && idx<=r)) return;
    if(l==r) {st[id].first=val; st[id].second=n+1; return;}
    int mid=(l+r)/2;
    updater(2*id, l, mid, idx, val);
    updater(2*id+1, mid+1, r, idx, val);
    st[id]=mn(st[2*id], st[2*id+1]);  // NOTE
}
pair<int,int> getr(int id, int l, int r, int u, int v){
    if(l>v || r<u) return {n+1,n+1};   // NOTE
    if(l>=u && r<=v) return st[id];
    int mid=(l+r)/2;
    auto get1=getr(2*id, l, mid, u, v);
    auto get2=getr(2*id+1, mid+1, r, u, v);
    return mn(get1, get2);   // NOTE
}
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin>>n;
    int x[n+1];
    for(int i=1; i<=n; i++) cin>>x[i];

    pair<int,int> l[n+1];
    for(int i=1; i<=n; i++) a[i]=0;
    build(1,1,n);
    for(int i=1; i<=n; i++){
        update(1,1,n,x[i],i);
        l[i] = get(1,1,n,x[i]+1,n);
    }

    pair<int,int> r[n+1];
    for(int i=n; i>0; i--) a[i]=n+1;
    buildr(1,1,n);
    for(int i=n; i>0; i--){
        updater(1,1,n,x[i],i);
        r[i] = getr(1,1,n,x[i]+1,n);
    }

    int ans=0;
    for(int i=1; i<=n; i++){
        auto [x1,y1] = l[i];
        auto [x2,y2] = r[i];
        ans+=(x1-y1)*(x2-i)*x[i];
        ans+=(i-x1)*(y2-x2)*x[i];
    }

    cout<<ans;

    return 0;
}
