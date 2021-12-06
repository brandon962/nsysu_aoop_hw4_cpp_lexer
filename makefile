all : compile 
	
compile:main.o lexer.o
	@echo "Start compile."
	g++ -o main.out main.o lexer.o -O3
	@echo "End compile."
	@echo "------------------------------"

main.o:
	g++ main.cpp -c -O3

lexer.o:
	g++ lexer.cpp -c -O3

dep:
	@echo "nothing"

clean:
	@echo "Start clean."
	rm -f main.out *.o
	@echo "Finished clean."
	@echo "------------------------------"
