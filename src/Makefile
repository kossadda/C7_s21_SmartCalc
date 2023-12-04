all: install run

install: uninstall
	mkdir build
	cd s21_smartcalc && qmake-qt5 && make
	mv s21_smartcalc/s21_smartcalc build
	rm -rf s21_smartcalc/Makefile

uninstall:
	@rm -rf test build build-* calculations/*.o s21_smartcalc/*.o s21_smartcalc/ui_* s21_smartcalc/moc_* s21_smartcalc/*.user

run:
	./build/s21_smartcalc

