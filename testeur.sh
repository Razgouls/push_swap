NOCOLOR='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
LIGHTGRAY='\033[0;37m'
DARKGRAY='\033[1;30m'
LIGHTRED='\033[1;31m'
LIGHTGREEN='\033[1;32m'
YELLOW='\033[1;33m'
LIGHTBLUE='\033[1;34m'
LIGHTPURPLE='\033[1;35m'
LIGHTCYAN='\033[1;36m'
WHITE='\033[1;37m'

rm -f push_swap_result.txt

TotalNbTest=$(($1 + 0))
stack_size=$(($2 + 0))

printf "${GREEN}Generation de $TotalNbTest tests pour liste de $stack_size nombres\n\n${NOCOLOR}" >&2
for ((testNB = 0; testNB < $TotalNbTest; testNB++)); do
  	printf "${DARKGRAY} TEST $testNB: ${NOCOLOR}"
	ARG=`./genstack.pl $stack_size -500 500` ;
	"./push_swap" $ARG > push_swap_result.txt ;
	RESULT_CHECKER=`"./checker" $ARG < push_swap_result.txt`
	if [[ "$RESULT_CHECKER" = "KO" ]]; then
		printf "${RED}$RESULT_CHECKER ${NOCOLOR}"
	else
		printf "${GREEN}$RESULT_CHECKER ${NOCOLOR}"
	fi
	MOVES=` cat push_swap_result.txt | wc -l`
	if (( $stack_size <= 3 )) ; then
		if (( $MOVES < 3 )); then
			COLOR=${WHITE}
		else
			COLOR=${RED}
		fi
	elif (( $stack_size <= 5 )) ; then
		if (( $MOVES < 8 )); then
			COLOR=${WHITE}
		elif (( $MOVES == 8 )); then
			COLOR=${BLUE}
		elif (( $MOVES <= 12 )); then
			COLOR=${GREEN}
		else
			COLOR=${RED}
		fi
	elif (( $stack_size <= 100 )) ; then
		if (( $MOVES <= 700 )); then
			COLOR=${WHITE}
		elif (( $MOVES <= 900 )); then
			COLOR=${BLUE}
		elif (( $MOVES <= 1100 )); then
			COLOR=${GREEN}
		elif (( $MOVES <= 1500 )); then
			COLOR=${ORANGE}
		else
			COLOR=${RED}
		fi
	elif (( $stack_size <= 500 )) ; then
		if (( $MOVES <= 5500 )); then
			COLOR=${WHITE}
		elif (( $MOVES <= 7000 )); then
			COLOR=${BLUE}
		elif (( $MOVES <= 8500 )); then
			COLOR=${GREEN}
		elif (( $MOVES <= 11500 )); then
			COLOR=${ORANGE}
		else
			COLOR=${RED}
		fi
	fi
	printf "${COLOR} $MOVES ${NOCOLOR} instructions\n"
	TOTAL=$(( $TOTAL + $MOVES ))
  done
MEAN=$(( $TOTAL / $TotalNbTest ))
printf "\nMean: $MEAN for stack of size $stack_size \n\n" 

rm -rf push_swap_result.txt