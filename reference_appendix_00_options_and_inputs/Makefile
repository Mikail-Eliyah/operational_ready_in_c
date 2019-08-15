# IDIR =../include \
This is a makefile \

IDIR =./inc
CC=gcc

ODIR=obj
# LIB_SRC_DIR =./lib
LDIR =./lib
DIR_TEST_USAGES =./test_usages
CFLAGS=-I $(IDIR)   

VPATH=$(LDIR):$(DIR_TEST_USAGES)

# header files required
_DEPS = *.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

#_DEP_LIB = *.c									#
#DEPS_LIB = $(patsubst %,$(LDIR)/%,$(_DEP_LIB))	#

_OBJ = lib.o main.o test_usages_00.o test_usages_01.o test_usages_02.o #*.o
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
	#./run '4' 'abcd' 'arg3' 'arg4' 'arg5' 'arg6' 'arg7'
	#./run 6 112233445566
	#./run -a -b
	#./run --file hello.txt
	#./run -a
	#./run -b
	#./run
	#./run -ba -f x1 -d x2 -c x3 --v
	# ./run -title "title" -artist "artist" -year 1991 -comment "comment" -album "album" -track 1
	# ./run -t "title_001100" -a "Uru:threads"
	./run -vabciefh
	
	echo "=========================================================="
	

#try 
#6 112233445566

#<< Loaded string data >> : 112233445566.
#<< String length >> : 6.

#try 
#6 11223344556677
#<< Declared string data length is NOT correct >> 7

#try 
#6 1122334455667
#<< string data is NOT even >>
	
.PHONY: clean

clean:
	echo "cleaning ...." $(ODIR)/*.o
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ ./*.exe
