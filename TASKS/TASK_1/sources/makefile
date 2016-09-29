CPP = g++
BIN_DIR = ./bin
SOURCES = main.cpp vector3d.cpp

release: bin $(SOURCES)
	$(CPP) $(SOURCES) -o $(BIN_DIR)/release

debug: bin $(SOURCES)
	$(CPP) -DDEBUG $(SOURCES) -o $(BIN_DIR)/debug

cleanup:
	if [ -d "$(BIN_DIR)" ]; then \
		rm -rf $(BIN_DIR); \
	fi

bin:
	if [ -d "$(BIN_DIR)" ]; then \
		echo "Bin directory exists."; \
	else \
		mkdir $(BIN_DIR) && echo "Bin directory created."; \
	fi

