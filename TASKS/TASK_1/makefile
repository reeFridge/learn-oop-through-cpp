CPP = g++

.SUFFIXES: .cpp .o
	.cpp.o:
	$(CPP) $<

SOURCES = main.cpp vector.cpp

main: $(SOURCES)

debug: $(SOURCES)
	$(CPP) -DDEBUG $? -o debug
