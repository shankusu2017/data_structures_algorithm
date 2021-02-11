//后序遍历
static void SizeOfDirectory(DirectoryOrFile D)
{
    int TotalSize = 0;
    if (D is legitimate entry) {
        TotalSize = FileSize(D);
        if (D is a directory) {
            for each child C, of D {
                TotalSize += SiezeOfDirectory(C)
            }
        }
    }
    return TotalSize;
}
