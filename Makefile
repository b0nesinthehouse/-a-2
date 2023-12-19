all: main

main: main.c database.c
    gcc -o main main.c database.c

clean:
    rm -f main