CC = gcc
CFLAGS = -Wall -g

LOOP_SOURCES = advancedClassificationLoop.o basicClassification.o
RECURSIVE_SOURCE = advancedClassificationRecursion.o basicClassification.o

all: recursives recursived loops loopd mains maindloop maindrec
maindloop: main.o libclassloops.so
	$(CC) $(CFLAGS) -o maindloop main.o libclassloops.so
maindrec: main.o libclassrec.so
	$(CC) $(CFLAGS) -o maindrec main.o libclassrec.so
mains: main.o libclassrec.a
	$(CC) $(CFLAGS) -o mains main.o libclassrec.a

main.o: main.c NumClass.h
	$(CC) $(CFLAGS) -c main.c

loops: $(LOOP_SOURCES)
	ar -rcs libclassloops.a $(LOOP_SOURCES)

recursives : $(RECURSIVE_SOURCE)
	ar -rcs libclassrec.a $(RECURSIVE_SOURCE)
recursived: $(RECURSIVE_SOURCE)
	$(CC) -Wall -shared -o libclassrec.so -fPIC $(RECURSIVE_SOURCE)

loopd: $(LOOP_SOURCES)
	$(CC) -Wall -shared -o libclassloops.so -fPIC $(LOOP_SOURCES)


basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CFLAGS) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationRecursion.c

clean:
	rm -f *.o *.a *.so mains maindloop maindrec
