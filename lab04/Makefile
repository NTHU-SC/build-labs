CXX = g++
exe = main.elf
obj = main.o print.o

$(exe): $(obj)
	$(CXX) -o $(exe) $(obj)

%.o: %.cpp
	$(CXX) -c $^ -o $@

.PHONY: clean
clean:
	rm $(exe) *.o


