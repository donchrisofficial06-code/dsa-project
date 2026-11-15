CC=gcc
CFLAGS=-Wall -Wextra -std=c11
all: student_search
student_search: main.c
	$(CC) $(CFLAGS) main.c -o student_search
clean:
	rm -f student_search student_search.exe
