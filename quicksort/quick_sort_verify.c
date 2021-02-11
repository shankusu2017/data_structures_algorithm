int check(int *start, int *tail)
{
    int *i = start;
    for(; i < tail; ++i) {
        if (*i > *(i + 1)) {
            return -1;
        }
    }

    return 0;
}
