# Сожмите архив trash.tar с максимальной степенью сжатия
tar -I 'gzip -9' -cf trash.tar.gz trash.tar
