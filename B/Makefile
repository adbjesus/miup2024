SOURCE := main.py
INPUTS := $(shell find . -name '*.in')

run: $(BINARY)
	$(foreach f,$(INPUTS),echo $(f); pypy3 $(SOURCE) < $(f);)

diff: $(BINARY)
	$(foreach f,$(INPUTS),echo $(f); pypy3 $(SOURCE) < $(f) | diff $(f:%.in=%.out) -;)

