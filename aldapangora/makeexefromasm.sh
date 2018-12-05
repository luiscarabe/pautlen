ASMFILE=$1
NAME='echo "$ASMFILE' | cut -d'.' -f1'
nasm -g -felf32 ASMFILE
OBJ='$NAME.o'
gcc -m32 -o programa -g olib.o OBJ


