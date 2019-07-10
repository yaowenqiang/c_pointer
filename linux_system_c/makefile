OBJS = howdy.o helper.o
HDRS = helper.h
# howdy: howdy.o helper.o helper.h
howdy: $(OBJS) $(HDRS)
# gcc howdy.o helper.o -o howdy
	gcc $(OBJS) -o howdy
helper.o: helper.c $(HDRS)
	gcc -c helper.c
howdy.o: howdy.c
	gcc -c howdy.c

hello:hello.c
	gcc hello.c -o hello
all: howdy hello
.PHONY: clean

clean:
	rm howdy hello *.o
