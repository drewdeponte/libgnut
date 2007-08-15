#!/bin/sh
#
# NOTE: DO NOT RUN THIS SCRIPT UNLESS YOU KNOW WHAT YOU ARE DOING
#
# Author: Andrew De Ponte <cyphactor@socal.rr.com>
# Description:  This is a script which I wrote to assist in my testing of
#               the build environment for this project. It removes all
#               the extra files generated by the build environment on my
#               system putting it in the original state before running
#               autoreconf. The files produced on your system may very
#               well be different. I do NOT recommend using this script.
#               There is NO reason what so ever that an end user should
#               need to use this script.
# Note: If ./configure has been run, this script should only be run
#       after first running "make clean" and "make distclean".

rm -rf autom4te.cache/
rm -f configure
rm -f config.log
rm -f config.status
rm -f src/config.h
rm -f src/config.h.in
rm -f aclocal.m4
rm -f config.guess
rm -f config.sub
rm -f depcomp
rm -f install-sh
rm -f ltmain.sh
rm -f missing
rm -f Makefile.in
rm -f src/Makefile.in
#rm -f testing/Makefile.in
rm -f src/*~
