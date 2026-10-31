grep -rcw "pizza" . | sort -t: -k2 -nr | head -5 | grep -o '^[^:]*'
