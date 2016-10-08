#KERNELDIR = /home/huawei/kernel_study/kernel
KERNELDIR = /lib/modules/3.13.0-74-generic/build

#####################
PWD := $(shell pwd)

#ARCH=arm64
#CROSS_COMPILE    =aarch64-linux-gnu-
#CC    = $(CROSS_COMPILE)gcc
CC    = $(CROSS_COMPILE)gcc

obj-m := hello.o

modules:
	    $(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	    rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions

.PHONY: modules modules_install clean
