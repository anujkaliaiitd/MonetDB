# The contents of this file are subject to the MonetDB Public
# License Version 1.0 (the "License"); you may not use this file
# except in compliance with the License. You may obtain a copy of
# the License at
# http://monetdb.cwi.nl/Legal/MonetDBLicense-1.0.html
# 
# Software distributed under the License is distributed on an "AS
# IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
# implied. See the License for the specific language governing
# rights and limitations under the License.
# 
# The Original Code is the Monet Database System.
# 
# The Initial Developer of the Original Code is CWI.
# Portions created by CWI are Copyright (C) 1997-2004 CWI.
# All Rights Reserved.
# 
# Contributor(s):
# 		Martin Kersten <Martin.Kersten@cwi.nl>
# 		Peter Boncz <Peter.Boncz@cwi.nl>
# 		Niels Nes <Niels.Nes@cwi.nl>
# 		Stefan Manegold  <Stefan.Manegold@cwi.nl>

# make rules to generate MonetDB RPMs (works on RedHat Linux, only)

rpmtopdir = $(shell cd $(top_builddir) && pwd)/rpm

$(top_builddir)/$(distdir).tar.gz:
	$(MAKE) $(AM_MAKEFLAGS) dist

rpm:	MonetDB-SQL.spec $(top_builddir)/$(distdir).tar.gz

	mkdir -p $(rpmtopdir)/RPMS
	mkdir -p $(rpmtopdir)/SRPMS
	mkdir -p $(rpmtopdir)/SPECS
	mkdir -p $(rpmtopdir)/BUILD
	mkdir -p $(rpmtopdir)/INSTALL

	echo "macrofiles: /usr/lib/rpm/macros:/usr/lib/rpm/%{_target}/macros:/etc/rpm/macros.specspo:/etc/rpm/macros.prelink:/etc/rpm/macros.solve:/etc/rpm/macros.up2date:/etc/rpm/macros:/etc/rpm/%{_target}/macros:$(rpmtopdir)/rpmmacros" > $(rpmtopdir)/rpmrc

	echo "%_tmppath          /tmp"                >  $(rpmtopdir)/rpmmacros
	echo "%_topdir           $(rpmtopdir)"        >> $(rpmtopdir)/rpmmacros
	echo "%tmpdir            %{_tmppath}"         >> $(rpmtopdir)/rpmmacros
	echo "%rpmcflags         -O2 "                >> $(rpmtopdir)/rpmmacros
	echo "#%top_builddirroot %{_topdir}/INSTALL/" >> $(rpmtopdir)/rpmmacros

	$(RPMBUILD) --rcfile $(rpmtopdir)/rpmrc -ta $(top_builddir)/$(distdir).tar.gz

	rm -rf $(rpmtopdir)/BUILD
