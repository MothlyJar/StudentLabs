#pragma once
#include <QString>
#include "ext/json/json.hpp"
#include "fstream"
#include <QDebug>
#include <QTreeWidgetItem>
using js= nlohmann::json;

struct data_s {
js _data;
QTreeWidgetItem* _item;
bool normal[6] = {true, true, true, true, true, true};
bool all_normal = true;

data_s(const std::string& name, const std::string& desc, const std::string& legs, const std::string& hands, const std::string& drawers, const std::string& cost, QTreeWidgetItem* item) {
    _data = {
        {"name", name},
        {"desc", desc},
        {"legs", legs},
        {"hands", hands},
        {"drawers", drawers},
        {"cost", cost}
    };
    _item = item;
}
//~data_s() {delete _item;}

void q_total_info() {
    qInfo() << QString("%1 %2 %3 %4 %5 %6").arg(_data["name"].get<std::string>()).arg(_data["desc"].get<std::string>()).arg(_data["legs"].get<std::string>()).arg(_data["hands"].get<std::string>()).arg(_data["drawers"].get<std::string>()).arg(_data["cost"].get<std::string>());
}
void data_export(const std::string& in_path_to_file, const std::string& out_path_to_file, js& all_data) {
    if (in_path_to_file.empty() || out_path_to_file.empty()) {
        qInfo() << "[data_export] no link";
    }

    std::ifstream filei(in_path_to_file, std::ios::app);
    if (!filei.is_open()) {
        qInfo() << "[data_export] file isn't open";
    }
    else {
        all_data = js::parse(filei);

        std::ofstream fileo(out_path_to_file);
        fileo.clear();

        all_data.emplace_back(_data);
        fileo << all_data.dump(4);
    }
}
};
