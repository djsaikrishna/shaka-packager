// Copyright 2017 Google Inc. All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#include "packager/media/base/text_sample.h"

#include "packager/base/logging.h"

namespace shaka {
namespace media {

bool TextFragment::is_empty() const {
  return body.empty();
}

TextSample::TextSample(const std::string& id,
                       int64_t start_time,
                       int64_t end_time,
                       const TextSettings& settings,
                       const TextFragment& body)
    : id_(id),
      start_time_(start_time),
      duration_(end_time - start_time),
      settings_(settings),
      body_(body) {}

int64_t TextSample::EndTime() const {
  return start_time_ + duration_;
}

}  // namespace media
}  // namespace shaka
