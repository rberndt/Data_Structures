#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <unordered_map>
using namespace std;

int quit = 0;
int error = 0;
unordered_map<string, double> um;

template<class T>
class arrayStack
{
public:
arrayStack(int initialCapacity = 10);
bool empty();
int size();
T& top();
void pop();
void push(const T& theElement);
private:
int stackTop;    //current top of stack
int arrayLength; //stack capacity
T *stack;        //element array
};

template<class T>
arrayStack<T>::arrayStack(int initialCapacity)
{
if(initialCapacity < 1)
{
//  cout << "Error: Initial Capacity less than one" << endl;
}
else
{
  arrayLength = initialCapacity;
  stack = new T[arrayLength];
  stackTop = -1;
}
}

template<class T>
bool arrayStack<T>::empty()
{
if(stackTop == -1)
{
  return true;
}
else
{
  return false;
}
}

template<class T>
int arrayStack<T>::size()
{
return stackTop + 1;
}

template<class T>
T& arrayStack<T>::top()
{
if(!empty())
{
  return stack[stackTop];
}
else
{
//  cout << "Error: Return top with empty stack" << endl;
}
}

template<class T>
void arrayStack<T>::push(const T& theElement)
{
if(stackTop == arrayLength - 1)
{//code to double capacity
  arrayLength = arrayLength * 2;
  T temp[arrayLength]; 
  for(int i = 0; i < (arrayLength/2)-1; i++)
  {
    temp[i] = stack[i];
  }
  stack = temp;
}
//add at stack top
stack[++stackTop] = theElement;
}

template<class T>
void arrayStack<T>::pop()
{
if(stackTop == -1)
{
//  cout << "Error: Pop with Stack empty" << endl;
}
stackTop--;
}











