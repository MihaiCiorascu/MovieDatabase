#pragma once
#include "Repository.h"
#include "MovieValidator.h"
#include "WatchList.h"
#include "FileWatchList.h"
#include "Command.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <initializer_list>

class Service
{
private:
    Repository *repository;
    bool adminCredentials;
    FileWatchList *watchList;
    std::vector<int> indexesOfMoviesThatTheUserLikes;
    int currentIndexForMovieToBeDisplayed;
    std::map<std::string, int> mapOfMoviesByGenre;
    std::vector<Movie> moviesFilteredByGenre;

    std::vector<std::unique_ptr<Command>> undoStack;
    std::vector<std::unique_ptr<Command>> redoStack;

public:
    Service();
    ~Service();
    Service &operator=(const Service &);
    bool compareStrings(const std::string &, const std::string &);
    void setAdminCredentials(bool);
    bool getAdminCredentials();
    void addMovie(Movie);
    void removeMovieByPosition(int);
    void updateMovie(int, Movie);
    std::vector<Movie> getMovies() const;
    int getMoviesCount() const;
    Movie getMovieByPosition(int) const;
    std::vector<Movie> getMoviesByGenre(const std::string &);
    void incrementIndexOfCurrentMovieToBeDisplayed();
    Movie getCurrentMovieToBeDisplayed();
    std::vector<Movie> getMoviesFromWatchList() const;
    void openTrailerOfMovieInBrowser(int) const;
    void openTrailerOfCurrentMovieInBrowser() const;
    void addMovieToWatchList(const Movie&);
    void addCurrentMovieToWatchList();
    void increaseLikesCountOfMovie(Movie &);
    void setTypeOfWatchList(FileWatchList *);
    void removeWatchedMovieFromWatchList(int positionOfMovie, bool likedMovie);
    void displayPlaylist();
    void setTypeOfRepository(Repository *);
    void checkIfMovieIsAlreadyInThePlaylist(const Movie &);
    void clearFile(const std::string &);
    std::map<std::string, int> getMapOfMoviesByGenre();
    void undo();
    void redo();
};