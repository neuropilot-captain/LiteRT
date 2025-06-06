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

#ifndef ODML_LITERT_LITERT_RUNTIME_TFL_UTILS_H_
#define ODML_LITERT_LITERT_RUNTIME_TFL_UTILS_H_

#include "litert/c/litert_layout.h"
#include "litert/cc/litert_expected.h"
#include "litert/cc/litert_layout.h"
#include "litert/cc/litert_model.h"

struct TfLiteOpaqueTensor;

namespace litert::internal {

Expected<ElementType> ConvertElementType(TfLiteType tfl_type);

Expected<Layout> ConvertTensorLayout(
    const TfLiteOpaqueTensor* tfl_opaque_tensor);

Expected<RankedTensorType> ConvertTensorType(
    const TfLiteOpaqueTensor* tfl_opaque_tensor);

// Resize a given `tfl_opaque_tensor` based on a given `layout`.
Expected<void> ResizeTensor(const LiteRtLayout& layout,
                            TfLiteOpaqueContext* tfl_context,
                            TfLiteOpaqueTensor* tfl_opaque_tensor);

}  // namespace litert::internal

#endif  // ODML_LITERT_LITERT_RUNTIME_TFL_UTILS_H_
