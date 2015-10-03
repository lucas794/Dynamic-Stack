# Dynamic-Stack
Dynamic Stac is a linear data structure in which insertion and deletion of elements takes place only one end known as TOP.

Compile commands:
    gcc -g -std=c99 -Wall -Wconversion -Wtype-limits -Wbad-function-cast -Wshadow -Wpointer-arith -Wunreachable-code -pedantic -Werror -MMD *.c -o out

Valgrind:
    valgrind -v --leak-check=full --show-leak-kinds=all ./out

==5648== Memcheck, a memory error detector
==5648== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==5648== Using Valgrind-3.10.0.SVN and LibVEX; rerun with -h for copyright info
==5648== Command: ./out
==5648== 
--5648-- Valgrind options:
--5648--    -v
--5648--    --leak-check=full
--5648--    --show-leak-kinds=all
--5648-- Contents of /proc/version:
--5648--   Linux version 3.16.0-46-generic (buildd@lgw01-57) (gcc version 4.8.2 (Ubuntu 4.8.2-19ubuntu1) ) #62~14.04.1-Ubuntu SMP Tue Aug 11 16:27:16 UTC 2015
--5648-- Arch and hwcaps: AMD64, amd64-cx16-lzcnt-rdtscp-sse3-avx-avx2-bmi
--5648-- Page sizes: currently 4096, max supported 4096
--5648-- Valgrind library directory: /usr/lib/valgrind
--5648-- Reading syms from /home/lucas/Escritorio/FIUBA/Algoritmos y Programacion II (75.41)/Pila Dinámica/out
--5648-- Reading syms from /lib/x86_64-linux-gnu/ld-2.19.so
--5648--   Considering /lib/x86_64-linux-gnu/ld-2.19.so ..
--5648--   .. CRC mismatch (computed 4cbae35e wanted 8d683c31)
--5648--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/ld-2.19.so ..
--5648--   .. CRC is valid
--5648-- Reading syms from /usr/lib/valgrind/memcheck-amd64-linux
--5648--   Considering /usr/lib/valgrind/memcheck-amd64-linux ..
--5648--   .. CRC mismatch (computed 37cdde19 wanted adc367dd)
--5648--    object doesn't have a symbol table
--5648--    object doesn't have a dynamic symbol table
--5648-- Scheduler: using generic scheduler lock implementation.
--5648-- Reading suppressions file: /usr/lib/valgrind/default.supp
==5648== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-5648-by-lucas-on-???
==5648== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-5648-by-lucas-on-???
==5648== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-5648-by-lucas-on-???
==5648== 
==5648== TO CONTROL THIS PROCESS USING vgdb (which you probably
==5648== don't want to do, unless you know exactly what you're doing,
==5648== or are doing some strange experiment):
==5648==   /usr/lib/valgrind/../../bin/vgdb --pid=5648 ...command...
==5648== 
==5648== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==5648==   /path/to/gdb ./out
==5648== and then give GDB the following command
==5648==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=5648
==5648== --pid is optional if only one valgrind process is running
==5648== 
--5648-- REDIR: 0x4019ca0 (strlen) redirected to 0x38068331 (???)
--5648-- Reading syms from /usr/lib/valgrind/vgpreload_core-amd64-linux.so
--5648--   Considering /usr/lib/valgrind/vgpreload_core-amd64-linux.so ..
--5648--   .. CRC mismatch (computed 329d6860 wanted c0186920)
--5648--    object doesn't have a symbol table
--5648-- Reading syms from /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so
--5648--   Considering /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so ..
--5648--   .. CRC mismatch (computed 1fb85af8 wanted 2e9e3c16)
--5648--    object doesn't have a symbol table
==5648== WARNING: new redirection conflicts with existing -- ignoring it
--5648--     old: 0x04019ca0 (strlen              ) R-> (0000.0) 0x38068331 ???
--5648--     new: 0x04019ca0 (strlen              ) R-> (2007.0) 0x04c2e1a0 strlen
--5648-- REDIR: 0x4019a50 (index) redirected to 0x4c2dd50 (index)
--5648-- REDIR: 0x4019c70 (strcmp) redirected to 0x4c2f2f0 (strcmp)
--5648-- REDIR: 0x401a9c0 (mempcpy) redirected to 0x4c31da0 (mempcpy)
--5648-- Reading syms from /lib/x86_64-linux-gnu/libc-2.19.so
--5648--   Considering /lib/x86_64-linux-gnu/libc-2.19.so ..
--5648--   .. CRC mismatch (computed dc620abc wanted 148cbd6e)
--5648--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/libc-2.19.so ..
--5648--   .. CRC is valid
--5648-- REDIR: 0x4ec3d60 (strcasecmp) redirected to 0x4a25720 (_vgnU_ifunc_wrapper)
--5648-- REDIR: 0x4ec6050 (strncasecmp) redirected to 0x4a25720 (_vgnU_ifunc_wrapper)
--5648-- REDIR: 0x4ec3530 (memcpy@GLIBC_2.2.5) redirected to 0x4a25720 (_vgnU_ifunc_wrapper)
--5648-- REDIR: 0x4ec17c0 (rindex) redirected to 0x4c2da30 (rindex)
--5648-- REDIR: 0x4ebfac0 (strlen) redirected to 0x4c2e0e0 (strlen)
~~~ PRUEBAS ALUMNO ~~~
--5648-- REDIR: 0x4ecaac0 (strchrnul) redirected to 0x4c319b0 (strchrnul)
Puntero inicializado a NULL... OK

