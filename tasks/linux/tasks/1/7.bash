# Выведите топ 5 файлов, в которых чаще всего встречается слово "lol"
sudo grep -r -s -c -w -I 'lol' / | grep -v ':0$' | sort -t: -k2 -nr | head -n 5
