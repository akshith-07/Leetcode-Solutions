class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        stack<int>st;
        int n=p.size();
        vector<int>indices(n);
        iota(indices.begin(),indices.end(),0);
        sort(indices.begin(),indices.end(),[&](int i,int j)
        {
            return p[i]<p[j];
        });
        for(auto i:indices)
        {
            // cout<<i<<endl;
            if(d[i]=='R'){
                st.push(i);
            }
            else{
                while(st.size()>0 and h[i]>0)
                {
                    if(h[i]>h[st.top()])
                    {
                        h[st.top()]=0;
                        h[i]-=1;
                        st.pop();
                    }
                    else if(h[i]==h[st.top()]){
                        // cout<<st.top()<<endl;
                        h[st.top()]=0;
                        h[i]=0;
                        st.pop();
                    }
                    else{
                        h[i]=0;
                        h[st.top()]-=1;
                    }
                }
            }
        }
        vector<int>ans;
        for(auto &x:h)
        {
            if(x>0){
                ans.push_back(x);
            }
        }
        return ans;
    }
};