awk 'BEGIN {
    count=0
} {
    ++count;
    if(count==10) print $0
}
' file.txt
