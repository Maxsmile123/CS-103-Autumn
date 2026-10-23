# Выведи мне топ 5 файлов, в которых чаще всего встречается слово pizza
grep -rcw "pizza" . | sort -t: -k2 -nr | head -5 | grep -o '^[^:]*'