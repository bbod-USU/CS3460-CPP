//
// Created by Brady Bodily on 10/20/19.
//
#include "WordTree.hpp"

TreeNode::TreeNode()
{
    endOfWord = false;
    for (auto& child : children)
    {
        child = nullptr;
    }
}

std::shared_ptr<WordTree> WordTree::readDictionary(std::string filename)
{
    auto wordTree = std::make_shared<WordTree>();
    std::ifstream inFile = std::ifstream(filename, std::ios::in);

    while (!inFile.eof())
    {
        std::string word;
        std::getline(inFile, word);
        // Need to consume the carriage return character for some systems, if it
        // exists
        if (!word.empty() && word[word.size() - 1] == '\r')
        {
            word.erase(word.end() - 1);
        }
        // Keep only if everything is an alphabetic character -- Have to send
        // isalpha an unsigned char or it will throw exception on negative values;
        // e.g., characters with accent marks.
        if (std::all_of(word.begin(), word.end(),
                        [](unsigned char c) { return std::isalpha(c); }))
        {
            std::transform(word.begin(), word.end(), word.begin(),
                           [](char c) { return static_cast<char>(std::tolower(c)); });
            wordTree->add(word);
        }
    }

    return wordTree;
}

std::vector<std::string> WordTree::predict(std::string partial,
                                           std::uint8_t howMany)
{
    transform(partial.begin(), partial.end(), partial.begin(), ::tolower);

    bool isValid = true;
    std::shared_ptr<TreeNode> current = root;
    std::vector<std::string> return_words;
    if (partial.empty())
    {
        return return_words;
    }
    for (auto& letter : partial)
    {
        if (current->children[letter % 'a'] == nullptr)
        {
            isValid = false;
            break;
        }
        current = current->children[letter % 'a'];
    }
    if (isValid)
    {
        std::queue<
            std::tuple<std::shared_ptr<TreeNode>, std::string>>
            queue;

        queue.push(make_tuple(current, partial));
        bool firstWord = true;
        while (!queue.empty())
        {
            if (partial.empty())
            {
                break;
            }
            auto first = std::get<0>(queue.front());
            auto second = std::get<1>(queue.front());
            if (first->endOfWord && !firstWord)
            {
                return_words.push_back(second);
            }

            for (int i = 0; i < first->children.size(); i++)
            {
                if (first->children[i] != nullptr)
                {
                    std::string tmpStr;
                    tmpStr.append(second.begin(), second.end());
                    tmpStr += ('a' + i);
                    queue.push(make_tuple(first->children[i], tmpStr));
                }
            }
            firstWord = false;
            queue.pop(); //it like its hot.
            if (return_words.size() > howMany - 1)
            {
                return return_words;
            }
        }
    }
    return return_words;
}
bool WordTree::find(std::string word)
{
    std::shared_ptr<TreeNode> current = root;

    for (auto& letter : word)
    {
        if (current->children[letter % 'a'] == nullptr)
        {
            return false;
        }
        current = current->children[letter % 'a'];
        if (&letter == &word.back())
        {
            if (current->endOfWord)
            {
                return true;
            }
        }
    }
    return false;
}

void WordTree::add(std::string word)
{
    std::shared_ptr<TreeNode> current = root;

    for (char& letter : word)
    {
        if (current->children[letter % 'a'] == nullptr)
        {
            current->children[letter % 'a'] = std::shared_ptr<TreeNode>(new TreeNode);
        }
        current = current->children[letter % 'a'];
        if (&letter == &word.back())
        {
            if (!current->endOfWord)
            {
                current->endOfWord = true;
                m_size += 1;
            }
        }
    }
}
std::size_t WordTree::size() { return m_size; }

WordTree::WordTree()
{
    m_size = 0;
    root = std::shared_ptr<TreeNode>(new TreeNode);
}
