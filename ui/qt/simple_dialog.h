/* simple_dialog.h
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef SIMPLE_DIALOG_H
#define SIMPLE_DIALOG_H

#include <config.h>

#include <stdio.h>

#include <glib.h>

#include "ui/simple_dialog.h"

#include <QPair>
#include <QString>

typedef QPair<QString,QString> MessagePair;

class QCheckBox;
class QMessageBox;
class QWidget;

// This might be constructed before Qt is initialized and must be a plain, non-Qt object.
class SimpleDialog
{
public:
    explicit SimpleDialog(QWidget *parent, ESD_TYPE_E type, int btn_mask, const char *msg_format, va_list ap);
    ~SimpleDialog();

    static void displayQueuedMessages(QWidget *parent = 0);
    void setDetailedText(QString text) { detailed_text_ = text; }
    void setCheckBox(QCheckBox *cb) { check_box_ = cb; }
    int exec();

private:
    const MessagePair splitMessage(QString &message) const;
    QString detailed_text_;
    QCheckBox *check_box_;
    QMessageBox *message_box_;
};

#endif // SIMPLE_DIALOG_H

/*
 * Editor modelines
 *
 * Local Variables:
 * c-basic-offset: 4
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * ex: set shiftwidth=4 tabstop=8 expandtab:
 * :indentSize=4:tabSize=8:noTabs=true:
 */
