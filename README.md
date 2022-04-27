#### vector

```cpp
vector<int>res(n,0);//初始化长度为n，全为0

vector<vector<bool>>visit(m,vector<bool>(n,false));//初始化m*n的二维数组
```



#### typedef

一般的struct定义Node对象时，其实是struct Node n1(1);

```cpp
struct Node{
    int num;
    Node *next;
    Node(int n){
        num=n;
        next=NULL;
    }
};
int main(){
    Node n1(1);//非指针，直接创建
    Node *n2=new Node(2);//指针需要指向已经new的对象
}
```

用typedef对struct node起别名Node，可以起多个别名，但它们本质是相同的结构体
在结构体内部定义结构体或写构造函数时，由于还不知道别名Node，因此还需要用node来定义

```cpp
typedef struct node{
    int num;
    node *next;
    node(int n){
        num=n;
        next=NULL;
    }
}Node;

int main(){
    Node n1(1);
    Node *n2=new Node(2);
}
```



#### virtual

虚函数实现多态，即使得基类和子类的方法分离

```cpp
#include <iostream>
using namespace std;
class Father{
	public:
    // void print(){
	// 	cout<<"Father\n";
	// }
	virtual void print(){
		cout<<"Father\n";
	}
};
class Son:public Father{
	public:
	void print(){
		cout<<"Son\n";
	}
};
int main(){
	Father *s=new Son();
	s->print();
}
```

该程序运行后输出Father。如果将Father类的print()改为`virtual void print()`，则输出Son。基类定义的虚函数，子类中自动也定义为虚函数

------

#### map

map使用红黑树来查找

c++11开始使用auto关键字，需要在编译时加上`-std=c++11`

```cpp
map<string,int>m;
for(auto i=m.begin();i!=m.end();++i){//指针遍历
    cout<<i->first<<','<<i->second<<endl;
}


for(auto &i:m){//c++11还支持range-based for循环
    cout<<i.first;
}
```

#### unordered_map

unordered_map使用哈希表来查找，c++11支持

```cpp
#include<unordered_map>
unordered_map<string,int>umap;
```



#### 二分查找

upper_bound/lower_bound

二分查找，找到vector中大于/大于等于target的物理地址

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>v;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		v.push_back(x); 
	}
	cout<<upper_bound(v.begin(),v.end(),3)-v.begin();//第一个>3的元素下标 
	cout<<lower_bound(v.begin(),v.end(),3)-v.begin();//第一个>=3的元素下标 
}
/*
5
1 2 4 5 6
*/	
```

#### 重载运算符

重载小于号，可以用于sort和priority_queue等

```cpp
struct node{
    int d,//node和集合的距离
	now;//node编号 
    bool operator<(const node &x)const {
        return d>x.d;
    }
}p;
```

#### namespace

namespace不能在主函数里面 想要使用某个namespace中的元素有三种方法：
1.直接ns::a
2.using namespace ns; 接下来都不用写空间名了
3.using ns::a; 接下来该元素不用写空间名了
想换的时候再写一遍新空间名即可

```cpp
#include<iostream> 
using namespace std;
namespace fa{
	int a=39;
}
namespace son{
	int a=23;
}
int main(){

	cout<<fa::a;
  
	using namespace son;
	cout<<a;
  
	using fa::a;
	cout<<a;
}
```

#### set

set：集合，元素默认从小到大排序

set中的元素是set::iterator类型，前面加*才能输出值

```cpp
#include <set>
for(set<int>::iterator it = s.begin(); it!= s.end(); it++){
  cout << *it << " ";
}
s.insert()
s.erase()
s.begin()
s.end()
s.clear()
s.empty()
s.size() 
```

#### enum

```cpp
enum DAY {
    MON, TUE, WED, THU, FRI, SAT, SUN
};
enum DAY day=THU;
cout<<day;
//output:3
```

#### 文件读写

```cpp
#include<fstream>
#include<iostream>
using namespace std;

//读文件
//c version
FILE *fin=fopen(path,"rb");
fseek(fin,1,0);//从0处开始算，偏移1字节处开始读取
fread(buffer,1,20,fin);//以1个字节为单位，读取20个单位，存入buffer
cout<<buffer; 
	

//c++ version
char path[]="./test.txt";//路径用正斜杠
ifstream infile;
infile.open(path);
infile.seekg(1);//从0处开始算，偏移1字节处开始读取
while(infile.eof()==false){//每次读1个字节
  infile>>buffer;
  cout<<buffer<<' ';
}


//写文件
//c version
FILE *fout=fopen(path,"wb");
fwrite(buffer,1,sizeof(buffer),fout);
```

