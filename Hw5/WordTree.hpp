//
// Created by Brady Bodily on 10/20/19.
//
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <vector>

#ifndef HW5_WORDTREE_HPP
#define HW5_WORDTREE_HPP

class TreeNode
{
  public:
    bool endOfWord;
    std::array<std::shared_ptr<TreeNode>, 26> children;
    TreeNode();
};

class WordTree
{
  private:
    std::shared_ptr<TreeNode> root;
    std::size_t m_size;

  public:
    WordTree();
    std::size_t size();
    void add(std::string word);
    bool find(std::string word);
    std::vector<std::string> predict(std::string partial, std::uint8_t howMany);
    static std::shared_ptr<WordTree> readDictionary(std::string filename);
};

#endif // HW5_WORDTREE_HPP
