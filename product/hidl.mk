# HIDL
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/manifest.xml:system/vendor/manifest.xml 

# Temp disable media treble until i fix OMX decoder for inapp players
PRODUCT_PROPERTY_OVERRIDES += \
    persist.media.treble_omx=false
