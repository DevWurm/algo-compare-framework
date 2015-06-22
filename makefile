ifeq	($(OS),Windows_NT)
all:
	mkdir libcompare/
	copy source/ libcompare/
	copy headers/ libcompare/
	copy libcompare.h libcompare/
else
all:
	mkdir -p libcompare/
	cp -r source/ libcompare/
	cp -r headers/ libcompare/
	cp libcompare.h libcompare/
endif
