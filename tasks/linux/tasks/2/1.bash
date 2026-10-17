# Изменить расширение всех txt файлов в формат md
for file in $(find . -name "*.txt");do
	mv "$file" "${file%.txt}.md"
done
