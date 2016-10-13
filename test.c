#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

main()
{
int fd, num;
// fd=open("/dev/my74hc595", O_RDWR, S_IRUSR|S_IWUSR); //可读写方式打开设备文件
fd=open("/dev/my74hc595-0", O_RDWR); //可读写方式打开设备文件
if(fd!=-1)
{
	read(fd, &num, sizeof(int)); //读取设备变量
	printf("The my74hc595 is %d\n", num);

	printf("Please input the num written to my74hc595\n");
	scanf("%d", &num);
	write(fd, &num, sizeof(int)); //写设备变量

	read(fd, &num, sizeof(int)); //再次读取刚才写的值
	printf("The my74hc595 is %d\n", num);

	close(fd); //关闭设备文件
}
else
{
	printf("Device open failure\n");
	perror("open my74hc595");
}
}
