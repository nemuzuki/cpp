#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stack>
#include <windows.h>
#include <queue>
#include <time.h>
using namespace std;

int file_size(char* filename){	
	FILE *fp = fopen(filename, "rb");//��zhi�ļ���
	int size;
	if(fp == NULL) // ���ļ�ʧ��
		return -1;
	fseek(fp, 0, SEEK_END);//��λ�ļ�ָ�뵽�ļ�β��
	size=ftell(fp);//��ȡ�ļ�ָ��ƫ��������dao�ļ���С��
	fclose(fp);//�ر��ļ���
	return size;
}
void sender(char *source,char* end){
	int size=0;
	size=file_size(source);
	printf("size:%d\n",size);
	
	FILE * pFile,*qw;
	char *buffer=(char*)malloc(sizeof(char)*size);
	qw=fopen(source,"r");
	pFile = fopen ( end , "wb" );
	fread(buffer,1,size,qw);
	fwrite (buffer , sizeof(byte), size , pFile );
	fclose (pFile);
	
}

//	sender("C:/Users/Mika/Desktop/���������/����ҵ3/����1�����ļ�/2.jpg",
//	"C:/Users/Mika/Desktop/���������/����ҵ3/���յ����ļ�/2.jpg");
int a(){
	return 2;
} 

int main() {
}
