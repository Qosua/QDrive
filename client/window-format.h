#ifndef QDRIVE_WINDOW_FORMAT_UTILS_H
#define QDRIVE_WINDOW_FORMAT_UTILS_H

#include <dwmapi.h>
#include <windows.h>

#include <QQuickWindow>
#include <QWindow>

namespace WindowFormat {

#ifndef DWMWA
#define DWMWA

enum WindowCornerPreference {
    defaultCorner = 0,
    notRoundedCorner = 1,
    roundedCorner = 2,
    roundedSmallCorner = 3
};
enum WindowBackDropType {
    autoType = 0,
    disableType = 1,
    micaType = 2,
    acrylicType = 3,
    micaAltType = 4
};

#define DWMWA_WINDOW_CORNER_PREFERENCE 33
#define DWMWA_CAPTION_COLOR 35
#define DWMWA_TEXT_COLOR 36
#define DWMWA_SYSTEMBACKDROP_TYPE 38

#endif

inline void setSystemTitleBarColor(const QWindow* window, const COLORREF color) {
    auto hwnd = reinterpret_cast<HWND>(window->winId());
    DwmSetWindowAttribute(hwnd, DWMWA_CAPTION_COLOR, &color, sizeof(color));
}

inline void setSystemTitleBarTextColor(const QWindow* window, const COLORREF color) {
    auto hwnd = reinterpret_cast<HWND>(window->winId());
    DwmSetWindowAttribute(hwnd, DWMWA_TEXT_COLOR, &color, sizeof(color));
}

inline void setSystemMicaEffect(const QWindow* window, const WindowBackDropType type) {
    auto hwnd = reinterpret_cast<HWND>(window->winId());
    DwmSetWindowAttribute(hwnd, DWMWA_SYSTEMBACKDROP_TYPE, &type, sizeof(type));
}

inline void setSystemRoundedCorners(const QWindow* window) {
    auto hwnd = reinterpret_cast<HWND>(window->winId());
    constexpr WindowCornerPreference pref = roundedCorner;
    DwmSetWindowAttribute(hwnd, DWMWA_WINDOW_CORNER_PREFERENCE, &pref, sizeof(pref));
}

inline void setupWindowFormat(QObject* obj, const QUrl&) {
    if (!obj)
	return;

#ifdef Q_OS_WIN
    auto* window = qobject_cast<QQuickWindow*>(obj);
    if (window) {
	// WindowFormat::applyRoundedCorners(window);
	// setSystemMicaEffect(window, WindowFormat::acrylicType);
	// WindowFormat::setSystemTitleBarColor(window, RGB(30, 30, 30));
    }
#endif
}

}  // namespace WindowFormat

#endif  // QDRIVE_WINDOW_FORMAT_UTILS_H
