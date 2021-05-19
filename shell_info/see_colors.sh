echo -en "Colors\n";
for COLOR in {1..255};
do
	echo -en "\033[38;5;${COLOR}m1-${COLOR} ";
	tput sgr0;
done;
echo;
echo -en "Styles\n";
for OPT0 in {1..38}
do
	for OPT1 in {1..9}
	do
		for OPT2 in {1..47};
		do
			echo -en "\033[${OPT0};${OPT1};${OPT2}m[${OPT0}-${OPT1}-${OPT2}] ";
			tput sgr0;
		done;
		#sleep 5;
	done;
done;
echo;
