class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())
            return false;
        bool T[s1.length()+1][s2.length()+1];
        T[0][0]=1;
        for(int i=1;i<=s1.length();i++)
        {
            if(s1[i-1]==s3[i-1])
                T[i][0]=T[i-1][0];
            else
                T[i][0]=0;
        }
        for(int i=1;i<=s2.length();i++)
        {
            if(s2[i-1]==s3[i-1])
                T[0][i]=T[0][i-1];
            else
                T[0][i]=0;
        }
        for(int i=1;i<=s1.length();i++)
        {
            for(int j=1;j<=s2.length();j++)
            {
                T[i][j]=0;
                if(s1[i-1]==s3[i+j-1])
                {
                    T[i][j]=T[i-1][j];
                }
                if(s2[j-1]==s3[i+j-1])
                {
                    T[i][j]=T[i][j]||T[i][j-1];
                }
            }
        }
        return T[s1.length()][s2.length()];
    }
};
