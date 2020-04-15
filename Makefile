CC = gcc
CFLAGS = -W -Wall
TARGET = shop
DTARGET = shop_debug
OBJECTS = main.c product.o manager.o

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
clean :
	rm *.o $(TARGET) $(DTARGET)



