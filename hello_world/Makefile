ifneq ($(KERNELRELEASE),)

# obj-m := hello_version.o
# obj-m := time.o
obj-m := version_param.o

else

KDIR := /home/roemvaar/bootlin/linux-kernel-labs/src/linux

all:
	$(MAKE) -C $(KDIR) M=$$PWD

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean

endif
