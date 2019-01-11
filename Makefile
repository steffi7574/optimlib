CC     = mpicc
CXX    = mpicxx

# set compiler flags
CPPFLAGS = -g -Wall -pedantic -lm -Wno-write-strings -Wno-delete-non-virtual-dtor -std=c++11

DEPS = optimizer.hpp  hessianApprox.hpp linalg.hpp defs.hpp
OBJ  = optimizer.o  hessianApprox.o linalg.o

.PHONY: all clean

%.o: %.cpp $(DEPS)
	$(CXX) $(CPPFLAGS) -c $< -o $@

liboptim.a: $(DEPS) $(OBJ)
	@echo "Building" $@ "..."
	ar cruv liboptim.a $(OBJ)
	ranlib liboptim.a


all: liboptim.a

clean:
	rm -f *.o liboptim.a

