#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stack>
#include <windows.h>
#include <queue>
#include <time.h>
using namespace std;

int file_size(char* filename){	
	FILE *fp = fopen(filename, "rb");//打开zhi文件。
	int size;
	if(fp == NULL) // 打开文件失败
		return -1;
	fseek(fp, 0, SEEK_END);//定位文件指针到文件尾。
	size=ftell(fp);//获取文件指针偏移量，即dao文件大小。
	fclose(fp);//关闭文件。
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

//	sender("C:/Users/Mika/Desktop/计算机网络/大作业3/任务1测试文件/2.jpg",
//	"C:/Users/Mika/Desktop/计算机网络/大作业3/接收到的文件/2.jpg");
int a(){
	return 2;
} 

int main() {
}
