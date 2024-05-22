// SPDX-License-Identifier: GPL-2.0
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/utsname.h>

time64_t on;

static int __init time_init(void)
{
	pr_alert("%s: Hello world.\n", module_name(THIS_MODULE));
	on = ktime_get_seconds();

	return 0;
}

static void __exit time_exit(void)
{
	time64_t elapsed;

	pr_alert("%s: Goodbye world!\n", module_name(THIS_MODULE));
	elapsed = ktime_get_seconds() - on;
	pr_alert("%s: Time module installed: %lld secs\n", module_name(THIS_MODULE), elapsed);
}

module_init(time_init);
module_exit(time_exit);

MODULE_AUTHOR("Roberto Valenzuela <valenzuelarober@gmail.com>");
MODULE_DESCRIPTION("Module that shows time alive");
MODULE_LICENSE("GPL");
