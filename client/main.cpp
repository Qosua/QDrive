#include <QApplication>
#include <QPushButton>

#include <spdlog/spdlog.h>

#include <spdlog/spdlog.h>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QPushButton button("Hello client!", nullptr);
    button.resize(200, 100);
    button.show();

    std::string str = ""
        "asdasd"
        "asd";

    switch (0) {
        case 0: {
        }
        break;
    }

    spdlog::info("Client started");
    spdlog::warn("Something looks suspicious");
    spdlog::error("Critical error: {}", 42);

    for (int i = 1; i <= 10; i++) {
        int sum = i;
    }

    return QApplication::exec();
}