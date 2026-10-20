class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // stack<int>st;
        vector<int>st;
        for(int &a: asteroids){
            //st.top --> st.back()
            // st.pop ---> st.pop_back()
            while(!st.empty() && a<0 && st.back()>0){
                int sum =a+st.back();
                if(sum>0){
                    a=0;
                }else if(sum<0){
                    st.pop_back();
                }else{
                    st.pop_back();
                    a=0;
                }
            }
            if(a!=0){
                st.push_back(a);
            }
        }
        return st;

            // int s = st.size();
            // vector<int>res(s);
            // int i=s-1;
            // while(!st.empty()){
            //     res[i]=st.top();
            //     st.pop();
            //     i--;
            // }
            // return res;
        }
};