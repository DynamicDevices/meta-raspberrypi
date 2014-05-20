DESCRIPTION = "This project enables PWM on the GPIO pins you request of a Raspberry Pi."
HOMEPAGE = "https://github.com/sarfata/pi-blaster/"
SECTION = "devel/libs"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://README.md;beginline=138;endline=151;md5=e0f0f92050a87a160939707c60940307"

SRC_URI = "git://github.com/sarfata/pi-blaster \
	   file://initscript.patch \
"


S = "${WORKDIR}/git"

COMPATIBLE_MACHINE = "raspberrypi"

inherit update-rc.d

INITSCRIPT_PACKAGES = "${PN}"
INITSCRIPT_NAME_${PN} = "pi-blaster.boot.sh"
INITSCRIPT_PARAMS_${PN} = "defaults 15 85"

do_configure() {
  sed -e "s|gcc|${CC}|g" -i Makefile
}

do_compile() {
  oe_runmake 
}

do_install() {
  install -d ${D}${sbindir}
  install -m 0755 ${S}/pi-blaster ${D}${sbindir}
  install -d ${D}${sysconfdir}
  install -d ${D}${sysconfdir}/init.d
  install -m 0755 ${S}/pi-blaster.boot.sh ${D}${sysconfdir}/init.d
}
