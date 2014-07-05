FILESEXTRAPATHS_prepend := "${THISDIR}/weston:"

SRC_URI += "file://disable-tests.patch  \
            file://fixup-egl-gles-versions.patch \
           "

# kms -> drm. drm requires libglapi which mesa provides and we don' have mesa
PACKAGECONFIG ??= "${@bb.utils.contains('DISTRO_FEATURES', 'wayland', 'fbdev wayland egl', '', d)} \
                   ${@bb.utils.contains('DISTRO_FEATURES', 'x11', 'x11', '', d)} \
                   ${@bb.utils.contains('DISTRO_FEATURES', 'pam', 'launch', '', d)} \
                  "

#PACKAGECONFIG += "rpi ${@bb.utils.contains('DISTRO_FEATURES', 'maynard', 'launch', 'pam', d)} \
#
#PACKAGECONFIG[rpi] = "--enable-rpi-compositor, --disable-rpi-compositor	,udev virtual/mesa \
#                      virtual/libgles2 virtual/libgl virtual/egl "
#
