BINARY := main
SOURCE := main.cpp
INPUTS := $(shell find . -name '*.in')

run: $(BINARY)
	$(foreach f,$(INPUTS),echo $(f); time ./$(BINARY) < $(f);)

diff: $(BINARY)
	$(foreach f,$(INPUTS),echo $(f); ./$(BINARY) < $(f) | diff $(f:%.in=%.out) -;)

debug: $(SOURCE)
	g++ -g -std=c++17 -o $(BINARY) $(SOURCE)

build: $(BINARY)
$(BINARY): $(SOURCE)
	g++ -O2 -std=c++17 -o $(BINARY) $(SOURCE)
