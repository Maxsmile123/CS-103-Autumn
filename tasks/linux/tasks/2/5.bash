# Выведите топ 7 самых тяжёлых файлов в диапазоне от 1 до 100 МВ
find . -type f -size +1M -size -100M -exec ls -s {} + | sort -n -r | head -n 7
