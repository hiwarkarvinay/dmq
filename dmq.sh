#!/bin/bash

##### constants
FILENAME="dmq.sh"
TITLE="Snooker Player Profile Manager v0.1"

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
	if [ -z "$1" -o -z "$2" ]
	then
		echo "Error: Specify number of users and number of servers as input."
		echo "Try dmq.sh --help"
		exit
	fi
	#if [ ! -f "$1" ]
	#then
	#	echo "File \"$1\" does not exist."
	#	echo "Try dmq.sh --help"
	#	exit
	#fi
	build/dmq $1 $2 $3
}

function search
{
	if [ -z "$1" ]
	then
		echo "Error: Missing input argument."
		exit
	fi
	find . -iregex '.*\.\(cpp\|sql\|hpp\)' -exec grep -inH $1 {} \;
}

function count
{
	find . -iregex '.*\.\(cpp\|sql\|hpp\|sh\)' -exec cat {} \; | wc -l
}

function db
{
	sqlite3 --interactive -echo database/snooker.db -separator "| "
}

function usage
{
	echo $TITLE
	if [ ! -f "doc/usage.txt" ]
	then
		echo "Error: doc/usage.txt missing."
		exit
	fi
	cat doc/usage.txt
}

function dmq_main
{
	case $1 in
		-b | --build | build)
			build
			;;
		-r | --run | run)
			run $2 $3 $4
			;;
		-s | --search | search)
            search $2
			;;
		-c | --count | count)
		    count
			;;
		-db | --database | database)
		    db
			;;
		-h | --help | help)
		    usage
			;;
		*)
			echo "Error: Invalid input option."
			echo "Try dmq.sh --help"
			;;
	esac
}

#### Main
dmq_main $*
