## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = ag

ag_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	verif.c verif.h \
	nour.c nour.h \
	admin.c admin.h \
	recla.c recla.h \
        jjjj.c hhhh.h  \
	rese.c  \
	fact.c fact.h
	

ag_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