double compute(string s)
{
arrayStack<double> num;
arrayStack<char> op;

int Ssize = s.size();

for(int i = 0; i < Ssize; i++)
{
  if(s.at(i) == ' ') //space
  {
    //continue;
  }
  else if(s.substr(i, 4) == "quit") //quit
  {
    error = 1;
    quit = 1;
    break;
  }
  else if(s.substr(i, 3) == "let") //variable declaration
  {
    string var = "";
    i += 4;
    while( s.at(i) != ' ' )
    {
      var.append(s.substr(i, 1));
      i++;
    }
    while( s.at(i) == ' ' || s.at(i) == '=' )
    {
      i++;
    }
//cout << "|" << s.substr(i, Ssize-i) << "|" << endl;
    double varNum = compute(s.substr(i, Ssize-i));
//cout << var << " " << varNum << endl;
    error = 1;
    um[var] = varNum;
    return 0;
  }
  else if( s.at(i) == '(' ) //open parenthesis
  {
    op.push('(');
  }
  else if( s.at(i) == ')' )
  {
    while( op.top() != '(' )
    {
      if( !(num.empty()) )
      {
        double b = num.top();
        num.pop();
        if( !(num.empty()) )
        {
          double a = num.top();
          num.pop();
          char opr = op.top();
          op.pop();
//cout << a << opr << b << endl;
          if(opr == '+')
          {
            num.push( a+b );
          }
          else if(opr == '-')
          {
            num.push( a-b );
          }
          else if(opr == '*')
          {
            num.push( a*b );
          }
          else if(opr == '/')
          {
            if( b != 0 )
            {
              num.push( a/b );
            }
            else
            {
              error = 1;
              cout << "Division-By-Zero" << endl;
              break;
            }
          }
          else
          {
            num.push( pow(a,b) );
          }
        }
        else
        {
          num.push( b ); //only single number in parenthesis
        }
      }
      else
      {
//cout << "Error: Num stack empty in parenthesis, returning 0" << endl;
      return 0;
      }     
    }
    op.pop();
  }
  else if(s.at(i) == '0' || s.at(i) == '1' || s.at(i) == '2' || 
          s.at(i) == '3' || s.at(i) == '4' || s.at(i) == '5' ||
          s.at(i) == '6' || s.at(i) == '7' || s.at(i) == '8' ||
          s.at(i) == '9') //numbers
  {
    string str = "";
    stringstream ss;
    double n = 0.0;
    while(s.at(i) == '0' || s.at(i) == '1' || s.at(i) == '2' || 
          s.at(i) == '3' || s.at(i) == '4' || s.at(i) == '5' ||
          s.at(i) == '6' || s.at(i) == '7' || s.at(i) == '8' ||
          s.at(i) == '9' || s.at(i) == '.')
    {
      str.append( s.substr(i, 1) );
      if( i < Ssize-1 )
      {
        i++;
      }
      else
      {
        break;
      }
    } 
    ss << str;
    ss >> n;
//cout <<  n << endl;
    num.push( n );
    if( i < Ssize-1 )
    {
      i--;
    }
  }
  else if(s.at(i) == '+') //addition
  {
//cout << "+" << endl;
    if( op.empty() || op.top() == '(' )
    {
      op.push('+');
    }
    else
    {
      double b = num.top();
      num.pop();
      double a = num.top();
      num.pop();
      char opr = op.top();
      op.pop();
//cout << a << opr << b << endl;
      if(opr == '+')
      {
        num.push( a+b );
      }
      else if(opr == '-')
      {
        num.push( a-b );
      }
      else if(opr == '*')
      {
        num.push( a*b );
      }
      else if(opr == '/')
      {
        if( b != 0 )
        {
          num.push( a/b );
        }
        else
        {
          error = 1;
          cout << "Division-By-Zero" << endl;
          break;
        }
      }
      else
      {
        num.push( pow(a,b) );
      }
      op.push('+');
    }
  }
  else if(s.at(i) == '-') //subtraction
  {
    if( op.empty() || op.top() == '(' )
    {
      op.push('-');
    }
    else
    {
      double b = num.top();
      num.pop();
      double a = num.top();
      num.pop();
      char opr = op.top();
      op.pop();
      if(opr == '+')
      {
        num.push( a+b );
      }
      else if(opr == '-')
      {
        num.push( a-b );
      }
      else if(opr == '*')
      {
        num.push( a*b );
      }
      else if(opr == '/')
      {
        if( b != 0 )
        {
          num.push( a/b );
        }
        else
        {
          error = 1;
          cout << "Division-By-Zero" << endl;
          break;
        }
      }
      else
      {
        num.push( pow(a,b) );
      }
      op.push('-');
    }
  }
  else if(s.at(i) == '*') //multiplication
  {
//cout << "*" << endl;
    if( op.empty() || op.top() == '(' )
    {
      op.push('*');
    }
    else if( op.top() == '+' || op.top() == '-')
    {
      op.push('*');
    }
    else if( op.top() == '^' )
    {
      double b = num.top();
      num.pop();
      double a = num.top();
      num.pop();
      char opr = op.top();
      op.pop();
      num.push( pow(a,b) );
      op.push('*'); 
    }
    else
    {
      double b = num.top();
      num.pop();
      double a = num.top();
      num.pop();
      char opr = op.top();
      op.pop();
      if(opr == '*')
      {
        num.push( a*b );
      }
      if(opr == '/')
      {
        if( b != 0 )
        {
          num.push( a/b );
        }
        else
        {
          error = 1;
          cout << "Division-By-Zero" << endl;
          break;
        }
      }
      op.push('*');
    }
  }
  else if(s.at(i) == '/') //division
  {
    if( op.empty() || op.top() == '(' )
    {
      op.push('/');
    }
    else if( op.top() == '+' || op.top() == '-')
    {
      op.push('/');
    }
    else if( op.top() == '^' )
    {
      double b = num.top();
      num.pop();
      double a = num.top();
      num.pop();
      char opr = op.top();
      op.pop();
      num.push( pow(a,b) );
      op.push('/'); 
    }
    else
    {
      double b = num.top();
      num.pop();
      double a = num.top();
      num.pop();
      char opr = op.top();
      op.pop();
      if(opr == '*')
      {
        num.push( a*b );
      }
      if(opr == '/')
      {
        if( b != 0 )
        {
          num.push( a/b );
        }
        else
        {
          error = 1;
          cout << "Division-By-Zero" << endl;
          break;
        }
      }
      op.push('/');
    }
  }
  else if(s.at(i) == '^') //exponent
  {
//cout << "^" << endl;
    op.push('^');
  }
  else //variable reference
  {
    string var2 = "";
    while( s.at(i) != ' ' && s.at(i) != '+' && s.at(i) != '-' && 
           s.at(i) != '*' && s.at(i) != '/' && s.at(i) != '^' )
    {
      var2.append( s.substr(i, 1) );
      if( i < Ssize-1 )
      {
        i++;
      }
      else
      {
        var2.append( s.substr(i+1,1) );
        break;
      }
    }
    if( s.at(i) == '+' )
    {
//cout << '+' << endl;
      op.push( '+' );
    }
    if( s.at(i) == '-' )
    {
      op.push( '-' );
    }
    if( s.at(i) == '*' )
    {
      op.push( '*' );
    }
    if( s.at(i) == '/' )
    {
      op.push( '/' );
    }
    if( s.at(i) == '^' )
    {
      op.push( '^' );
    }
//cout << var2 << endl;
    if( um.count(var2) > 0 )
    {
//cout << um[var2] << endl;
      num.push( um[var2] );
    }
    else
    {
      error = 1;
      cout << "Undeclared-Variable" << endl;
      num.push( 1 );
    }
  }
}

//cout << "made it here" << endl;

//compute final calculation here
while( !(op.empty()) )
{
if(op.top() == '(')
{
  op.pop();
}
else
{
  if( !(num.empty()) )
  {
    double b = num.top();
    num.pop();
    if( !(num.empty()) )
    {
      double a = num.top();
      num.pop();
      char opr = op.top();
      op.pop();
//cout << a << opr << b << endl;
        if(opr == '+')
        {
          num.push( a+b );
        }
        else if(opr == '-')
        {
          num.push( a-b );
        }
        else if(opr == '*')
        {
          num.push( a*b );
        }
        else if(opr == '/')
        {
          if( b != 0 )
          {
            num.push( a/b );
          }
          else
          {
            error = 1;
            cout << "Division-By-Zero" << endl;
            break;
          }
        }
        else
        {
          num.push( pow(a,b) );
        }
    }
    else
    {
      num.push( b ); 
    }
  }
  else
  {
  //cout << "Error: Num stack empty, Op stack not empty, returning 0" << endl;
    return 0;
  }
}
}

double ans;
if( error == 1 || quit == 1 )
{
ans = 0;
}
else
{
ans = num.top();
num.pop();
}

if( !(num.empty()) )
{
  //cout << "Error: Num Stack not empty, returning 0" << endl;
  return 0;
}
else if( !(op.empty()) )
{
  //cout << "Error: Op Stack not empty, returning 0" << endl;
  return 0;
}
else
{
  return ans;
}
}











int main()
{

while(quit == 0)
{
  error = 0;
  string input = "";
  getline(cin, input);
  double answer = compute(input);
  if(error == 0)
  {
    cout << answer << endl;
  }
}

return 0;
}
