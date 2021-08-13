class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int ns=s.length();
        int nt=t.length();
        
        int is=0, it=0;
        
        while(is!=ns && it!=nt)
        {
            if(s[is]==t[it])
            {
                is++;
                it++;
            }
            else
            {
                it++;
            }
        }
        
        if(is==ns)
            return true;
        else
            return false;
    }
};