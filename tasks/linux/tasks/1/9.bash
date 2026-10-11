# Найти все файлы размером от 1 до 10 МБ и вывести 5 самых тяжёлых среди них
sudo find / -type f -size +1M -size -10M -exec ls -l {} + | sort -k5 -nr | head -n 5
