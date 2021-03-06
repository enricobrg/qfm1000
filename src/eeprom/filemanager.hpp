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

#ifndef __QFM1000_EEPROM_MANAGER_H
#define __QFM1000_EEPROM_MANAGER_H

#include <QString>

#include "eeprom.hpp"

class FileManager {

public:
    static bool loadFromFile(EEPROM *eeprom, QString filename);

    static bool saveToFile(EEPROM *eeprom, QString filename);

private:
    static QByteArray parseFile(const QByteArray &rawData);

    static bool isIntelHex(const QByteArray &rawFile);

    static QStringList splitInLines(const QByteArray &rawData);

    static QByteArray intelHexToByteArray(const QByteArray &rawData);
};

#endif
