CXX=g++ 
INCLDIR=-I/opt/podofo/include -I/opt/local/include
CXXPATH=-I/opt/podofo/include
CXXFLAGS=-g -std=c++11  $(INCLDIR)
# LDFLAGS=-L/opt/podofo/lib -lpodofo -L/opt/local/lib -lfreetype -lfontconfig -ljpeg -lz -L/opt/local/lib/engines -lssl -lcrypto -lidn
LDFLAGS=-L/opt/podofo/lib -lpodofo -L/opt/local/lib -lfreetype -lfontconfig -ljpeg -lz  -lidn -lcrypto


# idn  _stringprep_profile
# /opt/local  for mac ports installed libraries

