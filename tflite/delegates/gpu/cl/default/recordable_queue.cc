/* Copyright 2021 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "tflite/delegates/gpu/cl/recordable_queue.h"

#include <memory>

namespace tflite {
namespace gpu {
namespace cl {

std::unique_ptr<RecordableQueue> CreateRecordableQueue(
    const std::vector<ClOperation*>& ops, const CLDevice& device,
    const CLContext& context) {
  return std::make_unique<RecordableQueue>(RecordableQueue());
}

}  // namespace cl
}  // namespace gpu
}  // namespace tflite
