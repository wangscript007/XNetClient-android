#ifndef __UTIL_LOG_H__
#define __UTIL_LOG_H__

#ifndef LOG_TAG

#define LOG_TAG "AudioOpusTest"


#include<android/log.h>

#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__) // ����LOGD����
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,  LOG_TAG, __VA_ARGS__) // ����LOGI����
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,  LOG_TAG, __VA_ARGS__) // ����LOGW����
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__) // ����LOGE����
#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL, LOG_TAG, __VA_ARGS__) // ����LOGF����

#endif


#endif // __UTIL_LOG_H__