class Solution {
public:
    bool allzero(vector<int>& counter){
            for(auto it: counter){
                if(it!=0)
                    return false;
            }
            return true;
        }
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int k=p.size();
        if(k>n)
            return {};
        vector<int>counter(26,0);
        for(char ch:p){
            counter[ch-'a']++;
        }
        int i=0,j=0;
        vector<int>res;
        
        
        while(j<n){
            counter[s[j]-'a']--;
            if(j-i+1==k){
                if(allzero(counter)){
                    res.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return res;
    }
};