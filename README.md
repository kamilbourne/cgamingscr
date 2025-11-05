# ScreenSaver created by the CGaming Association Team
# Authors: K. Nowak, R. Michaluszko
## How to compile for windows.
1. Download MingW64 portable.
2. Unpack the MingW64
3. Add path to system Path (Start->System Variables->Path->Edit->New->Browse, navigate where MingW is extracted, open bin folder), if your libscrnsave.a file in lib folder is less than 1KB go to the next step, if not skip to point 5.
4. Download MingW source and extract '''scrnsave.c''' from archive, compile it with '''gcc -c scrnsave.c -o scrnsave.o''', then create static library with '''ar rcs libscrnsave.a scrnsave.o'''
5. Download '''cgamingscr.cpp''' source file.
6. Compile with '''g++ cgascr.cpp -o cgascr.scr -luser32 -lgdi32 -lglu32 -lopengl32 -lscrnsave -Wl,--subsystem,windows''' command
7. Test/Run/Install

### Extra
- If you have sublime installed, press ctrl+shift+P and type ViewPackage, choose c++ single file, copy the contents and add new build system with modified command as above