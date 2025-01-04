class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& ed, int dis) {
        vector<vector<int>> mat(n,vector<int>(n,1e4+1));
        for(int i=0;i<n;i++) mat[i][i]=0;
        for(auto x:ed){
            mat[x[0]][x[1]]=x[2];
            mat[x[1]][x[0]]=x[2];
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }

        int mn=-1,no=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]<=dis) cnt++;
            }
            if(cnt<no){
                no=cnt;
                mn=i;
            }
            else if(cnt==no){
                mn=max(mn,i);
            }
        }
        return mn;
    }
};