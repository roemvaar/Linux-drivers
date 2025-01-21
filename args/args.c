// SPDX-License-Identifier: GPL-2.0

/*
 * args_module.c - Kernel Module that accepts a name as command line
 * argument and print hello <name>
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

static char *name = "world";
module_param(name, charp, 0000);
MODULE_PARM_DESC(name, "Name to be printed as greeting!");

static int __init args_module_init(void)
{
		pr_info(KBUILD_MODNAME ": Hello %s!\n", name);
		return 0;
}

static void __exit args_module_exit(void)
{
		pr_info(KBUILD_MODNAME ": Good bye %s!\n", name);
}

/* Register the module */
module_init(args_module_init);
module_exit(args_module_exit);

/* Information regarding the module */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Roberto Valenzuela <valenzuelarober@gmail.com");
MODULE_DESCRIPTION("Kernel Module that accepts command line arguments");
