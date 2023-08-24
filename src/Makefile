TARGET_EXEC = ss.exe

CFLAGS = -Wall
CC = g++

SRCS = $(wildcard *.cpp)
OBJS = $(subst .cpp,.o,$(wildcard *.cpp))

#all: $(TARGET_EXEC)
	#$(CC) $(CFLAGS) ss_testing.cpp ss_main.cpp ss.cpp

$(TARGET_EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(TARGET_EXEC)

$(OBJS): %.o: %.cpp
	$(CC) $(CFLAGS) $^ -c

clean:
	rm -f *.o *.exe
