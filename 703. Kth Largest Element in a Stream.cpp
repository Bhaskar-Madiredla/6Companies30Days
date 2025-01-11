class KthLargest {
public:
    int n;
    multiset<int> st;
    
    KthLargest(int k,vector<int>& nums) {
        n = k;
        for (auto x : nums) {
            st.insert(x);
            if (st.size() > n) {
                st.erase(st.begin());
            }
        }
    }
    
    int add(int val) {
        st.insert(val);
        if (st.size() > n) {
            st.erase(st.begin());
        }
        return *st.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */