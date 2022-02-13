CC = g++
CFLAGS = -Wall -std=c++11

OBJECTS1 = onp.o

TARGET1 = onp.out

.PHONY: all
all:$(TARGET1) $(TARGET2)

%.o : %.c++ Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET1) : $(OBJECTS1)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS1) -o $(TARGET1)

$(TARGET2) : $(OBJECTS2)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS2) -o $(TARGET2)

.PHONY: all
all:$(TARGET1) $(TARGET2)

.PHONY : clean

clean :
	$(RM) *.o *.out core