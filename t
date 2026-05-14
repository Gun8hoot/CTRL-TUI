/usr/bin/ld: objects/classes/termManager.o: warning: relocation against `_ZN11termManager9altBufferE' in read-only section `.text'
/usr/bin/ld: objects/classes/termManager.o: in function `termManager::termManager()':
xxxxxxxxx/sources/classes/termManager.cpp:6:(.text+0xe): undefined reference to `termManager::altBuffer'
/usr/bin/ld: objects/classes/termManager.o: in function `termManager::signalAltBuffer(int)':
xxxxxxxxx/sources/classes/termManager.cpp:68:(.text+0x287): undefined reference to `termManager::altBuffer'
/usr/bin/ld: warning: creating DT_TEXTREL in a PIE
collect2: error: ld returned 1 exit status
make: *** [Makefile:24: ctrl-tui] Error 1
