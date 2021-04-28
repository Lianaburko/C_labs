all: clean build_Main build_Test run_Test

build_Main:
	mkdir -p solution/main
	g++ -o solution/main/number main.cpp -lm

build_Test:
	mkdir -p solution/test
	g++ -o solution/test/number_test -Dmain=_main main.cpp test.cpp -lm

run_Test:
	./solution/test/number_test

clean:
	rm -rf solution