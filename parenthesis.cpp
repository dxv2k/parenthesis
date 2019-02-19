#include <iostream>
#include <cstring>
using namespace std;

// This program will check the expression of parenthesis,
// which also includes curly braces and brackets, find out
// if it's syntactically correct or not
// () [] {}
// RETURN TRUE OR FALSE

//----------------STACK-------------------------------
// Declare global variables
int stack[15], index;

void push(int num) // push elements into the stack
{
    index++;
    stack[index] = num;
}
void pop()   // delete elements from the stack
{
    stack[index] = 0;
    index--;
}
int top()   // return the top element
{
    return stack[index];
}
bool isEmpty()  // check if the stack is empty
{
    if (index == 0)
            return true;
    return false;
}
//-----------------END OF STACK---------------

char s[15];

bool verify (char s[])
{
    for (int i=0;i<strlen(s);i++)
    {
       if (s[i] == '(') push(1);
       if (s[i] == '[') push(2);
       if (s[i] == '{') push(3);

       if (s[i] == ')')
       {
            if (isEmpty() || stack[index] != 1)
                                return false;
            else
            {
                stack[index] = 0;
                index--;
            }
       }
       if (s[i] == ']')
       {
            if (isEmpty() || stack[index] != 1)
                                return false;
            else
            {
                stack[index] = 0;
                index--;
            }
       }
       if (s[i] == '}')
       {
            if (isEmpty() || stack[index] != 1)
                                return false;
            else
            {
                stack[index] = 0;
                index--;
            }
       }
    }
    if (index == 0) return true;
    else
         return false;

}
int main()
{
    index = 0;
    cin.getline(s,15);
    cout << verify(s);
    return 0;
}
