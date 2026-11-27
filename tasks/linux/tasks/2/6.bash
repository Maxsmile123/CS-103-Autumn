grep '^[[:space:]]*vk\.com[[:space:]]*:' passwords.txt | cut -d ':' -f 2- | sed 's/^[[:space:]]*//'
