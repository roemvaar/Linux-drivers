// SPDX-License-Identifier: GPL-2.0

/*
 * hello_world.c - The Hello World Kernel Module by Roberto
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

/*
 * hello_world_init - The init function, called when the module is loaded.
 * Returns zero if succefully loaded, non-zero otherwise.
 */
static int hello_world_init(void)
{
    pr_alert("Hello World from Kernel Module by Roberto\n");

    return 0;
}

/*
 * hello_world_exit - The exit function, called when the module is removed.
 */
static void hello_world_exit(void)
{
    pr_alert("See You Later, Alligator!\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Roberto Valenzuela <valenzuelarober@gmail.com>");
MODULE_DESCRIPTION("The Hello World Kernel Module by Roberto");
