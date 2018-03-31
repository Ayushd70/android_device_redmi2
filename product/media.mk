# Media
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/media_profiles_V1_0.xml:$(TARGET_COPY_OUT_VENDOR)/etc/media_profiles_V1_0.xml \
    $(LOCAL_PATH)/configs/media_codecs_performance.xml:$(TARGET_COPY_OUT_VENDOR)/etc/media_codecs_performance.xml \
    $(LOCAL_PATH)/configs/mixer_paths_qrd_skui.xml:system/vendor/etc/mixer_paths_qrd_skui.xml

PRODUCT_PROPERTY_OVERRIDES += \
    persist.media.treble_omx=false
