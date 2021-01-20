class Solution {
public:
    bool isMatch(string s, string p) {
        bool T[s.length()+1][p.length()+1];
        T[0][0]=true;
        for(int i=1;i<=p.length();i++)
        {
            if(p[i-1]=='*')
            {
                if(i>1)
                T[0][i]=T[0][i-2];
                else
                    T[0][i]=true;
            }
            else
            T[0][i]=false;
        }
        for(int i=1;i<=s.length();i++)
        {
            T[i][0]=false;
        }
        for(int i=1;i<=s.length();i++)
        {
            for(int j=1;j<=p.length();j++)
            {
                if(s[i-1]==p[j-1]||p[j-1]=='.')
                {
                    T[i][j]=T[i-1][j-1];
                }
                else
                {
                    T[i][j]=false;
                    if(p[j-1]=='*')
                    {
                        if(j==1)
                        {
                            T[i][j]=false;
                        }
                        else if(p[j-2]=='.')
                        {
                            T[i][j]=T[i][j-2]||T[i-1][j];
                        }
                        else
                        {
                            T[i][j]=T[i][j-2]||(s[i-1]==p[j-2]&&T[i-1][j]);
                        }
                    }
                    
                }
            }
        }
        return T[s.length()][p.length()];
    }
};
