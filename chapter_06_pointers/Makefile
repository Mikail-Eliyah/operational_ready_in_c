# IDIR =../include \
This is a makefile \

IDIR =./inc
CC=gcc

ODIR=obj
# LIB_SRC_DIR =./lib
LDIR =./lib
CFLAGS=-I $(IDIR)   

VPATH=$(LDIR)

# header files required
_DEPS = *.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

#_DEP_LIB = *.c									#
#DEPS_LIB = $(patsubst %,$(LDIR)/%,$(_DEP_LIB))	#

_OBJ = lib.o main.o test_usages.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)		## $(DEPS_LIB)
	$(CC) -c -o $@ $< $(CFLAGS) 

#%.o: %.c
#    	$(CC) $(CFLAGS) $(INCLUDES) -c $(input) -o $(output)
		
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
