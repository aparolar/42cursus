echo -en "Colors\n";
for COLOR in {1..255};
do
	echo -en "\033[38;5;${COLOR}m1-${COLOR} ";
	tput sgr0;
done;
echo;
echo -en "Styles\n";
for OPT1 in {1..1}
do
	for OPT2 in {1..47};
	do
		echo -en "\033[${OPT};${OPT2}m${OPT1}-${OPT2} ";
		tput sgr0;
	done;
done;
echo;
