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

#include <stdlib.h>

#include <cinttypes>
#include <hardware/hardware.h>
#include <hardware/hwcomposer.h>

int hwc_headless_set(hwc_composer_device_1_t *dev, size_t num_displays,
                     hwc_display_contents_1_t **sf_display_contents);

int hwc_get_headless_display_configs(struct hwc_composer_device_1 *dev,
                                     int display, uint32_t *configs,
                                     size_t *num_configs);

int hwc_get_headless_display_attributes(struct hwc_composer_device_1 *dev,
                                        int display, uint32_t config,
                                        const uint32_t *attributes,
                                        int32_t *values);

int hwc_get_headless_active_config(struct hwc_composer_device_1 *dev,
                                   int display);

int hwc_set_headless_active_config(struct hwc_composer_device_1 *dev,
                                   int display, int index);

int hwc_headless_event_control(struct hwc_composer_device_1 *dev, int display,
                               int event, int enabled);

int hwc_headless_set_power_mode(struct hwc_composer_device_1 *dev, int display,
                                int mode);

int hwc_headless_prepare(hwc_composer_device_1_t */*dev*/, size_t /*num_displays*/,
			 hwc_display_contents_1_t **/*display_contents*/);

int hwc_headless_set(hwc_composer_device_1_t *dev, size_t num_displays,
		   hwc_display_contents_1_t **sf_display_contents);

void hwc_headless_dump(struct hwc_composer_device_1 * /*dev*/,
		       char * /*buff*/, int /*buff_len*/);
