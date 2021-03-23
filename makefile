CC=gcc
queueC: queueC.c
	$(CC) -o queueC queueC.c
clean: 
	rm -f queueC