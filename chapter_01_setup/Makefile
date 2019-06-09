# IDIR =../include \
This is a makefile \

IDIR =./inc
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib
# header files required
_DEPS = *.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# object files from C files
_OBJ = hello_main.o hello_function.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# make commands options: make <options>, e.g. make hello_make	
# executable name
hello_make: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

run: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
	echo "=========================================================="
	./run
	echo "=========================================================="
	
.PHONY: clean

clean:
	echo "cleaning ...." $(ODIR)/*.o
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ ./*.exe
