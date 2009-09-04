AUTOMAKE_OPTIONS = gnu
SUBDIRS= computers help mp3 pix skins src
EXTRA_DIST = gtkgo.gif gtkgo2.gif gnome-gtkgo.png gtkgoico.ico gtkgoico.xpm gtkgo.desktop configure.old
bootstrap:
	aclocal; automake; autoconf
myclean:
	rm -f config.*
	rm -f Makefile
	rm -f computers/Makefile
	rm -f help/Makefile
	rm -f mp3/Makefile
	rm -f pix/Makefile
	rm -f skins/Makefile
	rm -f src/Makefile
	rm -f src/*.o
	rm -rf src/.deps
	rm -f src/gtkgo
