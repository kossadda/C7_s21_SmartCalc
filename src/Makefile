test: 
	@clear
	@gcc tests/main.c C_part/*.c -o tt
	@./tt
	@rm -rf tt

install: clean
	mkdir build
	cd smartcalc && qmake-qt5 && make
	mv smartcalc/smartcalc build
	rm -rf smartcalc/Makefile

uninstall: clean

run:
	./build/smartcalc

valgrind: tt
	@valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./build/smartcalc

clean:
	@rm -rf test functions/*.o smartcalc/*.o build
