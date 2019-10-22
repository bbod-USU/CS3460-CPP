#include "WordTree.hpp"
#include "rlutil.h"

int main()
{
    WordTree mytree;
    std::shared_ptr<WordTree> tree = mytree.readDictionary("dictionary.txt");
    //    mytree.add("whats");
    //    mytree.add("up");
    //    mytree.add("mother");
    //    mytree.add("fucker");
    //tree->readDictionary("dictionary.txt");
    std::string input;
    while ()
    {
        auto tmp = rlutil::getkey();
        switch (tmp)
        {
            case rlutil::KEY_BACKSPACE:
            {
                if (!input.empty())
                {
                    input.erase(input.size());
                }
            }
            case rlutil::KEY_DELETE:
            {
                std::cout << "IM HERE" << std::endl;
                input.clear();
            }
            default:
            {
                rlutil::setChar(tmp);
                input += tmp;

            }
        }
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
