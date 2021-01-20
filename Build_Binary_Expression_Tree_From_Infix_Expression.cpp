/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    Node* expTree(string s) {
        unordered_map<char,int> p;
        p['+']=1;
        p['-']=1;
        p['*']=2;
        p['/']=2;
        p['(']=0;
        stack<char> operators;
        stack<Node*> operands;
        operators.push('(');
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                Node* temp=new Node(s[i],NULL,NULL);
                operands.push(temp);
            }
            else if(s[i]==')')
            {
                Node* curr=operands.top();
                operands.pop();
                while(p[operators.top()]!=0)
                {
                    Node* temp=new Node(operators.top(),operands.top(),curr);
                    curr=temp;
                    operators.pop();
                    operands.pop();
                }
                operands.push(curr);
                operators.pop();
            }
            else if(s[i]=='(')
            {
                operators.push('(');
            }
            else
            {
                Node* curr=operands.top();
                operands.pop();
                while(p[s[i]]<p[operators.top()])
                {
                    Node* temp=new Node(operators.top(),operands.top(),curr);
                    curr=temp;
                    operators.pop();
                    operands.pop();
                }
                
                operands.push(curr);
                operators.push(s[i]);
            }
        }
                Node* curr=operands.top();
                operands.pop();
                while(p[operators.top()]!=0)
                {
                    Node* temp=new Node(operators.top(),operands.top(),curr);
                    curr=temp;
                    operators.pop();
                    operands.pop();
                }
                
        return curr;
    }
};
