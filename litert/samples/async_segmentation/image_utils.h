/*
 * Copyright 2025 The Google AI Edge Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef THIRD_PARTY_ODML_LITERT_LITERT_SAMPLES_ASYNC_SEGMENTATION_IMAGE_UTILS_H_
#define THIRD_PARTY_ODML_LITERT_LITERT_SAMPLES_ASYNC_SEGMENTATION_IMAGE_UTILS_H_

#include <string>

class ImageUtils {
 public:
  // Loads an image using stb_image.
  // Returns raw pixel data. Caller is responsible for freeing with
  // freeImageData(). desired_channels: 0=original, 1=grey, 2=grey_alpha, 3=RGB,
  // 4=RGBA
  static unsigned char* LoadImage(const std::string& path, int& width,
                                  int& height, int& channels_in_file,
                                  int desired_channels = 4);

  // Frees image data loaded by stbi_load.
  static void FreeImageData(unsigned char* data);

  // Saves image data using stb_image_write.
  // `channels_in_data` is the number of channels in the provided `data` buffer.
  static bool SaveImage(const std::string& path, int width, int height,
                        int channels_in_data, const void* data);
};

#endif  // THIRD_PARTY_ODML_LITERT_LITERT_SAMPLES_ASYNC_SEGMENTATION_IMAGE_UTILS_H_
