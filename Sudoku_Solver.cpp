class Solution {
public:
    unordered_map<int,unordered_map<char,int>> mp1;
    unordered_map<int,unordered_map<char,int>> mp2;
    unordered_map<int,unordered_map<char,int>> mp3;
    vector<vector<char>> res;
    int indexBoard(int r,int c)
    {
        if(r/3==0)
        {
            return c/3;
        }
        else if(r/3==1)
        {
            return 3+c/3;
        }
        else
        {
            return 6+c/3;
        }
        
    }
    bool isFilled(vector<vector<char>> board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='.')
                    return false;
            }
        }
        return true;
    }
    void traverse(vector<vector<char>>& board,int r,int c)
    {
        
     //cout<<r<<" ";   
        if(r==8&&c==9)
        {
            for(int i=0;i<board.size();i++)
            {
                for(int j=0;j<board[i].size();j++)
                {
                    res[i][j]=board[i][j];
                }
            }
            
            return;
        }
        
    if(c==9)
    {
        r++;
     c=0;
    }
        int i=r,j=c;
 
                if(board[i][j]=='.')
                {
                    for(int k=0;k<9;k++)
                    {
                       if(mp1[i].find(k+'1')==mp1[i].end()&&mp2[j].find(k+'1')==mp2[j].end()&&mp3[indexBoard(i,j)].find(k+'1')==mp3[indexBoard(i,j)].end())
                        {
                            board[i][j]=k+'1';
                           mp3[indexBoard(i,j)][board[i][j]]=1;
                           mp1[i][board[i][j]]=1;
                           mp2[j][board[i][j]]=1;
                            traverse(board,i,j+1);
                           mp3[indexBoard(i,j)].erase(board[i][j]);
                           mp1[i].erase(board[i][j]);
                           mp2[j].erase(board[i][j]);
                            board[i][j]='.';
                        }
                        
                    }
                
            
            
        }
        else
        {
                                        traverse(board,i,j+1);
        }
        
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            res.push_back(board[i]);
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]!='.')
                {
                    mp1[i][board[i][j]]=1;
                    mp2[j][board[i][j]]=1; 
                    mp3[indexBoard(i,j)][board[i][j]]=1;
                }
            }
        }
        traverse(board,0,0);
        for(int i=0;i<res.size();i++)
            {
                for(int j=0;j<res[i].size();j++)
                {
                    board[i][j]=res[i][j];
                }
            }
        
    }
};
