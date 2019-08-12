#include <linux/init.h>    
#include <linux/module.h>      
#include <linux/kernel.h>      

MODULE_LICENSE("GPL");             
MODULE_AUTHOR("Daniel Ogwok");    
MODULE_DESCRIPTION("A Basic Linux Kernel Module that supports module parameters."); 
MODULE_VERSION("0.1");         

static char *name = "world";       	//Module parameters
module_param(name, charp, S_IRUGO); 	//Parameter name
MODULE_PARM_DESC(name, "The name to display in /var/log/kern.log");  //Parameter description

/** 
 * Function to onotialize
 */
static int __init myModule_init(void){
   printk(KERN_INFO "myModule: Hey %s from my first LKM!\n", name);
   return 0;
}

/**
 * Function to exit moule
 */
static void __exit myModule_exit(void){
   printk(KERN_INFO "myModule: Goodbye %s from my first LKM!\n", name);
}

/** 
 * Implementation of modules
 */
module_init(myModule_init);
module_exit(myModule_exit);
