AUTOMAKE_OPTIONS=foreign
SUBDIRS = ferro

ACLOCAL_AMFLAGS = -I m4
AM_CXXFLAGS=$(BOOST_CPPFLAGS)
AM_CPPFLAGS=-I$(top_srcdir)/ferro
AM_LDFLAGS=$(BOOST_LDFLAGS)

EASYBMP_SRCS=EasyBMP.cpp EasyBMP.h EasyBMP_BMP.h EasyBMP_DataStructures.h EasyBMP_VariousBMPutilities.h

RESOURCE_SRCS=CLUTResource.h CLUTResource.cpp PICTResource.h PICTResource.cpp SndResource.h SndResource.cpp $(EASYBMP_SRCS)

EXTRA_DIST=atque.wxg atque.icns Atque-Info.plist EasyBMP_License.txt COPYING.txt atque.xcodeproj/project.pbxproj atque.rc atque.ico README.txt atque.png

if BUILD_ATQUEGUI
if MAKE_WINDOWS
bin_PROGRAMS=atques atquem Atque
else
bin_PROGRAMS=atques atquem atque
endif
else
bin_PROGRAMS=atques atquem
endif

atques_SOURCES=atques.cpp split.cpp split.h filesystem.h $(RESOURCE_SRCS) 
atques_LDADD = ferro/libferro.a

atquem_SOURCES=atquem.cpp merge.cpp merge.h filesystem.h $(RESOURCE_SRCS)
atquem_LDADD = ferro/libferro.a

if BUILD_ATQUEGUI
ATQUE_SOURCES=atque.h atque.cpp split.cpp split.h merge.cpp merge.h filesystem.h $(RESOURCE_SRCS)
if MAKE_WINDOWS
atque-resources.o: $(srcdir)/atque.rc
	@WX_RESCOMP@ -i $^ -O coff -o $@
Atque_LDADD=atque-resources.o ferro/libferro.a
Atque_SOURCES=$(ATQUE_SOURCES)
else
atque_SOURCES=$(ATQUE_SOURCES)
atque_LDADD=ferro/libferro.a
endif
endif
