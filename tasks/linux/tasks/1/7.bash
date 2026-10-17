# Выведите топ 5 файлов, в которых чаще всего встречается слово "lol"
grep -ro "lol" . | cut -d: -f1 | sort | uniq -c | sort -nr | head -n 5
