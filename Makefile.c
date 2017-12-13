KVERS = $(shell uname -r)

#Kernal modules

obj-m += file.o

# Specify flags for the module compilation.
//EXTRA_CFLAGS=-g -O1

build: kernal_modules

kernal_modules:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) modules

clean:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) clean


