OBJECTS := nuloops.o main.o

obj-m := nulo.o
nulo-objs := $(OBJECTS)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
