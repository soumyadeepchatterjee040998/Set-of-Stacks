#include <iostream>
#include<vector>
#include<stack>
using namespace std;
class setofstack
{
    private:
        vector<stack<int> > vect_of_stacks;
        stack<int> temp_stack;
        int capacity = 5;
    public:
        void push(int x);
        int pop();
        int popAt(int index);
        void print_();
};
void setofstack::push(int x)
{
    temp_stack.push(x);
    if(temp_stack.size()==capacity)
    {
        vect_of_stacks.push_back(temp_stack);
        while(!temp_stack.empty())
            temp_stack.pop();
    }
}
int setofstack::pop()
{
    if(vect_of_stacks.size()!=0 || !temp_stack.empty())
    {
        if(!temp_stack.empty())
        {
            int temp = temp_stack.top();
            temp_stack.pop();
            if(temp_stack.empty() && vect_of_stacks.size()!=0)
            {
                temp_stack = *vect_of_stacks.rbegin();
                vect_of_stacks.pop_back();
            }
            return temp;
        }
        else
        {
            temp_stack = *vect_of_stacks.rbegin();
            vect_of_stacks.pop_back();
            if(!temp_stack.empty())
            {
                int temp = temp_stack.top();
                temp_stack.pop();
                return temp;
            }
            else
                return -1;
        }
    }
    else
        return -1;
}
int setofstack::popAt(int index)
{
    if(index<vect_of_stacks.size())
    {
        if(!vect_of_stacks[index].empty())
        {
            int temp = vect_of_stacks[index].top();
            vect_of_stacks[index].pop();
            return temp;
        }
        else
            return -1;
    }
    else if(index == vect_of_stacks.size())
        if(!temp_stack.empty())
            return pop();
        else
            return -1;
    else
        return -1;

}
void setofstack::print_()
{
    for(stack<int> s: vect_of_stacks)
	{
	    stack<int> temp__;
	    while(!s.empty())
	    {
	        cout<<s.top()<<" ";
	        temp__.push(s.top());
	        s.pop();
	    }
        cout<<endl;
	    while(!temp__.empty())
	    {
	        s.push(temp__.top());
	        temp__.pop();
	    }
	}
    stack<int> temp__;
    while(!temp_stack.empty())
    {
        cout<<temp_stack.top()<<" ";
        temp__.push(temp_stack.top());
        temp_stack.pop();
    }
    cout<<endl;
    while(!temp__.empty())
    {
            temp_stack.push(temp__.top());
            temp__.pop();
    }
}

int main() 
{
	setofstack obj;
	int count = 35;
	while(count--)
	{
	    int n;
	    cout<<"Enter n ";
	    cin>>n;
	    cout<<endl;
	    if(n==1)//push
	    {
	        int val;
	        cout<<"Enter the value to be inserted ";
	        cin>>val;
	        cout<<endl;
	        obj.push(val);
	        obj.print_();
	    }
	    else if(n==2)//pop
	    {
	        cout<<"The value that is to be deleted "<<obj.pop()<<endl;
	    }
	    else//popAt
	    {
	        int ind;
	        cout<<"Enter the index position of the stack ";
	        cin>>ind;
	        cout<<endl;
	        cout<<"The value to be deleted is "<<obj.popAt(ind)<<endl;
	    }
	}
	return 0;
}