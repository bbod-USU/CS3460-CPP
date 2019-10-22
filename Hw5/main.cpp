#include "WordTree.hpp"
#include "rlutil.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
int main()
{
    WordTree mytree;
    std::shared_ptr<WordTree> tree = mytree.readDictionary("dictionary.txt");

    std::string input;
    int position = 0;
    while (true)
    {
        auto tmp = rlutil::getkey();
        rlutil::cls();
        rlutil::locate(0, 0);

        if (tmp == rlutil::KEY_BACKSPACE)
        {
            if (!input.empty())
            {
                input.pop_back();
                position--;
            }
        }
        else if (tmp == rlutil::KEY_DELETE)
        {
            input.clear();
            position = 0;
        }
        else if ((tmp >= 'a' && tmp <= 'z') || " ")
        {
            input += tmp;
            position++;
        }
        std::cout << input << std::endl;

        int i = input.length() - 1; // last character
        while (i != 0 && !isspace(input[i]))
        {
            --i;
        }
        std::string lastword = input.substr(i + 1);

        auto words = tree->predict(lastword, rlutil::trows() - 3);
        std::cout << "-----prediction-----" << std::endl;
        for (auto word : words)
        {
            std::cout << word << std::endl;
        }
        rlutil::locate(position + 1, 0);
    }
    return 0;
}
#pragma clang diagnostic pop
