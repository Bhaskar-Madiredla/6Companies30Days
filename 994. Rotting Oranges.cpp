class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        //{{i,j},t}
        int cnt=0,cntfrh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1) cnt++;
            }
        }

        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};
        int tm=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && !vis[nr][nc]){
                    tm=max(t+1,tm);
                    q.push({{nr,nc},t+1});
                    cntfrh++;
                    vis[nr][nc]=1;
                }
            }
        }
        return (cnt==cntfrh)?tm:-1;
    }
};