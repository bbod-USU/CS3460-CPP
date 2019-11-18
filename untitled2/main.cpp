#include <iostream>
class QuizClass
{
public:
  QuizClass(QuizClass&& rhs)
  {
    m_size = rhs.m_size;
    m_data = new int[rhs.m_size];
    for (int i = 0; i < m_size; i++)
    {
      m_data[i] = rhs.m_data[i];
    }
  }
private:
  unsigned int m_size;
  int* m_data;
};


int getUserInput() {
  std::string var;
  std::cin >> var;
  //...pretend user input happens here
  return var.size();
}

int main()
{
  auto obj = "ks";
  QuizClass(QuizClass& obj) = default;


  return 0;
}