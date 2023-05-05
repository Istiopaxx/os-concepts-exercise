#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/gcd.h>
#include <asm/param.h>
#include <linux/jiffies.h>

long init_jiffies;

/* This function is called when the module is loaded. */
int simple_init(void)
{
  printk(KERN_INFO "Loading Kernel Module");
  printk(KERN_INFO "Golden ratio prime : %llu", GOLDEN_RATIO_PRIME);
  printk(KERN_INFO "HZ : %d", HZ);
  printk(KERN_INFO "Jiffies at init : %lu", jiffies);
  init_jiffies = jiffies;
  return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void)
{
  printk(KERN_INFO "Removing Kernel Module");
  printk(KERN_INFO "gcd(3300, 24) = %lu", gcd(3300, 24));
  printk(KERN_INFO "Jiffies at exit : %lu", jiffies);
  printk(KERN_INFO "Time elapsed from loading to unloading : %lu second", (jiffies - init_jiffies) / HZ);
}

/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");