/*
 * LCD Image Converter. Converts images and fonts for embedded applications.
 * Copyright (C) 2013 riuson
 * mailto: riuson@gmail.com
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/
 */

#ifndef RESIZEMODEL_H
#define RESIZEMODEL_H
//-----------------------------------------------------------------------------
#include <QAbstractItemModel>
#include <QVariant>
//-----------------------------------------------------------------------------
class DataContainer;
//-----------------------------------------------------------------------------
class ResizeModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    enum
    {
        CropResultRole = Qt::UserRole + 1
    };

    explicit ResizeModel(DataContainer *container, QObject *parent = 0);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role) const;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;

    void callReset();

    void setCrop(int left, int top, int right, int bottom);
    void setScale(int scale);
private:
    DataContainer *mContainer;
    int mLeft;
    int mRight;
    int mTop;
    int mBottom;
    int mScale;

    QImage modifyImage(const QImage *source, bool preview) const;

signals:

public slots:

};
//-----------------------------------------------------------------------------
#endif // RESIZEMODEL_H