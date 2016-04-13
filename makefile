##########################################
# makefile
# Katie Underwood
##########################################


all : useb4

#Note: use -g option to include debug info for use in gdb

useb4 : usebefore.c
	gcc -Wall -lm -ggdb3 -o useb4 usebefore.c

#Clean up binary filess, emacs autosave files
clean 	: 
	@/bin/rm -f *~
	@/bin/rm -f useb4


friends:
	@echo Hey kid, I\'m a computer

