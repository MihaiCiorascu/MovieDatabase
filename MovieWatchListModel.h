//
// Created by Mihai on 6/1/2024.
//

#ifndef OOP_A10_MIHAICIORASCU_MOVIEWATCHLISTMODEL_H
#define OOP_A10_MIHAICIORASCU_MOVIEWATCHLISTMODEL_H

#include <QAbstractTableModel>
#include <vector>

#include "Movie.h"
#include "Service.h"

class MovieWatchListModel : public QAbstractTableModel {
Q_OBJECT

private:
    std::vector<Movie> movies;

public:
    MovieWatchListModel(Service& service, QObject* parent = nullptr)
            : QAbstractTableModel(parent), movies(service.getMovies()) {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return movies.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 5;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if (!index.isValid() || role != Qt::DisplayRole)
            return QVariant();

        const Movie& movie = movies[index.row()];
        switch (index.column()) {
            case 0: return QString::fromStdString(movie.getTitle());
            case 1: return QString::fromStdString(movie.getGenre());
            case 2: return movie.getYearOfRelease();
            case 3: return movie.getLikesCount();
            case 4: return QString::fromStdString(movie.getTrailer());
            default: return QVariant();
        }
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
            return QVariant();

        switch (section) {
            case 0: return QString("Title");
            case 1: return QString("Genre");
            case 2: return QString("Year of Release");
            case 3: return QString("Likes Count");
            case 4: return QString("Trailer");
            default: return QVariant();
        }
    }
};

#endif //OOP_A10_MIHAICIORASCU_MOVIEWATCHLISTMODEL_H
