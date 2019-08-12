#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENCSE("GPL");
MODULE_AUTHOR("Daniel Ogwok");
MODULE_DESCRIPTION("A basic Linux kernel module  that supports module parameters");
MODULE_VERSION("0.1");

static char *name = "world";	//An eample LKM argument - default value is "world"
module_param(name, charp, S_IRUG0);	//Parameter Description character pointer, charp = char ptr, S_IRUG0 can be read/not changed
MODULE_PARM_DESC(name, "The name to display in /var/log/kern.log");	//Parameter description

/**
 * LKM Initialization function
 */
static int __init myModule_init(void){
	printk(KERN_INFO "myModule: Hello %, from my Module LKM. \n", name);
	return 0;
}

/**
 * LKM cleanup function
 */
static void __exit myModule_exit(void){
	printk(KERN_INFO "myModule: Goodbye %s from my Module LKM. \n", name);
}

module_init(myModule_init);
module_init(myModule_exit);

