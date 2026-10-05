class Solution {
public:
    string reverseWords(string s) {
        string w="";
        stack<string>stk;
        s+=" ";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                if(!w.empty())
                {
                stk.push(w);
                w="";
                }
            }
            else
                w=w+s[i];
        }
        string temp,result;
        while(!stk.empty())
        {
            temp=stk.top();
            stk.pop();
            result+=temp+" ";
        }
        if (!result.empty()) result.pop_back();
        return result;
    }
};

//Python code 
// class Solution(object):
//     def reverseWords(self, s):
//         """
//         :type s: str
//         :rtype: str
//         """
//         words = s.split()
//         words.reverse()
//         return " ".join(words)
//         # w = ""
//         # stack = []
//         # s+=" "
//         # for i in range(len(s)):
//         #     if s[i] == " ":
//         #         if w!="":
//         #             stack.append(w)
//         #             w=""
//         #     else:
//         #         w+=s[i]
        
//         # result=""

//         # while stack:
//         #     temp = stack.pop()
//         #     result += temp + " "
        
//         # if result!="":
//         #     return result[:-1]
//         # return s