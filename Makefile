CC = gcc
DebugFLAGS = -Wall -pedantic -ansi -g -O0
srcDir = "src"

all: aline.c

aline.c:
	$(CC) $(CFLAGS) $(srcDir)/$@ -o aline

clean:
	find -type f -executable -print -delete
