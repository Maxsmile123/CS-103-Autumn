'''
Найдите все адреса эл.почты в домене gmail.com в файле personal.txt. Напомню, как выглядят адреса:
hey.uy@gmail.com
NiceTask@gmail.com
'''
egrep -o "[a-zA-Z0-9._-]+@gmail.com" personal.txt
