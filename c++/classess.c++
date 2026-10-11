#include <iostream>

enum class EvilWorkerKind { Witch, WereWolf, Elves, Wizard };

class EvilWorkers {
private:
  EvilWorkerKind kind{};
  std::string name{};
  int age{};

public:
  EvilWorkers(const int _age, const EvilWorkerKind _kind,
              const std::string _name) {
    kind = _kind;
    name = _name;
    age = _age;
  }
};

int main() {}
