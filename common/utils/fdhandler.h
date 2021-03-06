/*
// Copyright (c) 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/

#ifndef COMMON_UTILS_FDHANDLER_H_
#define COMMON_UTILS_FDHANDLER_H_

#include <map>

namespace hwcomposer {

class FDHandler {
 public:
  FDHandler();
  virtual ~FDHandler();

  // Add fd to the list of fds that we care about
  bool AddFd(int fd);
  bool RemoveFd(int fd);

  int Poll(int timeout);

  int IsReady(int fd) const;

 private:
  struct FDWatch {
    FDWatch();
    int idx;
    short revents;
  };

  std::map<int, FDWatch> fds_;
};

} // namespace hwcomposer

#endif // COMMON_UTILS_FDHANDLER_H_
