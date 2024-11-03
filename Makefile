CC = gcc
CFLAGS = -Wall -g
EXECS = task1 task2 task3 task4 task5 task6

all: $(EXECS)

task1: task1.c
	$(CC) $(CFLAGS) -o task1 task1.c

run_task1: task1
	./task1

task2: task2.c
	$(CC) $(CFLAGS) -o task2 task2.c

run_task2: task2
	./task2

task3: task3.c
	$(CC) $(CFLAGS) -o task3 task3.c

run_task3: task3
	./task3

task4: task4.c
	$(CC) $(CFLAGS) -o task4 task4.c

run_task4: task4
	./task4

task5: task5.c
	$(CC) $(CFLAGS) -o task5 task5.c

run_task5: task5
	./task5

task6: task6.c
	$(CC) $(CFLAGS) -o task6 task6.c

run_task6: task6
	./task6

clean:
	rm -f $(EXECS)


