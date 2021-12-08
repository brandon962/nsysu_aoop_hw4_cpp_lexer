all : compile 
	
start_com:
	@echo "------------------------------"
	@echo "Start compile."
	
compile:start_com main.o lexer.o
	
	g++ -o main.out main.o lexer.o -O3
	@echo "End compile."
	@echo "------------------------------"

main.o:
	g++ main.cpp -c -O3

lexer.o:
	g++ lexer.cpp -c

dep:
	@echo "nothing"

clean:
	@echo "------------------------------"
	@echo "Start clean."
	rm -f main.out *.o
	@echo "Finished clean."
	@echo "------------------------------"
