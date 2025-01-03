class Solution {
public:
    #define f first
    #define s second
    long long minimumCost(string src, string tar, vector<char>& org, vector<char>& chag, vector<int>& cost) {
        vector<vector<pair<int,int>>> adj(26);
        vector<vector<long long>> spath(26,vector<long long>(26,1e18));
        for(int i=0;i<26;i++) spath[i][i]=0;
        
        for(int i=0;i<org.size();i++){
            adj[org[i]-'a'].push_back({chag[i]-'a',cost[i]});
        }

        for(int i=0;i<26;i++){
            vector<int> vis(26,0);
            priority_queue<pair<long long,int>> pq;
            pq.push({0,i});
            while(!pq.empty()){
                long long dis=-1*(pq.top().f);
                int node=pq.top().s;
                pq.pop();
                if(vis[node]) continue;
                vis[node]=1;
                spath[i][node]=dis;
                for(auto x:adj[node]){
                    if(!vis[x.f] && spath[i][x.f]>dis+x.s){
                        pq.push({-1*(x.s + dis),x.f});
                    }
                }
            }
        }
        long long cnt=0;
        for(int i=0;i<src.length();i++){
            if(spath[src[i]-'a'][tar[i]-'a']>=1e18) return -1;
            cnt+=spath[src[i]-'a'][tar[i]-'a'];
        }
        return cnt;
    }
};

