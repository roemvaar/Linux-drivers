// SPDX-License-Identifier: GPL-2.0

/*
 * panic_module.c - Kernel module that produces a kernel panic.
 * Don't use it in your host environment unless you want it to break.
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/panic.h>

/*
 * panic_module_init - The init function for the panic module.
 * After the module is install, the kernel will panic due to
 * the call of panic() inside init function.
 */
static int panic_module_init(void)
{
	pr_info(": panic module started");
	panic("panic the kernel using panic() function from panic.h\n");

	return 0;
}

/*
 * panic_module_exit - The exit function, won't be called because
 * the kernel will panic after calling init.
 */
static void panic_module_exit(void)
{
	pr_info(": panic module exit\n");
}

module_init(panic_module_init);
module_exit(panic_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Roberto Valenzuela <valenzuelarober@gmail.com>");
MODULE_DESCRIPTION("Kernel module that produces a kernel panic");
