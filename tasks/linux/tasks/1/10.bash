# Написать скрипт антивируса, который сканирует все файлы в текущей и поддиректорях на предмет файлов, содержащих следующие строки:
# Trojan
# Process
# Backdoor
#!/bin/bash

KEY_WORDS="Trojan|Process|Backdoor"

echo "=== Запуск сканирования директории на вирусы ==="
echo "Ищем: Trojan, Process, Backdoor"
echo "------------------------------------------------"

find . -type f -print0 | xargs -0 grep -lE "$KEY_WORDS" 2>/dev/null > infected_files.txt

echo "Сканирование завершено! Найденные угрозы:"
cat infected_files.txt
echo "------------------------------------------------"
