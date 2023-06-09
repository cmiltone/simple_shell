CC	:= gcc
CFLAGS	:= -Wall -Werror -Wextra -pedantic -std=gnu89
SRCS	:= $(wildcard *.c)
TARGET	:= simple_shell

$(TARGET): $(SRCS)
	     $(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	$(RM) $(TARGET)