Prueba pila EJEMPLO (null) Apilar es falso...... OK
Prueba pila EJEMPLO (null) Desapilar es NULL...... OK
Prueba pila EJEMPLO (null) Ver tope es NULL... ... OK
Prueba pila EJEMPLO (null) Pila vacia?..... OK
--5648-- REDIR: 0x4eb9750 (malloc) redirected to 0x4c2ab10 (malloc)

Prueba pila 1 - Nueva pila de enteros (infima) creada! ¿Distinto de NULL? ...... OK
Prueba pila 1 Apilar elemento 5...... OK
Prueba pila 1 Apilar elemento 22...... OK
Prueba pila 1 Apilar elemento 36...... OK
Prueba pila 1 Apilar elemento 512...... OK
Prueba pila 1 ¿La pila, NO está vacia? ...... OK
Prueba pila 1 ¿El tope es la referencia a 512? ... ... OK
--5648-- REDIR: 0x4eb9ef0 (realloc) redirected to 0x4c2ce10 (realloc)
Prueba pila 1 Desapilando valor, ¿Es la referencia a 512?... OK
Prueba pila 1 Desapilando valor, ¿Es la referencia a 36?... OK
Prueba pila 1 Desapilando valor, ¿Es la referencia a 22?... OK
Prueba pila 1 Desapilando valor, ¿Es la referencia a 5?... OK
Prueba pila 1La pila está vacia?...... OK
Prueba pila 1 El tope es NULL? ... ... OK
--5648-- REDIR: 0x4eb9df0 (free) redirected to 0x4c2bd80 (free)
Prueba pila 1 Destruir la pila de enteros (infima)...... OK

Prueba pila 2 Nueva pila de enteros con volumen creada!, ¿Distinto de NULL?...... OK
Prueba pila 2 Desapilar es NULL...... OK
Prueba pila 2 Ver tope es NULL... ... OK
Prueba pila 2 Pila vacia?..... OK
Prueba pila 2 ¿Se pudieron apilar todos los elementos? ... ... OK
Prueba pila 2 El tope es la referencia a 49999? ...... OK
Prueba pila 2 La pila NO esta vacia?...... OK
Prueba pila 2 se pudieron obtener todos los elementos... OK
Prueba pila 2 Destruir la pila masiva de enteros...... OK

Prueba pila 3 Nueva pila de cadenas creada!, ¿Distinto de NULL?...... OK
Prueba pila 3 Desapilar es NULL...... OK
Prueba pila 3 Ver tope es NULL... ... OK
Prueba pila 3 Pila vacia?..... OK
Prueba pila 3 Apilar la referencia de szDocentesParaApilar?...... OK
Prueba pila 3 Desapilar la referencia en pila coincide con el vector de docentes?...... OK
Prueba pila 3 ¿Se pudieron apilar todos los profesores? ... ... OK
Prueba pila 3 El tope es la referencia a nacho??? ...... OK
Prueba pila 3 La pila NO esta vacia?...... OK
Prueba pila 3 se pudieron obtener todos los elementos... OK
Prueba pila 3 Destruir la pila de cadenas...... OK
Prueba pila 4 apilar NULL... ... OK
Prueba pila 4 pila NO vacia?? ...... OK
Prueba pila 4 desapilar es NULL...... OK
Prueba pila 4 pila VACIA??? ... ... OK

Al comparar malloc con la salida de la pila es...... OK
==5648== 
==5648== HEAP SUMMARY:
==5648==     in use at exit: 0 bytes in 0 blocks
==5648==   total heap usage: 43 allocs, 43 frees, 1,233,556 bytes allocated
==5648== 
==5648== All heap blocks were freed -- no leaks are possible
==5648== 
==5648== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
==5648== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
