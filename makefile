#Makefile for compiling Vertigo using djgpp

include makedefs
VERSION = 0.26
EXEDIR = vertigo-$(VERSION)
EXEFILES = $(PROGRAM) install.txt keys.txt license.txt vertigo.txt \
   *.dat 

OBJECTS = vertigo.o mymath.o mtable.o map.o config.o joystick.o polygrap.o timestat.o message.o carrier.o sound.o aoa360.o blt_inst.o astro.o gen_wing.o accel.o keyinp.o $(SYS_OBJECTS)

all    : $(PROGRAM) objwrite 

ifndef LINUX
# DOS/DJGPP
$(PROGRAM) : $(OBJECTS)
	$(CC) $(OPTFLAGS) $(WARNFLAGS) $(OBJECTS) $(LIB) $(LINKFLAGS) -o $(PROGRAM)
	stubedit vertigo.exe minstack=0x80000
else
# Linux/X11
$(PROGRAM) : $(OBJECTS)
	$(CC) $(OPTFLAGS) $(WARNFLAGS) $(OBJECTS) $(LIBG) $(LINKFLAGS) -o $(PROGRAM)
endif

vertigo.o : vertigo.c joystick.h graphics.c fltmodel.c instrum.c vertigo.h map.h mymath.h timestat.h config.h mtable.h polygrap.h carrier.h sound.h message.h aoa360.h blt_inst.h astro.h accel.h bool.h objects/objects.h $(SYS_HEADERS)
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c vertigo.c

mymath.o  : mymath.c mymath.h objects/objects.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c mymath.c

mtable.o  : mtable.c airplane/*.c vertigo.h mymath.h gen_wing.h objects/objects.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c mtable.c

keyinp.o  : keyinp.c keyinp.h vertigo.h bool.h mymath.h map.h message.h carrier.h sound.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c keyinp.c

accel.o  : accel.c accel.h propel.c jet_eng.c rock_eng.c vertigo.h mymath.h message.h sound.h carrier.h aoa360.h config.h objects/objects.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c accel.c

gen_wing.o: gen_wing.c gen_wing.h vertigo.h mymath.h objects/objects.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c gen_wing.c

map.o     : map.c map.h vertigo.h mymath.h carrier.h objects/objects.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c map.c

config.o  : config.c vertigo.h joystick.h map.h message.h carrier.h mymath.h sound.h objects/objects.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c config.c

joystick.o : joystick.c joystick.h vertigo.h objects/objects.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c joystick.c

ifeq ($(GUI),MGUI)

mgmenus.o : mgui/mgmenus.c mgui/mgmenus.h config.h vertigo.h mtable.h blt_inst.h objects/objects.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c mgui/mgmenus.c

mgerror.o : mgui/mgerror.c mgui/mgerror.h vertigo.h objects/objects.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c mgui/mgerror.c

endif

ifeq ($(GUI),CGUI)

cgmenus.o : cgui/cgmenus.c cgui/cgmenus.h config.h vertigo.h mtable.h blt_inst.h objects/objects.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c cgui/cgmenus.c
endif

polygrap.o : polygrap.c vertigo.h polygrap.h timestat.h mymath.h map.h objects/objects.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c polygrap.c

timestat.o : timestat.c timestat.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c timestat.c

message.o  : message.c message.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c message.c

carrier.o    : carrier.c carrier.h vertigo.h polygrap.h timestat.h message.h sound.h mymath.h objects/objects.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c carrier.c

sound.o      : sound.c sound.h vertigo.h mymath.h carrier.h objects/objects.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c sound.c

aoa360.o      : aoa360.c aoa360.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c aoa360.c

blt_inst.o    : blt_inst.c blt_inst.h vertigo.h objects/objects.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c blt_inst.c

astro.o       : astro.c astro.h vertigo.h polygrap.h objects/objects.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEFSYS) -c astro.c


objwrite:
	$(MAKE) -C objects

exedist: $(PROGRAM) objwrite
ifndef DJGPP
	mkdir vertigo-$(VERSION)
	mkdir vertigo-$(VERSION)/objects
	cp $(EXEFILES) $(EXEDIR)
	cp -r sound $(EXEDIR)
	cp objects/objects.dat objects/objects.pos $(EXEDIR)/objects
	tar -zcf vertigo-$(VERSION).tgz vertigo-$(VERSION)
	rm -rf vertigo-$(VERSION)
 ifeq ($(LIBTYPE), STATIC)
	@echo "__Static__ libs executeable distribution created."
 else
	@echo "__Shared__ libs executeable distribution created." 
 endif
else
	@echo "DOS executeable distribution not supported!!!" 
endif

clean:
	$(DELCMD) *.o
ifndef LINUX
	$(DELCMD) objects\*.o
else
	$(DELCMD) objects/*.o objects/objwrite Xvertigo
endif

cleanall:
	$(DELCMD) *.o 
	$(DELCMD) objects.dat
ifndef LINUX
	$(DELCMD) *.bak
	$(DELCMD) vertigo.exe
	$(DELCMD) objwrite.exe
else
	$(DELCMD) vertigo Xvertigo
endif
	$(MAKE) -C objects cleanall
