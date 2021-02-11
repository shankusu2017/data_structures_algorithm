//先序遍历-又名根优先

static void ListDir(DirectoryOrFile D, int Depth)
{
    if (D is a legitimate entry) {
        PrintName(D);                           //先处理根
        if (D is a Directory) {
            for each child C, of D {
                    ListDir(C, Depath + 1)      //再处理孩子
            }
        }
    }
}

void ListDirectory(DirectoryOrFile D)
{
    ListDir(D, 0)
}

