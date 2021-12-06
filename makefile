all : start main.o lexer.o
	g++ -o main.out main.o lexer.o -O3
	@echo "End compile."
	@echo ""

start:
	@echo "Start compile."

main.o:
	g++ main.cpp -c -O3

lexer.o:
	g++ lexer.cpp -c -O3


dep:
	@echo "nothing"

clean:
	@echo "Clean main.out & *.o."
	rm -f main.out *.o
	@echo "Finished clean."
	@echo ""
