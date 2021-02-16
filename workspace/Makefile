CXX=g++
CFLAGS=-g -std=c++17 -DLOCAL -Wall -O0 -I./../ac-library -fsanitize=undefined -D_GLIBCXX_DEBUG

%: %.cpp
	$(CXX) $(CFLAGS) -o $@ $<

.PHONY: clean, reset

clean:
	rm -f $(filter-out %.cpp Makefile %.sh, $(shell ls))

reset:
	rm -f $(filter-out Makefile %.sh, $(shell ls))
	./reset.sh a b c d e f
