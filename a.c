#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int main(void)
{
    int fd;
    int n = 0,i;
    char str1[200]={" "},str2[200] ={" "};
    fd = open("/dev/globalmem",O_RDWR);
   // printf("%d",fd);
    if(fd < 0)
    {
        printf("the file canot open!!!!\n");
        return 0;
    }
    
    printf("file ok!!!!!\n");
    n = read(fd,str1,200);
    str1[n] = '\0';
    printf("%s\n",str1);
    n = 0;
    n = read(STDIN_FILENO,str2,200);
    printf("%d\n",n);
    str2[n] = '\0';
    printf("%d is %s\n",n,str2);
    write(fd,str2,n);

    close(fd);
    return 0;
}
