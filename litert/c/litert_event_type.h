// Copyright 2025 Google LLC.
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

#ifndef ODML_LITERT_LITERT_C_LITERT_EVENT_TYPE_H_
#define ODML_LITERT_LITERT_C_LITERT_EVENT_TYPE_H_

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

typedef enum {
  LiteRtEventTypeUnknown = 0,
  LiteRtEventTypeSyncFenceFd = 1,
  LiteRtEventTypeOpenCl = 2,
  LiteRtEventTypeEglSyncFence = 3,
  LiteRtEventTypeEglNativeSyncFence = 4,
} LiteRtEventType;

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // ODML_LITERT_LITERT_C_LITERT_EVENT_TYPE_H_
