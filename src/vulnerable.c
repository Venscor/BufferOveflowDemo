#include<stdio.h>
#include<string.h>
/*unsigned long get_sp(){
	__asm__("movl %esp,%eax");
}*/
void main(int argc,char*argv[]){
	char buffer[512];
	if(argc>1){
		strcpy(buffer,argv[1]);
		printf("input buffer size:%d\n",strlen(argv[1]));
	}
}
