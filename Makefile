NAME  := dev-patel
obj-m := $(NAME).o
KDIR  := /lib/modules/$(shell uname -r)/build
PWD   := $(shell pwd)

all: build

build: $(NAME).c $(NAME).png
	xxd -i $(NAME).png > $(NAME).h
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm -f .*.cmd *.h *.ko *.mod.c *.o *.symvers *.order
	rm -rf .tmp_versions

install: build
	cp patel.rules /etc/udev/
	chmod +x /etc/udev/patel.rules
	ln -s /etc/udev/patel.rules /etc/udev/rules.d/010_patel.rules
	insmod ./$(NAME).ko

uninstall:
	rm -f /etc/udev/patel.rules
	rm -f /etc/udev/rules.d/010_patel.rules
	rmmod $(NAME)