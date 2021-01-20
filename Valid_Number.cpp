class Solution {
public:
    bool isNum(char ch)
    {
        if(ch>='0'&&ch<='9')
            return true;
        return false;
    }
    bool isDot(string s,int index,int stop)
    {
        if(index+1<=stop&&(!isNum(s[index+1])&&s[index+1]!='e'))
            return false;
        return true;
    }
    bool isNegPos(string s,int index)
    {
        if((index+1>=s.length()||!isNum(s[index+1]))||(index-1>=0&&s[index-1]!=' '&&s[index-1]!='e'))
            return false;
        return true;
    }
    bool isExp(string s,int index)
    {
        if(index+1>=s.length()||index-1<0||(!isNum(s[index-1])&&s[index-1]!='.')||(!isNum(s[index+1])&&s[index+1]!='-'&&s[index+1]!='+'))
            return false;
        return true;
    }
    
    
    bool isValid(string s,int index,int stop)
    {
        if(index>stop)
            return true;
        if(s[index]==' ')
            return false;
        if((s[index]=='-'||s[index]=='+')&&!isNegPos(s,index))
            return false;
        if((s[index]=='.')&&!isDot(s,index,stop))
            return false;
        if((s[index]=='e')&&!isExp(s,index))
            return false;
        if(s[index]=='e'||s[index]=='+'||s[index]=='-'||s[index]=='.'||isNum(s[index]))
        return isValid(s,index+1,stop);
    else
            return false;
        
        
    }
    bool isNumber(string s) {
        int ct=0;
        int ex=0;
        int nums=0;
        int dot=0;
        for(int i=0;i<s.length();i++)
        {
            ct=i;
            if(s[i]=='.'&&i+1<s.length()&&!isNum(s[i+1]))
                return false;
            if(s[i]=='-'||s[i]=='+')
                ct++;
            if(s[i]!=' ')
                break;
        }
        for(int i=0;i<s.length();i++)
        {
            if(isNum(s[i]))
                nums++;
            if(s[i]=='e')
                ex++;
            if(s[i]=='.'&&ex!=0)
            {
                return false;
        }
            else if(s[i]=='.')
                dot++;
        }
        if(nums==0)
            return false;
        int stop=s.length()-1;
        for(int i=s.length()-1;i>=0;i--)
        {
            stop=i;
            if(s[i]!=' ')
            break;
            
    }
        if(ex>1||dot>1)
            return false;
        if(ct>stop)
            return false;
        return isValid(s,ct,stop);
    }
};
