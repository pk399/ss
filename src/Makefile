TARGET_EXEC = ss.exe

CFLAGS := -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla

CC = g++

SRCS = $(wildcard *.cpp)
OBJS = $(subst .cpp,.o,$(SRCS))

#all: $(TARGET_EXEC)
#	$(CC) $(CFLAGS) ss_testing.cpp ss_main.cpp ss.cpp

all: $(TARGET_EXEC)

test: CFLAGS += -D TESTS
test: $(TARGET_EXEC)

$(TARGET_EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(TARGET_EXEC)

$(OBJS): %.o: %.cpp
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o $(TARGET_EXEC)
