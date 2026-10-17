# Найдите все py файлы, содержащие в названии любое из трёх слов: backdoor, trojan, keylogger
find . -type f -name '*.py' \( -name '*backdoor*' -o -name '*trojan*' -o -name '*keylogger*' \)
