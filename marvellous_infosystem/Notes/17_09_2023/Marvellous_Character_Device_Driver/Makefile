obj-m += driver-3.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	gcc demo.c -o myexe

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm myexe
