BEGIN {
    FS=""
}
{
    for (i = 1 ; i <= NF; i++) {
        printf("%d, ", $i);
    }
    printf("\n");    
}