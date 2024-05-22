ifneq ($(KERNELRELEASE),)
obj-m := nunchuk.o
else
KDIR := /home/roemvaar/bootlin/linux-kernel-labs/src/linux
all:
	$(MAKE) -C $(KDIR) M=$$PWD

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
endif
