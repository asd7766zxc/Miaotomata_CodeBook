// 算三元環數量 (用 degree 把無向圖轉成有向圖)
for (int x=1;x<=N;x++) {
    for (int y : G[x])vis[y] = 1;  //有向圖上對y標記
    for (int y : G[x])//直接暴力找 adj為無向圖
        for (int z : adj[y])ans += vis[z];
    for (int y : G[x])vis[y] = 0;  //取消標記
}
// 算四元環數量
bool check(int x,int z){
    return ( deg[x]==deg[z] ? x>z : deg[x]>deg[z] );
}
for (int x : arr) {
    for (int y : G[x])for(int z : adj[y]){
        if( !check(x, z) )continue;
        ans += cnt[z]; cnt[z] += 1 ;}
    for (int y : G[x])for(int z : adj[y]){
        if( !check(x, z) )continue;
        cnt[z] = 0;}
}
