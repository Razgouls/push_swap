#!/bin/bash

FAIL=0
Ntest=100
limit5=12
limit3=3
RED="\e[91m"
GREEN="\e[92m"
RESET="\e[0m"
WHITE="\e[97m"

get_limit()
{
	if (($1 < 4)) ; then
		limit=3
	elif (($1 < 6)) ; then
		limit=12
	elif (($1 < 101)) ; then
		limit=700
	elif (($1 < 501)) ; then
		limit=5500
	else
		Ntest=1
		limit=1000000
	fi
}

test()
{
	local j=0
	FAIL=0
	TOTALSCORE=0
	TOTALTIME=0
	get_limit $1
	printf "%-18s %-20s" "Test $1x $Ntest " "| limite $limit   "
	SPIN_ID=$!
	while ((j < $Ntest))
	do
	ts=$(date +%s%N)
	SECOND=0
	#v=$(./push_swap -r $1 | wc -l)
	v=$(./push_swap $(./genstack.pl $1 -1000 1000) | wc -l)
	((TOTALSCORE+=$v))
	if (( $v > $limit ))
	then
	((FAIL+=1))
	fi
	((j+=1))
	done
	check_fail
}

check_fail()
{
	if (($FAIL))
	then
	echo -ne "\b\b${RED}[KO] $FAIL fails $RESET"
	else
	echo -ne "\b\b${GREEN}[OK] $RESET"
	fi
	echo -e "average ${WHITE} $(($TOTALSCORE / $Ntest)) in $((TOTALTIME))ms"
}

if (($1))
then
	test $1
else
	printf "%10s\e[100m%s\e[49m\n" "" "START WITH $Ntest Tests"
	printf "%30s\n" "-------------------------------------------"
	test 3
	test 5
	test 100
	test 500
fi
