# Найти все файлы размером от 1 до 10 МБ и вывести 5 самых тяжёлых среди них
find . -type f -size +1M -size -10M -printf '%s\t%f\n' | sort -rn | grep -o '[A-Za-z0-9]*\.[A-Za-z]*' | head -5
