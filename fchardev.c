#include<linux/types.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>

#define DEVNAME "fchardev"

dev_t dev;

static int __init init_dev(void) {
	printk(KERN_INFO "Trying to make my first kernel device!!");
	int result = alloc_chrdev_region(&dev, 0, 2, DEVNAME);
	if (result) {
		printk(KERN_INFO "Unable to allocate region!!");
	}
	printk(KERN_INFO "hip hip hurray!!! Successful allocation!!! major -> %d and minor -> %d", MAJOR(dev), MINOR(dev));
	return 0;
}

static void __exit cleanup_dev(void) {
	printk(KERN_INFO "Will be back with extra features :))");
	unregister_chrdev_region(dev, 2);
}

module_init(init_dev);
module_exit(cleanup_dev);

MODULE_AUTHOR("Vishal");
MODULE_DESCRIPTION("small utility char device");
MODULE_LICENSE("GPL"); 
