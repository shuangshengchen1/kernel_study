#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
/*sadjkljasdfjkl*/
static int __init hello_init(void)
{
        printk(KERN_INFO "Hello world"); /* 打印的信息会出现在 dmesg 中 释放*/
        return 0;  /*  返回 0 是正常 */
} 

static void __exit hello_exit(void)
{
        printk(KERN_INFO "Goodbye world");
} 


module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
