
echo "TEST 1"

./omicron pruebas/test1.ol pruebas/test1.asm
nasm -g -o pruebas/test1.o -f elf32 pruebas/test1.asm
gcc -Wall -g  -m32 -o pruebas/test1 pruebas/test1.o pruebas/olib.o


echo "TEST 2"

./omicron pruebas/test2.ol pruebas/test2.asm
nasm -g -o pruebas/test2.o -f elf32 pruebas/test2.asm
gcc -Wall -g -m32 -o pruebas/test2 pruebas/test2.o pruebas/olib.o

echo "TEST 3"

./omicron pruebas/test3.ol pruebas/test3.asm
nasm -g -o pruebas/test3.o -f elf32 pruebas/test3.asm
gcc -Wall -g -m32 -o pruebas/test3 pruebas/test3.o pruebas/olib.o


echo "TEST 4"


./omicron pruebas/test4.ol pruebas/test4.asm
nasm -g -o pruebas/test4.o -f elf32 pruebas/test4.asm
gcc -Wall -g -m32 -o pruebas/test4 pruebas/test4.o pruebas/olib.o


echo "TEST 41"


./omicron pruebas/test41.ol pruebas/test41.asm
nasm -g -o pruebas/test41.o -f elf32 pruebas/test41.asm
gcc -Wall -g -m32 -o pruebas/test41 pruebas/test41.o pruebas/olib.o

echo "TEST 5"

./omicron pruebas/test5.ol pruebas/test5.asm
nasm -g -o pruebas/test5.o -f elf32 pruebas/test5.asm
gcc -Wall -g -m32 -o pruebas/test5 pruebas/test5.o pruebas/olib.o

echo "TEST 6"

./omicron pruebas/test6.ol pruebas/test6.asm
nasm -g -o pruebas/test6.o -f elf32 pruebas/test6.asm
gcc -Wall -g -m32 -o pruebas/test6 pruebas/test6.o pruebas/olib.o

echo "TEST 7"

./omicron pruebas/test7.ol pruebas/test7.asm
nasm -g -o pruebas/test7.o -f elf32 pruebas/test7.asm
gcc -Wall -g -m32 -o pruebas/test7 pruebas/test7.o pruebas/olib.o

echo "TEST 7-1"

./omicron pruebas/test7-1.ol pruebas/test7-1.asm

echo "TEST 7-2"

./omicron pruebas/test7-2.ol pruebas/test7-2.asm
nasm -g -o pruebas/test7-2.o -f elf32 pruebas/test7-2.asm
gcc -Wall -g -m32 -o pruebas/test7-2 pruebas/test7-2.o pruebas/olib.o

echo "TEST 7-3"

./omicron pruebas/test7-3.ol pruebas/test7-3.asm

echo "TEST 7-4"

./omicron pruebas/test7-4.ol pruebas/test7-4.asm

echo "TEST 7-5"

./omicron pruebas/test7-5.ol pruebas/test7-5.asm


echo "TEST 8"

./omicron pruebas/test8.ol pruebas/test8.asm
nasm -g -o pruebas/test8.o -f elf32 pruebas/test8.asm
gcc -Wall -g -m32 -o pruebas/test8 pruebas/test8.o pruebas/olib.o

echo "TEST 9"

./omicron pruebas/test9.ol pruebas/test9.asm
nasm -g -o pruebas/test9.o -f elf32 pruebas/test9.asm
gcc -Wall -g -m32 -o pruebas/test9 pruebas/test9.o pruebas/olib.o

echo "TEST 10"

./omicron pruebas/test10.ol pruebas/test10.asm
nasm -g -o pruebas/test10.o -f elf32 pruebas/test10.asm
gcc -Wall -g -m32 -o pruebas/test10 pruebas/test10.o pruebas/olib.o

echo "TEST 11"

./omicron pruebas/test11.ol pruebas/test11.asm
nasm -g -o pruebas/test11.o -f elf32 pruebas/test11.asm
gcc -Wall -g -m32 -o pruebas/test11 pruebas/test11.o pruebas/olib.o

echo "TEST 12"

./omicron pruebas/test12.ol pruebas/test12.asm
nasm -g -o pruebas/test12.o -f elf32 pruebas/test12.asm
gcc -Wall -g -m32 -o pruebas/test12 pruebas/test12.o pruebas/olib.o
