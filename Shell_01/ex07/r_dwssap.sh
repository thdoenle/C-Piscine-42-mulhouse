cat /etc/passwd | grep -v '#' | awk -F ':' 'NR % 2 == 0 { print $1 }' | rev | sort -r | awk "$FT_LINE1 <= NR && NR <= $FT_LINE2 { print }" | awk 1 ORS=', ' | sed 's/..$/./' | tr -d '\n'
