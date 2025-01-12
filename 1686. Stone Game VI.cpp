class Solution {
public:
    #define f first
    #define s second

    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        return (abs(a.f+a.s)>abs(b.f+b.s));
    }

    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i]={a[i],b[i]};
        }
        sort(v.begin(),v.end(),cmp);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i%2) cnt-=v[i].s;
            else cnt+=v[i].f;
        }
        if(cnt>0) return 1;
        else if(cnt<0) return -1;
        return 0;
    }
};