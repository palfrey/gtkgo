## Process this file with automake to produce Makefile.in

SKINS = default defwood gnome grayscale night

SKINFILES = hint.png lmb.png lmbl.png lme.png lmw.png lmwl.png ltb.png \
	ltbl.png lte.png ltw.png ltwl.png lub.png lubl.png lue.png luw.png \
	luwl.png mmb.png mmbl.png mme.png mms.png mmw.png mmwl.png mtb.png \
	mtbl.png mte.png mtw.png mtwl.png mub.png mubl.png mue.png muw.png \
	muwl.png options.png pass.png quit.png resize.png restart.png rmb.png \
	rmbl.png rme.png rmw.png rmwl.png rtb.png rtbl.png rte.png rtw.png \
	rtwl.png rub.png rubl.png rue.png ruw.png ruwl.png skin.png undo.png

# Make sure the skins are included in distribution
dist-hook:
	for skin in $(SKINS); do \
		mkdir $(distdir)/$$skin; \
		for file in $(SKINFILES); do \
			cp -p $$skin/$$file $(distdir)/$$skin/$$file; \
		done; \
	done

# Install skins
install-data-hook:
	for skin in $(SKINS); do \
		$(mkinstalldirs) $(pkgdatadir)/skins/$$skin ; \
		for file in $(SKINFILES); do \
			$(INSTALL) -m 644 $$skin/$$file $(pkgdatadir)/skins/$$skin/$$file; \
		done; \
	done
