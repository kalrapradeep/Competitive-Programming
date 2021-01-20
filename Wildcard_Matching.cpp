class Solution {
public:
    bool isMatch(string s, string p) {
        bool T[s.length()+1][p.length()+1];
        T[0][0]=1;
        for(int i=1;i<=p.length();i++)
        {
            if(p[i-1]=='*')
            T[0][i]=1;
            else
                T[0][i]=0;
            T[0][i]=T[0][i-1]&&T[0][i];
        }
        for(int i=1;i<=s.length();i++)
        {
            T[i][0]=0;
        }
        for(int i=1;i<=s.length();i++)
        {
            for(int j=1;j<=p.length();j++)
            {
                if(p[j-1]=='?')
                {
                    T[i][j]=T[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    T[i][j]=T[i][j-1]||T[i-1][j];
                }
                else
                {
                    if(s[i-1]==p[j-1])
                    T[i][j]=T[i-1][j-1];
                    else
                        T[i][j]=0;
                }
            }
        }
        return T[s.length()][p.length()];
    }
};
