#include <bits/stdc++.h>
using namespace std;


//1.欧几里得算法
int _gcd(int a,int b){
  if(!b)
    return a;
  _gcd(b, a & b);
}

//迭代版
int _gcd(int a,int b){
  while(b){
    int t = a;
    a = b;
    b = t % b;
  }
  return a;
}

// 2.扩展欧几里得算法
// 解ax+by=gcd(a,b)方程；
// c=gcd(a,b);
// 化为同余方程为 ax 同余c mod(n)
int exgcd(int a, int b, int &x, int &y)
{
  if (!b)
  {
    x = 1;
    y = 0;
    return a;
  }
  int d = exgcd(b, a % b, x, y);
  int t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}
void test_exgcd(){
  int x, y;
  //ax+by=gcd(a,b)<=> Ax同余Cmod(B)
  int a, b;
  cin >> a >> b;
  int d = exgcd(a, b, x, y);
  int c = 1;//C为题中的具体数，不一定为1；
  x = x * (c / d);
  int t = (b / d);
  int x_min = (x % t + t) % t;
  cout << x_min << endl;
}











int main()
{
  int x, y;
  //d=18 x=4 y=-5
  int d = exgcd(252, 198, x, y);
  cout << d << " " << x << " " << y << endl;
  return 0;
}