CC	:= gcc
CFLAGS	:= -Wall -Werror -Wextra -pedantic -std=gnu89
SRCS	:= $(wildcard *.c)
TARGET	:= shell

$(TARGET): $(SRCS)
	     $(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	$(RM) $(TARGET)
