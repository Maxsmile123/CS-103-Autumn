# Изменить расширение всех txt файлов в формат md
for f in $(find -name "*.txt") ; do mv "$f" "${f%txt}md" ; done
