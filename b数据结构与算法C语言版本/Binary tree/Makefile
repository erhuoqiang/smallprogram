src := $(shell ls *.cpp)
obj := $(patsubst %.cpp,%.o,$(src))
CC := g++
Tree:$(obj)
	$(CC) $^ -o $@
$(obj):$(src)
	$(CC) $(src) -c -o $(obj) 

clean:
	rm -f Tree *.o   
