#include<vector>
#include<iostream>
#include<map>
//#include<unordered_map>
using namespace std;
int main(){
	map<int,int>m;
//	unordered_map<int,int>u;
	m[1]=2;
//	u[2]=3; 
typedef map<int,int>M;
	for(M::iterator i=m.begin();i<m.end();++i){
		cout<<i.first;
	}
} 
enum DAY{
      MON, TUE, WED, THU, FRI, SAT, SUN
	};
	enum DAY day=THU;
	cout<<day;
  output:3