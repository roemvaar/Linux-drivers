// SPDX-License-Identifier: GPL-2.0

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/utsname.h>

static int __init hello_init(void)
{
	pr_alert("%s: Hello world. You are currently using Linux:\n", module_name(THIS_MODULE));
	pr_alert("%s: %s version %s: %s\n", module_name(THIS_MODULE),
										utsname()->sysname,
										utsname()->release,
										utsname()->version);
	return 0;
}

static void __exit hello_exit(void)
{
	pr_alert("%s: Goodbye world!\n", module_name(THIS_MODULE));
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Roberto Valenzuela <valenzuelarober@gmail.com>");
MODULE_DESCRIPTION("Module to get kernel version");
