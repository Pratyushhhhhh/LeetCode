class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0,j=0,vc=0, mvc=0;
        int n= s.size();
        string v = "aeiou";
        while(j<n){
            if(j-i+1<=k){
                if(v.find(s[j])!=-1)
                    vc++;
            }
            if(j-i+1==k){
                mvc = max(mvc,vc);
                if(v.find(s[i])!=-1)
                    vc--;
                i++;
            }
            j++;
        }
        return mvc;
    }
};