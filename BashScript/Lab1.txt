1- sed -n '/lp/p' /etc/passwd

2- sed '3d' /etc/passwd

3- sed '$d' /etc/passwd

4- sed '/lp/d' /etc/passwd

5- 


-------------------------------------

Awk

1- awk -F: '{print $5}' /etc/passwd

2- awk -F: '{print NR, $1, $5, $6}' /etc/passwd

3- awk -F: '$3 > 500 {print $1, $3, $5}' /etc/passwd

4- awk -F: '$3 == 500 {print $1, $3, $5}' /etc/passwd

5- awk 'NR >= 5 && NR <= 15' /etc/passwd

6- awk '{gsub(/lp/, "mylp"); print}' /etc/passwd

7- awk -F: 'BEGIN {max_uid = -1} {if ($3 > max_uid) {max_uid = $3; line = $0}} END {print line}' /etc/passwd

8- the Picture