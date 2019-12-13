// Copyright 2018 Your Name <your_email>

#pragma once

#include <thread>
#include <boost/log/trivial.hpp>
#include <PicoSHA2/picosha2.h>
#include <string>

struct Hash{
  const std::string correctString = "0000";
  void work();
};
