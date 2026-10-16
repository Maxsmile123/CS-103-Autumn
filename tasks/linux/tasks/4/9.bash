# Выведите 5 строчек после слова eth0/enp0s3 при выводе команды ifconfig
ifconfig | grep -E -m 1 -A 5 'eth0|enp0s3' | tail -n +2
