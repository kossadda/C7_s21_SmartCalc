all: install run

install: clean
	mkdir build
	cd smartcalc && qmake-qt5 && make
	mv smartcalc/smartcalc build
	rm -rf smartcalc/Makefile

uninstall: clean

run:
	./build/smartcalc

clean:
	@rm -rf test functions/*.o smartcalc/*.o build