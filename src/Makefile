all: install run

install: uninstall
	mkdir build
	cd s21_smartcalc && qmake-qt5 && make
	mv s21_smartcalc/s21_smartcalc build
	rm -rf s21_smartcalc/Makefile

uninstall:
	@rm -rf test calculations/*.o s21_smartcalc/*.o build

run:
	./build/s21_smartcalc

