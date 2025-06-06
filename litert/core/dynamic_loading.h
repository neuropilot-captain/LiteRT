// Copyright 2024 Google LLC.
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

#ifndef ODML_LITERT_LITERT_CORE_DYNAMIC_LOADING_H_
#define ODML_LITERT_LITERT_CORE_DYNAMIC_LOADING_H_

#include <string>
#include <vector>

#include "absl/strings/string_view.h"  // from @com_google_absl
#include "litert/c/litert_common.h"

namespace litert::internal {

constexpr absl::string_view kLiteRtSharedLibPrefix = "libLiteRt";

// Find all litert shared libraries in "search_path" and return
// kLiteRtStatusErrorInvalidArgument if the provided search_path doesn't
// exist. All internal dynamically linked dependencies for litert should be
// prefixed with "libLiteRtCompilerPlugin".
LiteRtStatus FindLiteRtCompilerPluginSharedLibs(
    absl::string_view search_path, std::vector<std::string>& results);

// Find all litert shared libraries in "search_path" and return
// kLiteRtStatusErrorInvalidArgument if the provided search_path doesn't
// exist. All internal dynamically linked dependencies for litert should be
// prefixed with "libLiteRtDispatch".
LiteRtStatus FindLiteRtDispatchSharedLibs(absl::string_view search_path,
                                          std::vector<std::string>& results);

// Find shared libraries for a given pattern in "search_path" and return
// kLiteRtStatusErrorInvalidArgument if the provided search_path doesn't
// exist.
LiteRtStatus FindLiteRtSharedLibsHelper(const std::string& search_path,
                                        const std::string& lib_pattern,
                                        bool full_match,
                                        std::vector<std::string>& results);

// Analogous to the above, but the first match identified, its immediate parent
// directory will be appended to the LD_LIBRARY_PATH.
LiteRtStatus PutLibOnLdPath(absl::string_view search_path,
                            absl::string_view lib_pattern);

}  // namespace litert::internal

#endif  // ODML_LITERT_LITERT_CORE_DYNAMIC_LOADING_H_
