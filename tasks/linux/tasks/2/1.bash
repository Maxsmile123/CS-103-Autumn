for file in *.txt; do
    [ -f "$file" ] || continue
    mv -- "$file" "${file%.txt}.md"
