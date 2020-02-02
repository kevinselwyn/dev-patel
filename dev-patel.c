#include <linux/fs.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <asm/uaccess.h>
#include "dev-patel.h"

static ssize_t patel_read(struct file *file, char *buf, size_t count, loff_t *ppos) {
	if (count < dev_patel_png_len) {
		return -EINVAL;
	}

	if (*ppos != 0) {
		return 0;
	}

	if (copy_to_user(buf, dev_patel_png, dev_patel_png_len)) {
		return -EINVAL;
	}

	*ppos = dev_patel_png_len;

	return dev_patel_png_len;
}

static const struct file_operations patel_fops = {
	.owner = THIS_MODULE,
	.read  = patel_read
};

static struct miscdevice patel_dev = {
	MISC_DYNAMIC_MINOR,
	"patel",
	&patel_fops
};

static int __init patel_init(void) {
	int ret = 0;

	ret = misc_register(&patel_dev);

	if (ret) {
		printk(KERN_ERR "Unable to register \"Patel\" misc device\n");
	}

	return ret;
}

module_init(patel_init);

static void __exit patel_exit(void) {
	misc_deregister(&patel_dev);
}

module_exit(patel_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kevin Selwyn <kevinselwyn@gmail.com>");
MODULE_DESCRIPTION("Dev Patel");
MODULE_VERSION("dev");