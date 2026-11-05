# Антифлуд: найти файлы, в которых используются матерные слова: fuck, ass, shit.
sudo grep -r -l -i -w -I -e 'fuck' -e 'ass' -e 'shit' /
