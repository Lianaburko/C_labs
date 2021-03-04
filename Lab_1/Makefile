all: clean build_Main build_Test run_Test

build_Main:
	mkdir -p solution/main
	gcc -o solution/main/number main.c -lm

build_Test:
	mkdir -p solution/test
	gcc -o solution/test/number_test -Dmain=_main main.c test.c -lm

run_Test:
	./solution/test/number_test

clean:
	rm -rf solution