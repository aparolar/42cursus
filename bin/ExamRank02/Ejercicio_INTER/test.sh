gcc -Wall -Werror -Wextra inter.c -o inter
echo "# Expected result (next line) Your result #"
echo "---"
echo "padinto$"
./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
echo "---"
echo "df6ewg4$"
./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
echo "---"
echo "nothig$"
./inter "nothing" "This sentence hides nothing" | cat -e
echo "---"
echo "$"
./inter | cat -e
echo "---"
echo "$"
./inter "rien" | cat -e
rm -rf inter
