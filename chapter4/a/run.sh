#!/bin/sh

# Author : jackson sang
# toy script

sudo mount a.img -o loop /mnt/floppy
for f in *.asm;
do
	nasm "${f}" -o "${f%.asm}.com"
	if [ $? -ne 0 ]; 
	then
		sudo umount /mnt/floppy
    		echo "Failed to assemble!!!"
    		exit 1
	fi
	sudo cp  "${f%.asm}.com" /mnt/floppy
	rm "${f%.asm}.com"
done

sudo umount /mnt/floppy
bochs
