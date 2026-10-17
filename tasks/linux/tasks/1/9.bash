# Найти все файлы размером от 1 до 10 МБ и вывести 5 самых тяжёлых среди них
find . -type f -size +1048575c -size -10485761c -printf '%s %p\n' | sort -rn | head -5 | cut -d' ' -f2-
