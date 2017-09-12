/*
 * qFM1000
 * Copyright (C) 2017  Luca Cireddu
 * sardylan@gmail.com
 * http://www.lucacireddu.it
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <QtCore/QSettings>
#include <QSerialPort>

#include "manager.hpp"
#include "config.hpp"
#include "default.hpp"

Q_DECLARE_METATYPE(QSerialPort::BaudRate);

void ConfigManager::load() {
    Config *config = Config::getInstance();
    QSettings settings;

    settings.beginGroup("serial");
    config->setPortName(settings.value("portName", CONFIG_PORTNAME_DEFAULT).toString());
    config->setPortSpeed(settings.value("portSpeed", CONFIG_PORTSPEED_DEFAULT).value<QSerialPort::BaudRate>());
    settings.endGroup();
}

void ConfigManager::save() {
    Config *config = Config::getInstance();
    QSettings settings;

    settings.beginGroup("serial");
    settings.setValue("portName", config->getPortName());
    settings.setValue("portSpeed", config->getPortSpeed());
    settings.endGroup();

    settings.sync();
}
