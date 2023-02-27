#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main()
{
    int i;

    for(i = 0; environ[i] != NULL; i++)
        puts(environ[i]);

    return 0;
}

/*
CLUTTER_IM_MODULE=xim
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/0/bus
DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
DESKTOP_SESSION=ubuntu
DISPLAY=:0
GDMSESSION=ubuntu
GIO_LAUNCHED_DESKTOP_FILE=/usr/share/applications/DigiaQt-qtcreator-community.desktop
GIO_LAUNCHED_DESKTOP_FILE_PID=2311
GJS_DEBUG_OUTPUT=stderr
GJS_DEBUG_TOPICS=JS ERROR;JS LOG
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
GNOME_SHELL_SESSION_MODE=ubuntu
GPG_AGENT_INFO=/run/user/0/gnupg/S.gpg-agent:0:1
GTK_IM_MODULE=fcitx
GTK_MODULES=gail:atk-bridge
HOME=/root
IM_CONFIG_PHASE=2
LANG=zh_CN.UTF-8
LANGUAGE=zh_CN:zh:en_US:en
LC_ADDRESS=zh_CN.UTF-8
LC_IDENTIFICATION=zh_CN.UTF-8
LC_MEASUREMENT=zh_CN.UTF-8
LC_MONETARY=zh_CN.UTF-8
LC_NAME=zh_CN.UTF-8
LC_NUMERIC=zh_CN.UTF-8
LC_PAPER=zh_CN.UTF-8
LC_TELEPHONE=zh_CN.UTF-8
LC_TIME=zh_CN.UTF-8
LD_LIBRARY_PATH=/opt/Qt5.9.0/5.9/gcc_64/lib
LOGNAME=root
MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
PATH=/opt/Qt5.9.0/5.9/gcc_64/bin:/usr/bin:/opt/Qt5.9.0/5.9/gcc_64/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
PWD=/root
QT4_IM_MODULE=fcitx
QTDIR=/opt/Qt5.9.0/5.9/gcc_64
QT_ACCESSIBILITY=1
QT_IM_MODULE=fcitx
SESSION_MANAGER=local/lishu-virtualbox:@/tmp/.ICE-unix/1688,unix/lishu-virtualbox:/tmp/.ICE-unix/1688
SHELL=/bin/bash
SHLVL=0
SSH_AGENT_PID=1814
SSH_AUTH_SOCK=/run/user/0/keyring/ssh
TEXTDOMAIN=im-config
TEXTDOMAINDIR=/usr/share/locale/
USER=root
USERNAME=root
WINDOWPATH=2
XAUTHORITY=/run/user/0/gdm/Xauthority
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
XDG_CURRENT_DESKTOP=ubuntu:GNOME
XDG_DATA_DIRS=/usr/share/ubuntu:/usr/local/share/:/usr/share/:/var/lib/snapd/desktop
XDG_MENU_PREFIX=gnome-
XDG_RUNTIME_DIR=/run/user/0
XDG_SEAT=seat0
XDG_SESSION_DESKTOP=ubuntu
XDG_SESSION_ID=2
XDG_SESSION_TYPE=x11
XDG_VTNR=2
XMODIFIERS=@im=fcitx
TERM=xterm-256color
*/


