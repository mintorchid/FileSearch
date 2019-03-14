.SUFFIXES:.c .o
CC = clang
CC_FLAGS = -W -Wall -Werror

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
EXEC = main.exe

do:build

all:build

build:$(EXEC)
	@echo -----$(EXEC) is up-to-date.-----

$(EXEC):$(OBJS)
	$(CC) $(CC_FLAGS) -o $(EXEC) $(OBJS) -static-libgcc -fcolor-diagnostics --target=x86_64-w64-mingw -std=c11
	@echo -----Compile successfully.-----

.c.o:
	$(CC) $(CC_FLAGS) -g -o $@ -c $< -fcolor-diagnostics --target=x86_64-w64-mingw -std=c11

clean:
	del $(OBJS)
	del $(EXEC)
