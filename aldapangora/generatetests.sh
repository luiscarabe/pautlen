./omicron pruebas/test1.ol pruebas/test1.asm
nasm -g -o pruebas/test1.o -f elf32 pruebas/test1.asm
gcc -Wall -g  -m32 -o pruebas/test1 pruebas/test1.o pruebas/olib.o

./omicron pruebas/test2.ol pruebas/test2.asm
nasm -g -o pruebas/test2.o -f elf32 pruebas/test2.asm
gcc -Wall -g -m32 -o pruebas/test2 pruebas/test2.o pruebas/olib.o

./omicron pruebas/test3.ol pruebas/test3.asm
nasm -g -o pruebas/test3.o -f elf32 pruebas/test3.asm
gcc -Wall -g -m32 -o pruebas/test3 pruebas/test3.o pruebas/olib.o

./omicron pruebas/test4.ol pruebas/test4.asm
nasm -g -o pruebas/test4.o -f elf32 pruebas/test4.asm
gcc -Wall -g -m32 -o pruebas/test4 pruebas/test4.o pruebas/olib.o


./omicron pruebas/test41.ol pruebas/test41.asm
nasm -g -o pruebas/test41.o -f elf32 pruebas/test41.asm
gcc -Wall -g -m32 -o pruebas/test41 pruebas/test41.o pruebas/olib.o

./omicron pruebas/test5.ol pruebas/test5.asm
nasm -g -o pruebas/test5.o -f elf32 pruebas/test5.asm
gcc -Wall -g -m32 -o pruebas/test5 pruebas/test5.o pruebas/olib.o

./omicron pruebas/test6.ol pruebas/test6.asm
nasm -g -o pruebas/test6.o -f elf32 pruebas/test6.asm
gcc -Wall -g -m32 -o pruebas/test6 pruebas/test6.o pruebas/olib.o

./omicron pruebas/test7.ol pruebas/test7.asm
nasm -g -o pruebas/test7.o -f elf32 pruebas/test7.asm
gcc -Wall -g -m32 -o pruebas/test7 pruebas/test7.o pruebas/olib.o
