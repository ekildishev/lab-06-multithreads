// Copyright 2018 Your Name <your_email>

#include <hash.hpp>
#include <iostream>

void Hash::work() {
  for (unsigned int i = 0; i < 200000; ++i) {
    std::string attemptString(std::to_string(rand()) + std::to_string(rand()) +
                              std::to_string(rand()) +
                              std::to_string(rand()));  // вектор
    std::string hash = picosha2::hash256_hex_string(attemptString);

    BOOST_LOG_TRIVIAL(trace)
        << "Attempt: " << attemptString << " hash: " << hash << std::endl;
    if (hash.substr(hash.size() - 4, hash.size()) == correctString) {
      BOOST_LOG_TRIVIAL(info)
          << "Correct: " << attemptString << " hash: " << hash << std::endl;
    }
  }
}
