# Linux Drivers

Linux kernel device drivers

## Install Modules

```
$ sudo insmod <module>.ko
$ sudo rmmod <module>.ko
$ sudo dmesg | tail
$ sudo lsmod | grep "<module>"  # Check that your module is on the list of loaded modules
```

You can use `cat /proc/modules` to check if your module was loaded correctly.
