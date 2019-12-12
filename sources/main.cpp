//
// Created by Admin on 10.12.2019.
//

#include <boost/log/utility/setup.hpp>
#include <iostream>
#include <random>
#include "hash.hpp"

void threadWork(Hash &hasher) { hasher.work(); }

void prepare() {
  boost::log::register_simple_formatter_factory<
      boost::log::trivial::severity_level, char>("Severity");
  static const std::string format =
      "[%TimeStamp%][%Severity%][%ThreadID%]: %Message%";

  auto all = boost::log::add_file_log(
      boost::log::keywords::file_name = "All/log_%N.log",
      boost::log::keywords::rotation_size = 128 * 1024 * 1024,
      boost::log::keywords::format = format);
  all->set_filter(boost::log::trivial::severity >= boost::log::trivial::trace);

  auto correct = boost::log::add_file_log(
      boost::log::keywords::file_name = "Correct/log_%N.log",
      boost::log::keywords::rotation_size = 128 * 1024 * 1024,
      boost::log::keywords::format = format);
  correct->set_filter(boost::log::trivial::severity >=
                      boost::log::trivial::info);

  auto console = boost::log::add_console_log(
      std::cout, boost::log::keywords::format = format);
  console->set_filter(boost::log::trivial::severity >=
                      boost::log::trivial::info);

  boost::log::add_common_attributes();
}

int main(int argc, char *argv[]) {
  prepare();
  srand(time(nullptr));
  unsigned int threadNumder;
  if (argc == 1) {
    threadNumder = std::thread::hardware_concurrency();
  } else if (argc == 2) {
    threadNumder = std::atoi(argv[1]);
  } else {
    std::cout << "Incorrect parameters!\n";
    return 0;
  }
  std::vector<std::thread> threadVector;
  Hash hasher;
  for (unsigned int i = 0; i < threadNumder; ++i) {
    threadVector.emplace_back(threadWork, std::ref(hasher));
  }
  for (auto &thread : threadVector) {
    thread.join();
  }
}
