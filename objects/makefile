#Makefile for compiling object data file writer for Vertigo

include makedefs

OBJ_OBJ = initobja.o initobjb.o initobjc.o initobjd.o initobje.o initobjf.o initobjg.o

all	: objwrite$(EXE) data 


mymath.o  : mymath.c ../mymath.h objects.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) -c mymath.c

initobja.o : initobja.c ../bool.h objects.h ../mymath.h harrier.c corsair.c hangar.c tower.c
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c initobja.c

initobjb.o : initobjb.c ../bool.h objects.h ../mymath.h u2.c runway.c rw_mark.c map.c sun.c t17.c f104.c
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c initobjb.c

initobjc.o : initobjc.c ../bool.h objects.h ../mymath.h nim_hull.c nim_deck.c nim_mk1.c nim_mk2.c
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c initobjc.c

initobjd.o : initobjd.c ../bool.h objects.h ../mymath.h f14.c
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c initobjd.c

initobje.o : initobje.c ../bool.h objects.h ../mymath.h windbag.c target.c t17_cp.c corsa_cp.c u2_cp.c f104_cp.c harr_cp.c f14_cp.c x15.c addon1.c addon2.c addon3.c
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c initobje.c

initobjf.o : initobjf.c ../bool.h objects.h ../mymath.h lm.c 
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c initobjf.c

initobjg.o : initobjg.c ../bool.h objects.h ../mymath.h lm_asc.c 
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c initobjg.c

objwrite$(EXE) : objwrite.o mymath.o $(OBJ_OBJ)
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) objwrite.o mymath.o $(OBJ_OBJ) $(LIB) $(LINKFLAGS) -o objwrite$(EXE)

objwrite.o      : objwrite.c objwrite.h objects.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c objwrite.c

data : objects.dat 

objects.dat : objwrite$(EXE)
	./objwrite$(EXE)

clean:
	$(DELCMD) *.o

cleanall:
	$(DELCMD) *.o 
	$(DELCMD) *.bak 
	$(DELCMD) objwrite$(EXE) 
	$(DELCMD) objects.dat
