#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
using namespace std;
//��׺���ʽת��׺���ʽ
void printPostfixExpression(char *exp,int n){
	map<char,int>priority;
	priority['+']=priority['-']=1;
	priority['*']=priority['/']=2;
	priority['(']=3;
	stack<char>signStack;
	queue<char>postQueue;
	for(int i=0;i<n;++i){
		if(exp[i]=='('){//������ֱ�ӽ�ջ
			signStack.push(exp[i]);
		}
		else if(exp[i]==')'){//���������ţ��������ź����ȫ��������������ֱ��pop��
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
				if(priority[exp[i]]>priority[t]){//��ǰ���ȼ�����ջ����ֱ�ӽ�ջ
					signStack.push(exp[i]);
				}
				else{//��ǰ���ȼ�<=ջ��
					while(!signStack.empty()){//ֻҪ��ǰ���ȼ�<=ջ����һֱ��ջ��ֱ������������
						t=signStack.top();
						if(priority[exp[i]]>priority[t]||t=='(')break;
						signStack.pop();
						postQueue.push(t);
					}
					signStack.push(exp[i]);
				}
			}
		}
		else{//����
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