CPP = g++
BIN_DIR = ./bin
SOURCES = main.cpp vector3d.cpp

release: $(SOURCES)
	$(CPP) $? -o $(BIN_DIR)/release

debug: $(SOURCES)
	$(CPP) -DDEBUG $? -o $(BIN_DIR)/debug
