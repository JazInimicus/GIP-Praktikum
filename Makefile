CXX = cl
CXXFLAGS = /EHsc /nologo
LD = link
LDFLAGS = /nologo
MAIN_EXECUTABLE = main.exe

.PHONY: all clean distclean

all: $(MAIN_EXECUTABLE)

clean:
	del *.obj

distclean: clean
	del $(MAIN_EXECUTABLE)

$(MAIN_EXECUTABLE): main.obj sort.obj
	$(LD) $(LDFLAGS) $^ /OUT:$@

%.obj: %.cpp
	$(CXX) $(CXXFLAGS) /c $<