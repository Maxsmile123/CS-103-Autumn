find . -type f -size +1048575c -size -104857601c -printf '%s %p\n' | sort -nr | head -n 7
