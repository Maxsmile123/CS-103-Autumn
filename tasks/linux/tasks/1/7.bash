# Выведите топ 5 файлов, в которых чаще всего встречается слово "lol"
grep -row 'lol' . | cut -d: -f1 | sort | uniq -c | sort -rn | head -5
