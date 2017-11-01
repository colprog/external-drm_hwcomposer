/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "headlesscompositor.h"

int hwc_headless_set(hwc_composer_device_1_t *dev, size_t num_displays,
                     hwc_display_contents_1_t **sf_display_contents) {
  for (size_t i = 0; i < num_displays; ++i) {
    if (!sf_display_contents[i])
      continue;

    hwc_display_contents_1_t *dc = sf_display_contents[i];
    dc->outbufAcquireFenceFd = -1;
    if (dc->retireFenceFd >= 0) {
      close(dc->retireFenceFd);
      dc->retireFenceFd = -1;
    }
  }

  return 0;
}

int hwc_get_headless_display_configs(struct hwc_composer_device_1 * /*dev*/,
                                     int /*display*/, uint32_t *configs,
                                     size_t *num_configs) {
  *num_configs = 1;
  if (configs)
    configs[0] = 0;

  return 0;
}

int hwc_get_headless_display_attributes(struct hwc_composer_device_1 * /*dev*/,
                                        int /*display*/, uint32_t /*config*/,
                                        const uint32_t *attributes,
                                        int32_t *values) {
  for (int i = 0; attributes[i] != HWC_DISPLAY_NO_ATTRIBUTE; ++i) {
    switch (attributes[i]) {
      case HWC_DISPLAY_VSYNC_PERIOD:
        values[i] = 60;
        break;
      case HWC_DISPLAY_WIDTH:
        values[i] = 1;
        break;
      case HWC_DISPLAY_HEIGHT:
        values[i] = 1;
        break;
      case HWC_DISPLAY_DPI_X:
        /* Dots per 1000 inches */
        values[i] = 1;
        break;
      case HWC_DISPLAY_DPI_Y:
        /* Dots per 1000 inches */
        values[i] = 1;
        break;
    }
  }
  return 0;
}

int hwc_get_headless_active_config(struct hwc_composer_device_1 * /*dev*/,
                                   int /*display*/) {
  return -1;
}

int hwc_set_headless_active_config(struct hwc_composer_device_1 * /*dev*/,
                                   int /*display*/, int /*index*/) {
  return -1;
}

int hwc_headless_event_control(struct hwc_composer_device_1 * /*dev*/,
                               int /*display*/, int /*event*/,
                               int /*enabled*/) {
  return 0;
}

int hwc_headless_set_power_mode(struct hwc_composer_device_1 * /*dev*/,
                                int /*display*/, int /*mode*/) {
  return 0;
}

int hwc_headless_prepare(hwc_composer_device_1_t * /*dev*/,
				size_t num_displays,
				hwc_display_contents_1_t **display_contents) {
  for (int i = 0; i < (int)num_displays; ++i) {
    if (!display_contents[i])
      continue;

    // Mark everything for overlay, so SF doesnt have to do any
    // extra work.
    int num_layers = display_contents[i]->numHwLayers;

    for (int j = 0; j < num_layers; ++j) {
      hwc_layer_1_t *layer = &display_contents[i]->hwLayers[j];
      layer->compositionType = HWC_OVERLAY;
    }
  }

  return 0;
}

void hwc_headless_dump(struct hwc_composer_device_1 * /*dev*/,
		       char * /*buff*/, int /*buff_len*/) {
}
