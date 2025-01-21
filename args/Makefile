ifneq ($(KERNELRELEASE),)

obj-m := args.o

else

KDIR := /linux_work/linux_stable

all:
	$(MAKE) -C $(KDIR) M=$$PWD

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean

endif
