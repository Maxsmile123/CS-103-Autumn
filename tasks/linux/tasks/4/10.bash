# Выведи мне топ 5 файлов, в которых чаще всего встречается слово pizza
grep -r -H -w -o 'pizza' . | sed 's/:pizza$//' | sort | uniq -c | sort -nr | head -n 5 | sed 's/^[[:space:]]*[0-9]* //'
