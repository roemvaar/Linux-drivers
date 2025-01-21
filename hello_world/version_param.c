// SPDX-License-Identifier: GPL-2.0

/* hello_version.c */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/utsname.h>

static char *who = "world";
module_param(who, charp, 0644);
MODULE_PARM_DESC(who, "Recipient of the hello message");

static int __init version_param_init(void)
{
	pr_alert("%s: Hello %s\n", module_name(THIS_MODULE), who);
	pr_alert("%s: %s version %s: %s\n", module_name(THIS_MODULE),
										 utsname()->sysname,
										 utsname()->release,
										 utsname()->version);
	return 0;
}

static void __exit version_param_exit(void)
{
	pr_alert("%s: Goodbye %s!\n", module_name(THIS_MODULE), who);
}

module_init(version_param_init);
module_exit(version_param_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Roberto Valenzuela <valenzuelarober@gmail.com>");
MODULE_DESCRIPTION("Module for greeting and get version");
