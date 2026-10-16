# Выведите топ 5 файлов, в которых чаще всего встречается слово "lol"
grep -or lol | uniq -c | sort -nr | cut -c 9- | cut -d: -f1 | head -5
