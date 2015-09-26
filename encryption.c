/********************
Signature: Paul Mattioli
Date: 9/23/2015
program: encryption.c will encrypt and decrypt files using c system calls
*********************/

#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int main(int argc, const char* argv[]){
	
	int cread, kread;
	int length =0;
	int key_length=0;

	struct stat buf1;
	struct stat buf2;
	struct stat buf3;
	
/*Following lines opens input file and key files, allocating memory to buffs for file read and writes.*/
	int input_fd = open(argv[1], O_RDONLY,S_IRWXU);
	int key_fd = open(argv[2], O_RDONLY,S_IRWXU);
	mode_t mode = S_IREAD; //  
	int output_fd = creat(argv[3], mode);
	off_t ret;

	stat(argv[1], &buf1);
	stat(argv[2], &buf2);


	int input_size= buf1.st_size;
	int key_size= buf2.st_size;
	char input_buff[input_size];
	char output_buff[input_size];
	char key_buff[input_size];

	for(int j=0; j<input_size; j++){
		kread=read(key_fd,key_buff,key_size);
		if((kread=read(key_fd,key_buff,key_size))==0)
				ret = lseek (key_fd, (off_t) 0, SEEK_SET);
	}

/*counts char in file by loop through contents*/
	while((cread=read(input_fd, input_buff, input_size))!=0)
	{

	for(int i=0; i<input_size;i++){
		output_buff[i]=input_buff[i]^key_buff[i]; //assign char to holder
	}
	write(output_fd, output_buff,input_size);
} 
	close(input_fd);
	close(key_fd);
	close(output_fd);
   }	
	
