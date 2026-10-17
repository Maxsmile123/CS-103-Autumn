# Сожмите архив trash.tar с максимальной степенью сжатия
mkdir ttrr && tar xvf trash.tar -C ttrr/ && tar cJvf trash.tar.xz -C ttrr/ . && rm -rf ttrr
