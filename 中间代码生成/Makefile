all: compiler

OBJS = myparser.o \
		mylexer.o  \
		IRgenerator.o \
		main.o	 \
		typeCheck.o \

LLVMCONFIG = llvm-config-3.9
CPPFLAGS = `$(LLVMCONFIG) --cppflags` -std=c++11
LDFLAGS = `$(LLVMCONFIG) --ldflags` -lpthread -ldl -lz -lncurses -rdynamic -L/usr/local/lib -ljsoncpp
LIBS = `$(LLVMCONFIG) --libs`

clean:
	$(RM) -rf myparser.cpp myparser.hpp test compiler mylexers.cpp *.output $(OBJS)

IRgenerator.cpp: IRgenerator.h Nodes.h

myparser.cpp: myparser.y
	bison -d -o $@ $<

myparser.hpp: myparser.cpp

mylexer.cpp: mylexer.l myparser.hpp
	flex -o $@ $<

%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<

compiler: $(OBJS)
	g++ $(CPPFLAGS) -o $@ $(OBJS) $(LIBS) $(LDFLAGS)

if_fun_op_test: compiler if_fun_op_test.c
	cat if_fun_op_test.c | ./compiler
if_fun_op_testrun: output.o if_fun_op_test.c
	clang output.o -o test
	./test

array_for_test: compiler array_for_test.c
	cat array_for_test.c | ./compiler

array_for_testrun: output.o array_for_test.c
	clang output.o -o test
	./test

