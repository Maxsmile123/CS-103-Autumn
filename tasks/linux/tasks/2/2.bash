# Создать файлы формата txt, в которых название - одна каждая буква латинского алфавита:
# Example: a.txt, b.txt... z.txt
ALF="qazwsxedcrfvtgbyhnujmikolp"
for i in {1..26};do
	touch "${ALF:i:1}.txt"
done
