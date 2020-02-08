obj-m =  fchardev.o
KERNELVERS = $(shell uname -r)
all:
	make -C /lib/modules/$(KERNELVERS)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KERNELVERS)/build M=$(PWD) clean
