#include "stacktype.cpp"
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    string s;
    int i = 0;
    StackType<char> s1, s2;
    getline(cin, s);
    cout << "Showing Input String: "<< s;
    cout << "\n" << endl;
    int len = s.size();
    cout << "Length of String: " << len << endl;

//    s1.Push(s[0]);
//    s2.Push(s[0]);
    //i++;
    int k = 0;

    while(len != i)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                s1.Push(s[i]);
                s2.Push(s[i]);
                k++;
            }
        else if(s[i] == ')')
        {
            if(s1.Top() == '(')
            {
                s1.Pop();
                s2.Push(s[i]);
                k++;
            }
            else
            {
                if(s1.Top() == '(')
                {
                    s2.Push(')');
                    s2.Push(s[i]);
                    k = k + 2;
                }
                else if(s1.Top() == '{')
                {
                    s2.Push('}');
                    s2.Push(s[i]);
                    k = k + 2;
                }
                else
                {
                    s2.Push(']');
                    s2.Push(s[i]);
                    k = k + 2;
                }
            }
        }
        else if(s[i] == '}')
        {
            if(s1.Top() == '{')
            {
                s1.Pop();
                s2.Push(s[i]);
                k++;
            }
            else
            {
                if(s1.Top() == '(')
                {
                    s2.Push(')');
                    s2.Push(s[i]);
                    k = k + 2;
                }
                else if(s1.Top() == '{')
                {
                    s2.Push('}');
                    s2.Push(s[i]);
                    k = k + 2;
                }
                else
                {
                    s2.Push(']');
                    s2.Push(s[i]);
                    k = k + 2;
                }
            }
        }
        else if(s[i] == ']')
        {
           if(s1.Top() == '[')
            {
                s1.Pop();
                s2.Push(s[i]);
                k++;
            }
            else
            {
                if(s1.Top() == '(')
                {
                    s2.Push(')');
                    s2.Push(s[i]);
                    k = k + 2;
                }
                else if(s1.Top() == '{')
                {
                    s2.Push('}');
                    s2.Push(s[i]);
                    k = k + 2;
                }
                else
                {
                    s2.Push(']');
                    s2.Push(s[i]);
                    k = k + 2;
                }
            }
        }
        i++;
    }
    cout << "Size of s2: " << k << endl;


    while(k != 0)
    {
        s2.Pop();
        cout << s2.Top();
        s2.Pop();
        k--;
    }

//        cout << s2.Top();
//        s2.Pop();
//        cout << s2.Top();
//        s2.Pop();
//        cout << s2.Top();
//        s2.Pop();
//        cout << s2.Top();
//        s2.Pop();
    return 0;
}
