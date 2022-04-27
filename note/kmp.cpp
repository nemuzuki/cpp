#include <iostream>
#include <cstring>
using namespace std;
const int N=100;
int nxt[N];
int *glob;
int *f (int **x)
{  int sa[2] = { 0, 1 };
   int loc = 3;
   glob = &loc;
   *x = &sa[0];
   return &loc;
}
int main(){
	int **x=new int *;
	cout<<f(x);
}
