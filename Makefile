#
# make: all, clean, tar
#
#=========================================================================
DIR = `basename $(CURDIR)`
#------------------------

MAIN = so_task_9
LIB = thread

SECTIONS = 5
THREADS = 3
#----------------------
EXEC1 = $(MAIN).x
OBJS1 = $(MAIN).o
#----------------------

#----------------------
LIBS1 = $(LIB).c
#----------------------
#############################
COFLAGS = -Wall -std=c99 -pedantic -O -fPIC -lpthread
LDFLAGS = -Wall -std=c99 -pedantic -O -fPIC -lpthread
CO = gcc
LD = $(CO)
#############################
%.o: %.c
	$(CO) $(COFLAGS) -c $<
#############################


.PHONE: d
d: $(EXEC1)

.PHONY: all
all: $(EXEC1)
#############################
$(EXEC1): $(OBJS1) $(LIBS1)
	 $(LD) $^ -o $@ $(LDFLAGS)


.PHONE: run
run: $(EXEC1)
	./$(EXEC1) $(THREADS) $(SECTIONS)


.PHONY: clean tar
EXECS = $(EXEC1)

clean:
	rm -f *.o  *~ $(EXECS)
#=========================================================================
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
#=========================================================================