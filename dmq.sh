#!/bin/bash

##### constants
FILENAME="dmq.sh"
TITLE="Distributed Messaging Queue v0.1"

#### functions
function build
{
	echo "Building code..."
	mkdir -p build/
	cd build;
	cmake ..
	make
}

function run
{
    build/dmq
}

function search
{
	find . -iregex '.*\.\(cpp\|sql\|hpp\)' -exec grep -inH $1 {} \;
}

function count
{
	find . -iregex '.*\.\(cpp\|sql\|hpp\)' -exec cat {} \; | wc -l
}

function usage
{
	echo $TITLE
	cat doc/usage.txt
}

function dmq_main
{
	# TODO: Replace with better parsing
	# https://gist.github.com/jehiah/855086
	if [ -n "$1" ]
	then
		if [ $1 = "-b" -o $1 = "--build" -o $1 = "build" ];
		then
			build
		elif [ $1 = "-r" -o $1 = "--run" -o $1 = "run" ];
		then
			#if [ -n "$2" ]
			#then
            run
			#else
			#	echo "Error: Missing input argument."
			#	usage
			# fi
		elif [ $1 = "-s" -o $1 = "--search" -o $1 = "search" ];
		then
			search $2
		elif [ $1 = "-c" -o $1 = "--count" -o $1 = "count" ];
		then
			count
		elif [ $1 = "-h" -o $1 = "--help" -o $1 = "help" ];
		then
			usage
		else
			echo "Error:Invalid input option."
			echo "Try: dmq.sh --help"
		fi
	else
		echo "Error: Missing input option."
		echo "Try: dmq.sh --help"
	fi
}

#### Main
dmq_main $*
