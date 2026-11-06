# Выведите топ 7 самых тяжёлых файлов в диапазоне от 1 до 100 МВ

find . -type f -size +1048576c -size -104857600c -printf '%s %p\n' | sort -rn | head -n 7