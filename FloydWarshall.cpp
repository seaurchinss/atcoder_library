vector<vector<ll>> FloydWarshallAlgorithm(vector<vector<ll>> dist,int v){
    for(int k=0;k<v;++k){
        for(int i=0;i<v;++i){
            for(int j=0;j<v;++j){
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }
    return dist;
}
