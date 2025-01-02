class Solution {
public:
    int n;
    int f(int i,string s,string x,string y){
        if(i==n){
            int m=x.length();
            for(int j=0;j<m/2;j++){
                if(x[j]!=x[m-1-j]) return 0;
            }
            m=y.length();
            for(int j=0;j<m/2;j++){
                if(y[j]!=y[m-1-j]) return 0;
            }
            return x.length()*y.length();
        }
        int mx=f(i+1,s,x,y);
        mx=max(mx,f(i+1,s,x+s[i],y));
        mx=max(mx,f(i+1,s,x,y+s[i]));
        return mx;
    }

    int maxProduct(string s) {
        n=s.length();
        return f(0,s,"","");
    }
};