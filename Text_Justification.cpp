class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        queue<string> q;
        int sum=0;
        vector<string> v;
        for(int i=0;i<words.size();i++)
        {
            if(q.size()+sum+words[i].length()<=maxWidth)
            {
                q.push(words[i]);
            }
            else
            {
                int num=0;
                int sp=maxWidth-sum;
                if(q.size()-1>0)
                num=sp/(q.size()-1);
                int p=sp-(q.size()-1)*num;
                string s="";
                while(!q.empty())
                {
                    s=s+q.front();
                    if(sp>0)
                    {
                    for(int j=0;j<num;j++)
                    {
                        s=s+" ";
                    }
                    }
                    if(p>0)
                    {
                        s=s+" ";
                        p--;
                        sp--;
                    }
                    sp=sp-num;
                    q.pop();
                }
                for(int j=0;j<p;j++)
                    s=s+" ";
                v.push_back(s);
                sum=0;
                q.push(words[i]);
            }
            sum+=words[i].length();
        }
      string s="";
        while(!q.empty())
        {
            s=s+" "+q.front();
            q.pop();
        }
        s=s.substr(1);int num=maxWidth-s.length();
        for(int i=0;i<num;i++)
        {
            s=s+" ";
        }
        v.push_back(s);
        return v;
    }
};
