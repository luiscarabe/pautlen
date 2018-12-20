./omicron tests/test1.ol tests/test1.asm
nasm -g -o tests/test1.o -f elf32 tests/test1.asm
gcc -Wall -g  -m32 -o tests/test1 tests/test1.o tests/olib.o 

./omicron tests/test2.ol tests/test2.asm
nasm -g -o tests/test2.o -f elf32 tests/test2.asm
gcc -Wall -g -m32 -o tests/test2 tests/test2.o tests/olib.o 

./omicron tests/test3.ol tests/test3.asm
nasm -g -o tests/test3.o -f elf32 tests/test3.asm
gcc -Wall -g -m32 -o tests/test3 tests/test3.o tests/olib.o 

./omicron tests/test4.ol tests/test4.asm
nasm -g -o tests/test4.o -f elf32 tests/test4.asm
gcc -Wall -g -m32 -o tests/test4 tests/test4.o tests/olib.o 


./omicron tests/test41.ol tests/test41.asm
nasm -g -o tests/test41.o -f elf32 tests/test41.asm
gcc -Wall -g -m32 -o tests/test41 tests/test41.o tests/olib.o

./omicron tests/test5.ol tests/test5.asm
nasm -g -o tests/test5.o -f elf32 tests/test5.asm
gcc -Wall -g -m32 -o tests/test5 tests/test5.o tests/olib.o 

./omicron tests/test6.ol tests/test6.asm
nasm -g -o tests/test6.o -f elf32 tests/test6.asm
gcc -Wall -g -m32 -o tests/test6 tests/test6.o tests/olib.o 

./omicron tests/test7.ol tests/test7.asm
nasm -g -o tests/test7.o -f elf32 tests/test7.asm
gcc -Wall -g -m32 -o tests/test7 tests/test7.o tests/olib.o 
