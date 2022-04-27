#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
using namespace std;
//中缀表达式转后缀表达式
void printPostfixExpression(char *exp,int n){
	map<char,int>priority;
	priority['+']=priority['-']=1;
	priority['*']=priority['/']=2;
	priority['(']=3;
	stack<char>signStack;
	queue<char>postQueue;
	for(int i=0;i<n;++i){
		if(exp[i]=='('){//左括号直接进栈
			signStack.push(exp[i]);
		}
		else if(exp[i]==')'){//遇到右括号，将左括号后面的全部弹出（左括号直接pop）
			char t;
			while(!signStack.empty()){
				t=signStack.top();
				signStack.pop();
				if(t=='('){
					break;
				}
				postQueue.push(t);
			}
		}
		else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
			if(signStack.empty()){
				signStack.push(exp[i]);
			}
			else{
				char t=signStack.top();
				if(priority[exp[i]]>priority[t]){//当前优先级大于栈顶，直接进栈
					signStack.push(exp[i]);
				}
				else{//当前优先级<=栈顶
					while(!signStack.empty()){//只要当前优先级<=栈顶，一直弹栈，直到遇到左括号
						t=signStack.top();
						if(priority[exp[i]]>priority[t]||t=='(')break;
						signStack.pop();
						postQueue.push(t);
					}
					signStack.push(exp[i]);
				}
			}
		}
		else{//数字
			postQueue.push(exp[i]);
		}
	}
	while(!signStack.empty()){
		char t=signStack.top();
		signStack.pop();
		postQueue.push(t);
	}
	while(!postQueue.empty()){
		char f=postQueue.front();
		cout<<f;
		postQueue.pop();
	}
	cout<<endl;
}
int main(){
	char exp[20];
	cin>>exp;//a/b+(c*d-e*f)/g
	printPostfixExpression(exp,strlen(exp));
}