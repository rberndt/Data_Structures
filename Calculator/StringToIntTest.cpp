#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s1 = "aaaa";
  string s2 = "aaab";
  string s3 = "aaba";
  string s4 = "aabb";
  string s5 = "abaa";
  string s6 = "abab";
  string s7 = "abba";
  string s8 = "abbb";
  string s9 = "baaa";
  string s10 = "baab";
  string s11 = "baba";
  string s12 = "babb";
  string s13 = "bbaa";
  string s14 = "bbab";
  string s15 = "bbba";
  string s16 = "bbbb";
   
  unsigned int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, 
      sum5 = 0, sum6 = 0, sum7 = 0, sum8 = 0, 
      sum9 = 0, sum10 = 0, sum11 = 0, sum12 = 0, 
      sum13 = 0, sum14 = 0, sum15 = 0, sum16 = 0;
  unsigned int a = 378551;
  unsigned int b = 63689;
 
  for(int i = 0; i < 4; i++)
  {
    sum1 = sum1 * a + int( s1.at(i) );
    sum2 = sum2 * a + int( s2.at(i) );
    sum3 = sum3 * a + int( s3.at(i) );
    sum4 = sum4 * a + int( s4.at(i) );
    sum5 = sum5 * a + int( s5.at(i) );
    sum6 = sum6 * a + int( s6.at(i) );
    sum7 = sum7 * a + int( s7.at(i) );
    sum8 = sum8 * a + int( s8.at(i) );
    sum9 = sum9 * a + int( s9.at(i) );
    sum10 = sum10 * a + int( s10.at(i) );
    sum11 = sum11 * a + int( s11.at(i) );
    sum12 = sum12 * a + int( s12.at(i) );
    sum13 = sum13 * a + int( s13.at(i) );
    sum14 = sum14 * a + int( s14.at(i) );
    sum15 = sum15 * a + int( s15.at(i) );
    sum16 = sum16 * a + int( s16.at(i) );
    a = a * b;
    sum1 = sum1 % 101;
    sum2 = sum2 % 101;
    sum3 = sum3 % 101;
    sum4 = sum4 % 101;
    sum5 = sum5 % 101;
    sum6 = sum6 % 101;
    sum7 = sum7 % 101;
    sum8 = sum8 % 101;
    sum9 = sum9 % 101;
    sum10 = sum10 % 101;
    sum11 = sum11 % 101;
    sum12 = sum12 % 101;
    sum13 = sum13 % 101;
    sum14 = sum14 % 101;
    sum15 = sum15 % 101;
    sum16 = sum16 % 101;
  }

  cout << sum1 << endl;
  cout << sum2 << endl;
  cout << sum3 << endl;
  cout << sum4 << endl;
  cout << sum5 << endl;
  cout << sum6 << endl;
  cout << sum7 << endl;
  cout << sum8 << endl;
  cout << sum9 << endl;
  cout << sum10 << endl;
  cout << sum11 << endl;
  cout << sum12 << endl;
  cout << sum13 << endl;
  cout << sum14 << endl;
  cout << sum15 << endl;
  cout << sum16 << endl;

return 0;
}
